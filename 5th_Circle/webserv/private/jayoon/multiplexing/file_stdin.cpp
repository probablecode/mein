#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <fcntl.h>

int main() {
    int maxfd, fd;
    fd_set readfds;
    char buffer[256];

    // 파일 디스크립터 설정
    int stdin_fd = fileno(stdin); // stdin의 파일 디스크립터
    int file_fd = open("example.txt", O_RDONLY); // 읽기 전용 파일 열기
    if (file_fd == -1) {
        perror("open");
        exit(1);
    }

    // 최대 파일 디스크립터 값 계산
    maxfd = (stdin_fd > file_fd) ? stdin_fd : file_fd;

    while (1) {
        // 파일 디스크립터 설정
        FD_ZERO(&readfds);
        FD_SET(stdin_fd, &readfds);
        FD_SET(file_fd, &readfds);

        // 멀티플렉싱
        int ready_fds = select(maxfd + 1, &readfds, NULL, NULL, NULL);
        if (ready_fds == -1) {
            perror("select");
            exit(1);
        }

        // stdin에서 입력을 읽음
        if (FD_ISSET(stdin_fd, &readfds)) {
            fgets(buffer, sizeof(buffer), stdin);
            printf("Input: %s", buffer);
        }

        // 파일에서 데이터를 읽음
        if (FD_ISSET(file_fd, &readfds)) {
            ssize_t n = read(file_fd, buffer, sizeof(buffer));
            if (n == -1) {
                perror("read");
                exit(1);
            } else if (n == 0) {
                printf("End of file reached.\n");
                break;
            } else {
                printf("File data: %.*s", (int)n, buffer);
            }
        }
    }

    // 파일 디스크립터 닫기
    close(file_fd);

    return 0;
}
