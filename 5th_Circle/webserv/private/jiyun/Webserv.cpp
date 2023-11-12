#include <sys/event.h>
#include <sys/fcntl.h>
#include <netinet/in.h>

#include "Webserv.hpp"
#include "Client.hpp"
#include "Server.hpp"

// public **********************************************************************

//  constructors & destructor --------------------------------------------------

//  Default constructor

Webserv::Webserv(Config& config) {
  InitWebserv(config);
//  Run();
}

//  destructor constructor
Webserv::~Webserv() {
  // TODO
}

// local function

uint32_t ipToUint32(const std::string& ip) {
  uint32_t result = 0;

  std::stringstream ss(ip);
  std::string octet;
  while (getline(ss, octet, '.')) {
	int value = atoi(octet.c_str());

	result = (result << 8) | value;
  }

  return result;
}

int portToInt(const std::string& port) {
  std::stringstream ss(port);
  int result;
  ss >> result;
  return result;
}

Server createServer(std::string& listen) {
  size_t colon_pos = listen.find(':');
  std::string ip = listen.substr(0, colon_pos);
  std::string port = listen.substr(colon_pos + 1);

  return Server(ipToUint32(ip), portToInt(port));
}

void addUniqListenServers(Config &config, std::map<std::string, Server>& uniq_listen_server) {
  for(int i = 0; i < config.GetServerConfigsNum(); i++) {
	std::string listen = config.GetServerConfig(i).GetListen();

	std::map<std::string, Server>::iterator iter = uniq_listen_server.begin();
	if (iter == uniq_listen_server.end())
	  uniq_listen_server.insert(std::make_pair(listen, createServer(listen)));
	for(;iter != uniq_listen_server.end(); iter++)
	  if (iter->first != listen)
		uniq_listen_server.insert(std::make_pair(listen, createServer(listen)));
  }
}

// public function

void Webserv::InitWebserv(Config &config) {
  std::map<std::string, Server> uniq_listen_server;

  addUniqListenServers(config, uniq_listen_server);
  FillServerField(config, uniq_listen_server);
}

void Webserv::FillServerField(Config &config, std::map<std::string, Server>& uniq_listen_server) {
  std::map<std::string, Server>::iterator iter = uniq_listen_server.begin();
  for(;iter != uniq_listen_server.end(); iter++) {
	Server cur_server = iter->second;

	for(int i = 0; i < config.GetServerConfigsNum(); i++) {
	  ServerConfig cur_server_config = config.GetServerConfig(i);
	  std::string listen = cur_server_config.GetListen();
	  if (listen == iter->first)
		cur_server.AddServerBlock(cur_server_config);
	}
	servers_.push_back(cur_server);
  }
}

//void Webserv::Run() {
//  int kq = kqueue();
//  int cnt_event = 0;
//  const int nevents = 8; // tmp
//  struct kevent event_list[nevents]; // tmp
//  struct kevent current_event;
//
//
//  Server new_server(INADDR_ANY, 8080);
//  servers_.push_back(new_server);
//
//  // 1. 첫번째 /////////////////////////////////////////////////////////////////////////
//  // Server 안에서 new_server를 추가하고, 함수가 끝날때 스택 메모리들은 해제가 된다.
//  // 소멸자에서는 close를 소거했다. 즉, 일괄적으로, 의식적으로 close처리를 해줘야한다는 뜻
// ////////////////////////////////////////////////////////////////////////////////////////////
//
//  for (std::vector<Server>::iterator iter = servers_.begin(); iter != servers_.end(); iter++)
//  {
//    AddChangeList(iter->GetListenSocket().GetSocketFD(), EVFILT_READ, EV_ADD, 0, 0, &(*iter));
//   std::cout << "AddChangeList" << std::endl;
//  }
//
//  while (1) {
//    cnt_event = kevent(kq, &change_list_[0], change_list_.size(), event_list, nevents, NULL);
//
//    std::cout << "cnt_event : " << cnt_event << std::endl; // temporary echo-printout
//    ClearChangeList();
//
//    if (cnt_event == -1)
//      std::cout << "kevent : error : tmp  : errno [" << errno << "]"<< std::endl;
//
//	  for (int i = 0; i < cnt_event; i++) {
//      current_event = event_list[i];
//
//      if (IsErrorFlags(current_event.flags))
//        std::cout << "IsErrorFlags : tmp : ident[" << current_event.ident << "],  flags [" << current_event.flags << "]" << std::endl;
//      else if (IsReadEvent(current_event.filter)) {
//          std::cout << "readevent" << std::endl;
//        if (current_event.udata != NULL && (*(Udata *)current_event.udata).IsServer())
//          ManageServerReadEvent(current_event);
//        else if (current_event.udata != NULL && (*(Udata *)current_event.udata).IsClient())
//          ManageClientReadEvent(current_event, *((Client *)current_event.udata));
//        else
//          std::cout << "IsReadEvent : error : tmp" << std::endl;
//      }
//      else if(IsWriteEvent(current_event.filter)) {
//        if (1) // Client socket// else if (0) // File socket  ;std::cout << "hello\n";
//          ManageClientWriteEvent(current_event, *((Client *)current_event.udata));
//        else
//          std::cout << "IsWriteEvent : error : tmp" << std::endl;
//      }
//    }
//
//  }
//}
//
//// private *********************************************************************
//
//// unused func
//// change
//void  Webserv::AddListenSocketEventInChageList() {
//  for (std::vector<Server>::iterator iter = servers_.begin(); iter != servers_.end(); iter++)
//    AddChangeList(iter->GetListenSocket().GetSocketFD(), EVFILT_READ, EV_ADD, 0, 0, &(*iter));
//}
//
//// tmp function set Servers
//void Webserv::SetServers(){
//  Server new_server(INADDR_ANY, 8080);
//  servers_.push_back(new_server);
//}
//
//
//// manage events
//void Webserv::ManageServerReadEvent(struct kevent& current_event) {
//
//  Client  client_instance(*(Server *)current_event.udata, current_event.ident); //  Socket  client_socket(current_event.ident);
//  int socket_fd = client_instance.GetClientSocket().GetSocketFD();
//
//  clients_.insert(std::pair<int, Client>(socket_fd, client_instance)); // need success check
//  AddChangeList(socket_fd, EVFILT_READ, EV_ADD, 0, 0, &(*clients_.find(socket_fd)).second);
////  AddChangeList(client_instance.GetClientSocket().GetSocketFD(), EVFILT_WRITE, EV_ADD, 0, 0, &(clients_.back()));
////  std::cout << "ManageServerReadEvent : accept : new client: " << client_instance.GetClientSocket().GetSocketFD() << std::endl;
//}
//
//void Webserv::ManageClientReadEvent(struct kevent& current_event, Client& client_instance) {
//  char buff[1024];
//  ssize_t n = recv(current_event.ident, buff, sizeof(buff), 0);
//
//  if (n < 0)
//    std::cout << "received error from client : recv == " << n << "\n";
//  else if (n == 0) {
//    std::cout << "EOF, close..\n";
//
//    clients_.erase(current_event.ident);
//    close(current_event.ident);
//  }
//  else {
//    std::cout << "ManageClientReadEvent : recv : buff :" << buff << std::cout;
//    AddChangeList(current_event.ident, EVFILT_WRITE, EV_ADD, 0, 0, current_event.udata);
//
//  }
//}
//
//
//
//// tmp func
//char* readIndexHtml() {
//	printf("mooyaho\n");
//    FILE* file = fopen("index.html", "r");
//    if (file == NULL) {
//        printf("파일을 열 수 없습니다.\n");
//        return NULL;
//    }
//
//    fseek(file, 0, SEEK_END);
//    long size = ftell(file);
//    rewind(file);
//
//    char* buffer = (char*)malloc(size + 1);
//    if (buffer == NULL) {
//        printf("메모리를 할당할 수 없습니다.\n");
//        fclose(file);
//        return NULL;
//    }
//
//    size_t result = fread(buffer, 1, size, file);
//    if (result != size) {
//        printf("파일을 읽을 수 없습니다.\n");
//        free(buffer);
//        fclose(file);
//        return NULL;
//    }
//
//    buffer[size] = '\0';
//    fclose(file);
//
//    return buffer;
//}
//
//void Webserv::ManageClientWriteEvent(struct kevent& current_event, class Client& client_instance) {
//  if (1) {
//    std::string str = "HTTP/1.0 200 OK\r\nServer:Linux Web Server \r\nContent-length:2048\r\nContent-type:text/html\r\n\r\nHello World!";
//    std::string jchoi = readIndexHtml();
//	  ssize_t n = send(current_event.ident, jchoi.c_str(), jchoi.length(), 0);
//    std::cout << "ManageClientWriteEvent : send" << std::endl;
//    int socket_fd = client_instance.GetClientSocket().GetSocketFD();
//    AddChangeList(socket_fd, EVFILT_WRITE, EV_DELETE, 0, 0, &(*clients_.find(socket_fd)).second);
//  }
//  else
//    std::cout << "ManageClientWriteEvent : empty" << std::endl;
//
//}
//
//// ChangeList
//void Webserv::AddChangeList(uintptr_t ident, int16_t filter, uint16_t flags, uint32_t fflags, intptr_t data, void* udata) {
//	struct kevent new_event;
//
//  EV_SET(&new_event, ident, filter, flags, fflags, data, udata);
//	change_list_.push_back(new_event);
//}
//
//void Webserv::ClearChangeList() {
//  change_list_.clear();
//}
//
//// utils
//bool Webserv::IsErrorFlags(uint16_t flags) const {
//  return flags & EV_ERROR;
//}
//
//bool Webserv::IsReadEvent(int16_t filter) const {
//  return filter == EVFILT_READ;
//}
//
//bool Webserv::IsWriteEvent(int16_t filter) const {
//  return filter == EVFILT_WRITE;
//}
