#include <stdio.h>
#include <stdlib.h>
#include <sys/event.h>
#include <unistd.h>

int main() {
    // kqueue 생성
    int kq = kqueue();
    if (kq == -1) {
        perror("kqueue");
        exit(1);
    }

    // stdin의 이벤트를 감시할 kevent 구조체 설정
    struct kevent stdin_ev;
    EV_SET(&stdin_ev, fileno(stdin), EVFILT_READ, EV_ADD, 0, 0, NULL);

    // kqueue에 이벤트 등록
    if (kevent(kq, &stdin_ev, 1, NULL, 0, NULL) == -1) {
        perror("kevent");
        exit(1);
    }

    while (1) {
        struct kevent events[1];
        int nevents;

        // 이벤트 대기
        nevents = kevent(kq, NULL, 0, events, 1, NULL);
        if (nevents == -1) {
            perror("kevent");
            exit(1);
        }

        for (int i = 0; i < nevents; i++) {
            if (events[i].ident == fileno(stdin)) {
                // stdin에서 데이터를 읽어옴
                char buf[1024];
                ssize_t n = read(fileno(stdin), buf, sizeof(buf));
                if (n == -1) {
                    perror("read");
                    exit(1);
                } else if (n == 0) {
                    // EOF (입력 종료)
                    printf("Input finished.\n");
                    exit(0);
                } else {
                    // 입력 내용 출력
                    printf("Input: %.*s", (int)n, buf);
                }
            }
        }
    }

    return 0;
}
