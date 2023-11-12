#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/event.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    int server_fd, client_fds[MAX_CLIENTS], num_clients = 0;

    if (argc != 2)
    {
        perror("Usage: ./server <PORT>");
        exit(1);
    }

    // 소켓 생성
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        exit(1);
    }

    // 서버 주소 설정
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    // 소켓과 주소를 바인딩
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // 연결 요청 대기
    if (listen(server_fd, 5) == -1) {
        perror("listen");
        exit(1);
    }

    // kqueue 생성
    int kq = kqueue();
    if (kq == -1) {
        perror("kqueue");
        exit(1);
    }

    // 서버 소켓의 이벤트 등록
    struct kevent server_ev;
    EV_SET(&server_ev, server_fd, EVFILT_READ, EV_ADD, 0, 0, NULL);
    if (kevent(kq, &server_ev, 1, NULL, 0, NULL) == -1) {
        perror("kevent");
        exit(1);
    }

    while (1) {
        struct kevent events[MAX_CLIENTS + 1];
        int nevents;

        // 이벤트 대기
        nevents = kevent(kq, NULL, 0, events, MAX_CLIENTS + 1, NULL);
        if (nevents == -1) {
            perror("kevent");
            exit(1);
        }

        for (int i = 0; i < nevents; i++) {
            int fd = events[i].ident;
            if (fd == server_fd) {
                // 클라이언트 연결 수락
                int client_fd = accept(server_fd, NULL, NULL);
                if (client_fd == -1) {
                    perror("accept");
                    exit(1);
                }

                // 클라이언트 소켓의 이벤트 등록
                struct kevent client_ev;
                EV_SET(&client_ev, client_fd, EVFILT_READ, EV_ADD, 0, 0, NULL);
                if (kevent(kq, &client_ev, 1, NULL, 0, NULL) == -1) {
                    perror("kevent");
                    exit(1);
                }

                // 클라이언트 소켓을 배열에 저장
                if (num_clients < MAX_CLIENTS) {
                    client_fds[num_clients++] = client_fd;
                    printf("New client connected: %d\n", client_fd);
                } else {
                    printf("Max number of clients reached. Rejecting connection.\n");
                    close(client_fd);
                }
            } else {
                // 클라이언트 소켓의 데이터 읽기
                char buffer[BUFFER_SIZE];
                ssize_t n = read(fd, buffer, BUFFER_SIZE);
                if (n == -1) {
                    perror("read");
                    exit(1);
                } else if (n == 0) {
                    // 클라이언트 연결 종료
                    printf("Client disconnected: %d\n", fd);
                    close(fd);
                    // 클라이언트 소켓을 배열에서 제거
                    for (int j = 0; j < num_clients; j++) {
                        if (client_fds[j] == fd) {
                            client_fds[j] = client_fds[num_clients - 1];
                            num_clients--;
                            break;
                        }
                    }
                } else {
                    // 받은 데이터를 모든 클라이언트에게 전송
                    for (int j = 0; j < num_clients; j++) {
                        int client = client_fds[j];
                        if (client != fd) {
                            if (write(client, buffer, n) == -1) {
                                perror("write");
                                exit(1);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
