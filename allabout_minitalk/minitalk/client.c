typedef struct	s_client
{
	struct sigaction	connect;
	struct sigaction	msglen_send;
	struct sigaction	msg_send;	
	pid_t				server_pid;
	char				*message;
	size_t				msglen;
}	t_client

extern t_client	g_client;

typedef	struct	s_pid_list
{
	pid_t				pid;
	struct s_pid_list	*next;
}	t_pid_list

typedef struct	s_server
{
	struct sigaction	permit_connect;
	struct sigaction	read_msglen;
	struct sigaction	read_message;
	pid_t				client_pid;
	t_pid_list			*waiting_queue;
	char				*message;
	size_t				msglen;
	size_t				bitcount;
	size_t				count;
}	t_server;

wait_permission;
popup;
