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
	pid_t 	client_pid;

	client_pid = client_info->si_pid;
	(void      )client_pid;
	(void)context      ;
	static char data = 0;
	static int 	count = 0;

	if (signum == SIGUSR1)
	{
		data |= 1;
		data <<= 1;
		count ++;
		write(1,"1",1);
		ft_printf("{%d}\n",data);
	}
	else if (signum == SIGUSR2)
	{
		data <<= 1;
		count ++;
		write(1,"0",2);
		ft_printf("{%d}\n",data);
	}
	if (count == 8)
	{
		write(1,"\n\n",2);
		write (1, &data, 1);
		ft_printf("\n[%d]\n",data);
		write(1,"\n\n",2);
		data = 0;
		count = 0;
	}
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
	ft_printf("%d",server_pid);

	while (1)
	{
		usleep(5);
	}
	return (0);
}