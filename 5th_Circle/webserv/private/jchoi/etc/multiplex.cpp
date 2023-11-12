/* kevent는 ident와 filter를 식별자로 삼는다. 이를 통해 kevent의 중복 등록을 막고, 해당 이벤트 발생 조건이 부합하지 않을 경우(파일 디스크립터가 close 될 경우 등)에는 kqueue에서 삭제되어 최소한의 kevent만 남아있을 수 있도록 관리된다.

EV_SET 매크로함수를 사용하면 kevent 구조체를 초기화할 때 편리하다.
EV_SET(&kev, ident, filter, flags, fflags, data, udata); // kevent 구조체의 주소를 전달
 
다시 kevent()로 돌아와서, 인자 eventlist는 발생한 event가 return될 배열이고, nevents는 배열의 크기이다. kevent()는 이 배열에 발생한 kevent를 최대 nevents 만큼 정리하여 담아주고, 그 개수를 return한다. changelist와 eventlist는 같은 배열을 사용할 수 있는데, 관리의 용이성을 위해 따로 둘 수 있다.

timeout은 timespec 구조체의 포인터를 전달하고, NULL을 전달할 경우 이벤트 발생까지 block된다. (무한정 대기)

kqueue()로 kqueue를 할당하고, 이벤트의 변화(등록, 삭제 등)를 kevent()에 전달, kevent()가 return한 처리 가능 event들을 받아 그에 맞게 처리하면 된다.
 
다음은 kqueue를 이용한 multiplexing echo server 예제 코드이다. C++로 작성되었다.*/
#include <sys/types.h>
#include <sys/event.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#include <iostream>
#include <map>
#include <vector>

using namespace std;

void exit_with_perror(const string& msg)
{
    cerr << msg << endl;
    exit(EXIT_FAILURE);
}

void change_events(vector<struct kevent>& change_list, uintptr_t ident, int16_t filter,
        uint16_t flags, uint32_t fflags, intptr_t data, void *udata)
{
    struct kevent temp_event;

    EV_SET(&temp_event, ident, filter, flags, fflags, data, udata);
    change_list.push_back(temp_event);
}

void disconnect_client(int client_fd, map<int, string>& clients)
{
    cout << "client disconnected: " << client_fd << endl;
    close(client_fd);
    clients.erase(client_fd);
}

int main()
{
    /* init server socket and listen */
    int server_socket;
    struct sockaddr_in server_addr;

    if ((server_socket = socket(PF_INET, SOCK_STREAM, IP)) == -1)
        exit_with_perror("socket() error\n" + string(strerror(errno)));

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        exit_with_perror("bind() error\n" + string(strerror(errno)));

    if (listen(server_socket, 5) == -1)
        exit_with_perror("listen() error\n" + string(strerror(errno)));
    fcntl(server_socket, F_SETFL, O_NONBLOCK);
    /* init kqueue */
    int kq;
    if ((kq = kqueue()) == -1)
        exit_with_perror("kqueue() error\n" + string(strerror(errno)));

    map<int, string> clients; // map for client socket:data
    vector<struct kevent> change_list; // kevent vector for changelist
    struct kevent event_list[8]; // kevent array for eventlist
    /* add event for server socket */
    change_events(change_list, server_socket, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
    cout << "echo server started" << endl;
    /* main loop */
    int new_events;
    struct kevent* curr_event;
    while (1)
    {
        /*  apply changes and return new events(pending events) */
        new_events = kevent(kq, &change_list[0], change_list.size(), event_list, 8, NULL);
        if (new_events == -1)
            exit_with_perror("kevent() error\n" + string(strerror(errno)));

        change_list.clear(); // clear change_list for new changes

        for (int i = 0; i < new_events; ++i)
        {
            curr_event = &event_list[i];

            /* check error event return */
            if (curr_event->flags & EV_ERROR)
            {
                if (curr_event->ident == server_socket)
                    exit_with_perror("server socket error");
                else
                {
                    cerr << "client socket error" << endl;
                    disconnect_client(curr_event->ident, clients);
                }
            }
            else if (curr_event->filter == EVFILT_READ)
            {
                if (curr_event->ident == server_socket)
                {
                    /* accept new client */
                    int client_socket;
                    if ((client_socket = accept(server_socket, NULL, NULL)) == -1)
                        exit_with_perror("accept() error\n" + string(strerror(errno)));
                    cout << "accept new client: " << client_socket << endl;
                    fcntl(client_socket, F_SETFL, O_NONBLOCK);

                    /* add event for client socket - add read && write event */
                    change_events(change_list, client_socket, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, NULL);
                    change_events(change_list, client_socket, EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0, NULL);
                    clients[client_socket] = "";
                }
                else if (clients.find(curr_event->ident)!= clients.end())
                {
                    /* read data from client */
                    char buf[1024];
                    int n = read(curr_event->ident, buf, sizeof(buf));

                    if (n <= 0)
                    {
                        if (n < 0)
                            cerr << "client read error!" << endl;
                        disconnect_client(curr_event->ident, clients);
                    }
                    else
                    {
                        buf[n] = '\0';
                        clients[curr_event->ident] += buf;
                        cout << "received data from " << curr_event->ident << ": " << clients[curr_event->ident] << endl;
                    }
                }
            }
            else if (curr_event->filter == EVFILT_WRITE)
            {
                /* send data to client */
                map<int, string>::iterator it = clients.find(curr_event->ident);
                if (it != clients.end())
                {
                    if (clients[curr_event->ident] != "")
                    {
                        int n;
                        if ((n = write(curr_event->ident, clients[curr_event->ident].c_str(),
                                        clients[curr_event->ident].size()) == -1))
                        {
                            cerr << "client write error!" << endl;
                            disconnect_client(curr_event->ident, clients);  
                        }
                        else
                            clients[curr_event->ident].clear();
                    }
                }
            }
        }

    }
    return (0);
}
/*
vector를 통해 새로 등록할 이벤트를 관리하여, kevent의 changelist를 vector의 첫 번째 요소의 포인터로 전달했다. return되는 event는 길이 8의 고정 배열인 event_list로 받았다. (만약 반환할 수 있는 이벤트가 전달한 배열의 길이인 nevents보다 많다면, nevents 만큼만 배열에 담고 나머지는 다음 kevent 호출 때 반환한다.)

server 소켓은 READ event만 등록, client 소켓은 READ와 WRITE를 모두 등록했다. client 연결 해제 시에는 DELETE 이벤트를 등록하지 않고 close()만 하도록 했다. close()시 닫힌 fd를 참조하는 모든 이벤트는 비활성화되고 삭제되기 때문이다.

 

 

kqueue는 select나 poll에 비해 이벤트 처리에서 효율적인데, 그 이유는 다음과 같다.

이벤트 발생 시, 해당 이벤트에 접근하는 시간복잡도가 O(1)이다.
select와 poll의 경우 이벤트 발생 시 해당 이벤트에 접근하는 시간복잡도가 O(N)이나, kqueue는 발생한 이벤트를 정리하여 return해주기 때문에 O(1)로 접근 가능하다.
등록된 이벤트를 따로 관리할 필요가 없다.
select는 fd_set, poll은 poll_fd 구조체의 배열로 모니터링할 이벤트들을 사용자가 관리하고, 이를 select()나 poll()에 전달해야 하지만, kqueue의 경우 새로 등록할 이벤트, 발생한 이벤트만 관리해주면 된다. 모니터링되는 이벤트는 kqueue, 즉 커널에서 관리된다.
 

kqueue는 fd에 대한 I/O 처리가 사용 용도의 대부분을 차지하지만, 프로세스, 시그널 등 다양한 리소스를 관리할 수 있다. 자세한 정보는 man page를 참고하도록 하자.

BSD kqueue man page 번역: https://hyeonski.tistory.com/10
*/
