#include "IrcServer.hpp"

void IrcServer::Set()
{
	try {
		server_socket_.InitServerSocket(INADDR_ANY, 6667);
		kqueue_.InitPoller(server_socket_.GetSocketFD());
	}
	catch (std::exception& e) {
	  std::cout << e.what() << std::endl;
	  throw MyExceptions(MyExceptions::kServer, "Server::Set() fail");
	}
}

void IrcServer::Run() {
	
	// start of while loop
	try {								 
		while (1) {
			kqueue_.Safekevent();
			struct kevent* current_event;
			while (current_event = kqueue_.GetCurrentEvent()) {
				kqueue_.CheckErrorFlags(current_event);//throw internal execption
				else if (kqueue_.IsReadEvent(current_event->filter))
					ManageReadEvent(current_event);
				else if (kqueue_.IsWriteEvent(current_event->filter))
					ManageWriteEvent(current_event);
			}
		}
	}
	catch (std::exception& e) {
	  std::cout << e.what() << std::endl;
	  throw MyExceptions(MyExceptions::kServer, "Server::Run() fail");
	}
}

void IrcServer::ManageReadEvent(struct kevent* current_event) {
	if (current_event->ident == server_socket_.GetSocketFD()) { // server_sock에서-> 새 client 등장
		Client client = new Client();
		client->InitClient(current_event->ident);
		// InitClient : client 내에서 자기 socket의 InitClientSocket() 함수를 실행한다
		int client_socket_fd = client->GetClientSocket().GetSocketFD();
		clients_[client_socket_fd] = client; // map에 삽입하는 문장
		kqueue_.AddEvent(client_socket_fd, EVFILT_READ);
	}
	else {// Client에서 메시지가 왔을떄..
	  char buff[4096] = {0,};
	  Client* client = GetClient(current_event->ident);
	  ssize_t n = recv(current_event->ident, buff, sizeof(buff), 0);
	  if (n < 0)
		  throw MyExceptions(MyExceptions::kServer, "Server::recv() fail");
	  else if (n == 0) {
		client->Clean();
		close(current_event->ident);
		clients_.erase(current_event->ident);
	  }
	  else { 
		  Buffer buffer = client->GetFromClientBuffer(); 
		  buffer += buff;
		  executeTransaction(client);
	  // 개행을 받을 때 까지 버퍼에 담아뒀다가
	  // 완전한 문장으로 전달이 되서 서버에서 실행이 되었다면
	  // 그떄 AddEvent(client_socket_fd, EVFILT_WRITE)를 등록하는 함수를 호출한다
	  }
	}
}

void IrcServer::ManageWriteEvent(struct kevent* current_event) {
	Client* client = GetClient(current_event->ident);

	if (!client)
	  throw MyExceptions(MyExceptions::kServer, "Server::GetClient() fail");
	Buffer buffer = client->GetToClientBuffer(); // need to define 'Buffer'
	if (buffer.IsReady()) {
		size_t	len = buffer_.size();
		ssize_t	result = send(current_event->ident, buffer_.c_str(), len, 0);
		if (result != len)
			throw MyExceptions(MyExceptions::kServer, "Server::send() fail");
		kqueue_.DeleteEvent(current_event->ident, EVFILT_WRITE);
	}
}
