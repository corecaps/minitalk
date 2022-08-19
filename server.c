/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:56:09 by jgarcia           #+#    #+#             */
/*   Updated: 2022/07/04 23:56:10 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void listen(int signum,siginfo_t *client_info,void *context)
{
	static pid_t 	client_pid = 0;
	static char data = 0;
	static int 	count = 1;
	static  int handshake = 0;

	(void)context      ;
	if (client_pid == 0)
		client_pid = client_info->si_pid;
	if (handshake == 1)
	{
		if (signum == SIGUSR1)
		{
			data =  data << 1;
			data |= 1;
			count ++;
		}
		else if (signum == SIGUSR2)
		{
			data = data << 1;
			count ++;
		}
		if (count == 9)
		{
			if (data == 0)
			{
				handshake = 0;
				client_pid = 0;
				data = 0;
				count = 1;
				return ;
			}
			write (1, &data, 1);
			data = 0;
			count = 1;
		}
	}
	else if (signum == SIGUSR1)
	{
		handshake = 1;
		count = 1;
	}
	usleep(10);
	kill(client_pid, SIGUSR1);
}
int main(void)
{
	pid_t server_pid;
	struct sigaction message_handler;

	message_handler.sa_sigaction = listen;
	sigemptyset(&message_handler.sa_mask);
	message_handler.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &message_handler, NULL);
	sigaction(SIGUSR2, &message_handler,NULL);
	server_pid = getpid();
	ft_printf("%d\n",server_pid);

	while (1)
	{
		usleep(500);
	}
	return (0);
}