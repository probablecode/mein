/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:12:50 by jchoi             #+#    #+#             */
/*   Updated: 2022/06/26 20:56:01 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TRUE 1
#define FALSE 0
//#include "minitalk.h"
#include "libft.h"
#include "ft_printf.h"
#include <signal.h>

typedef struct s_client
{
	struct sigaction	connect;
	struct sigaction	sendmsg;
	pid_t				clientpid;
	pid_t				serverpid;
	char				*msg;
	size_t				msglen;
	size_t				chcnt;
	size_t				bitcnt;
	int					flag;
}	t_client;

t_client	g_client;

void	mt_sendmsg(void);
void	sig_connect(int signo, siginfo_t *siginfo, void *context);
void	sig_sendmsg(int signo, siginfo_t *siginfo, void *context);
void	init_client(void)
{
	g_client.clientpid = getpid();
	g_client.connect.sa_sigaction = sig_connect;
	sigemptyset(&g_client.connect.sa_mask);
	g_client.connect.sa_flags = SA_SIGINFO;
	g_client.sendmsg.sa_sigaction = sig_sendmsg;
	sigemptyset(&g_client.sendmsg.sa_mask);
	g_client.sendmsg.sa_flags = SA_SIGINFO;
	g_client.chcnt = 0;
	g_client.bitcnt = 0;
	g_client.flag = 0;
	ft_printf("[minitalk] : client(%d) initiated.\t", g_client.clientpid);
}

void	validitycheck(int argc, char *argv[])
{
	ft_putendl_fd("arguments validity check..", 1);
	if (argc == 3)
	{
		g_client.serverpid = (pid_t)ft_atoi(argv[1]);
		if ((argv[1][0] == '-') + (6 <= ft_strlen(argv[1])) + (g_client.serverpid < 100))		{
			ft_putendl_fd("[minitalk] : Invalid pid\n", 1);
			exit(1);
		}	
		g_client.msglen = ft_strlen(argv[2]);
		if (!g_client.msglen)
		{
			ft_putendl_fd("[minitalk] : Invalid Message", 1);
			exit(1);
		}
		g_client.msg = argv[2];
	}
	else
	{
		ft_putendl_fd("[minitalk] : Invalid number of Arguments", 1);
		exit(1);
	}
	ft_putendl_fd("[minitalk] : validation complete!", 1);
}

void	sig_connect(int signo, siginfo_t *siginfo, void *context)
{
	pid_t	srvpid;
	
	(void)siginfo;
	(void)context;
	srvpid = g_client.serverpid;
	if (siginfo->si_pid == srvpid)
	{	
		if (signo == SIGUSR1)
		{
			ft_printf("\n\n[server(%d)] : processing other client. ", srvpid);
			ft_printf("connect a few moment later.\n");
			ft_printf("[minitalk] : exit program\n");
			exit(1);
		}
		else if (signo == SIGUSR2 && !g_client.flag)
		{
			ft_printf("\n\n[server] : connected\n");
			g_client.flag++;
		}
	}
}

void	mt_connect(void)
{
	int		timer;
	pid_t	srvpid;
	pid_t	clipid;
	
	clipid = g_client.clientpid;
	srvpid = g_client.serverpid;
	sigaction(SIGUSR1, &g_client.connect, NULL);
	sigaction(SIGUSR2, &g_client.connect, NULL);
	ft_printf("\n[client(%d)] : connecting to server(%d)..", clipid, srvpid);
	kill (srvpid, SIGUSR2);
	timer = usleep(8000000);
	if (!timer)
	{
		ft_printf("\tserver(%d) didn't respond.\n" ,srvpid);
		ft_printf("\n[minitalk] : exit program.\n");
		exit(1);
	}
} 

void	mt_sendnull(void)
{
	while (g_client.bitcnt < 8)
	{
		kill(g_client.serverpid, SIGUSR1);
		g_client.bitcnt++;
		pause();
	}
}

void	sig_sendmsg(int signo, siginfo_t *siginfo, void *context)
{
	(void)siginfo;
	(void)context;

	if (signo == SIGUSR2 && siginfo->si_pid == g_client.serverpid)
		mt_sendmsg();
}

void	mt_sendmsg(void)
{
	size_t	bc;
	size_t	cc;
	int		sig;
	
	cc = g_client.chcnt;
	bc = g_client.bitcnt;
	sigaction(SIGUSR2, &g_client.sendmsg, NULL);
	usleep(500000);
	if (cc < g_client.msglen)
	{
		if (bc < 8)
		{
			sig = (g_client.msg[cc] & (1 << bc));
			sig = SIGUSR1 + (SIGUSR2 - SIGUSR1) * (0 < sig);
			g_client.bitcnt = (bc + 1);
			ft_printf("client to server sig(%d)\n", sig);
			kill(g_client.serverpid, sig);
		}
		else
		{
			g_client.bitcnt = 0;
			g_client.chcnt++;
		}
	}
	else
		mt_sendnull();
	usleep(500000);
}

int	main(int argc, char *argv[])
{	
	init_client();
	validitycheck(argc, argv);
	mt_connect();
	usleep(100000);
	while (g_client.chcnt < g_client.msglen)
		mt_sendmsg();
	return (0);
}










//send_msglen_handler(); // 1을 받으면msglen을 계속 뱉는 친구
/*void send_msglen(pid_t pid, const size_t len)
{
	static size_t	step = 0;
	const int		signo;
	if (len | 1 << step)
		signo = SIGUSR2;
	else
		signo = SIGUSR1;
		
	if (step < 32)
	{
		kill(pid, signo);
		step++;
		pause();
	}
	else // 이제 다음 거로 바꿔야죠 메시지 전송으로!
// 		sigaction(); 
}

void	send_msglen(pid_t pid)
{
	static size_t	bit = 0;
	if (bit < 32)
	{
		if (g_len & (1 << bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		pause();
		bit++;
	}
	else
	{
		send_msg(pid);
	}
}
*/


