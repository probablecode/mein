/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:39:53 by jchoi             #+#    #+#             */
/*   Updated: 2022/06/26 20:58:38 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TRUE 1
#define FALSE 0
//#include "minitalk.h"
#include "libft.h"
#include "ft_printf.h"
#include <signal.h>

typedef struct s_server
{
	struct sigaction	permit;
	struct sigaction	receive;
	pid_t				clientpid;
	pid_t				serverpid;
	size_t				bitcnt;
	char				ch;
}	t_server;

t_server	g_server;

void    sig_permit(int signo, siginfo_t *siginfo, void *context);
void	mt_permit(void);
void    sig_receive(int signo, siginfo_t *siginfo, void *context);
void	mt_receive(int sig);
void	mt_print(void);

void	init_server(void)
{
	g_server.serverpid = getpid();
	ft_printf("[minitalk] : start server(%d) on.\n", g_server.serverpid);
	g_server.permit.sa_sigaction = sig_permit;
	sigemptyset(&g_server.permit.sa_mask);
	g_server.permit.sa_flags = SA_SIGINFO;
	g_server.receive.sa_sigaction = sig_receive;
	sigemptyset(&g_server.receive.sa_mask);
	g_server.receive.sa_flags = SA_SIGINFO;
	g_server.clientpid = 0;
	g_server.bitcnt = 0;
	g_server.ch = 0;
}

void    sig_permit(int signo, siginfo_t *siginfo, void *context)
{
	if (!g_server.clientpid)
	{
		g_server.clientpid = siginfo->si_pid;
		kill(g_server.clientpid, SIGUSR2);
		ft_printf("[minitalk] : message from client(%d)\n", g_server.clientpid);
		mt_receive(0);
	}
}

void	mt_permit(void)
{
	sigaction(SIGUSR2, &g_server.permit, NULL);
}

void    sig_receive(int signo, siginfo_t *siginfo, void *context)
{
	(void)siginfo;
	(void)context;
	
	if (g_server.clientpid == siginfo->si_pid)
		mt_receive(signo);
	else
		kill(siginfo->si_pid, SIGUSR1);
}

void	mt_receive(int sig)
{
	sigaction(SIGUSR1, &g_server.receive, NULL);
	sigaction(SIGUSR2, &g_server.receive, NULL);
	if (sig)
	{
		g_server.ch += ((sig == SIGUSR2) & (1 << g_server.bitcnt));
		g_server.bitcnt++;
		if (g_server.bitcnt == 8)
		{
			write(1, &g_server.ch, 1);
			g_server.ch = 0;
			g_server.bitcnt = 0;
		}
		usleep(500000);
		kill(g_server.clientpid, SIGUSR2);
		usleep(500000);
		ft_printf("sig :%d\n", sig);
	}
}
/*
void	mt_print(void)
{
	if (g_server.ch)
	{
		write(1, &g_server.ch, 1);
	}
	else
	{
		g_server.clientpid = 0;
	}
}
*/
int	main(void)
{
	init_server();
	while (1)
	{
		if (!g_server.clientpid)
			mt_permit();
	}
	return (0);
}
