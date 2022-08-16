/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:56:17 by jgarcia           #+#    #+#             */
/*   Updated: 2022/07/04 23:56:18 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf/ft_printf.h"
#include "client.h"
#include <signal.h>

char	*str;

void	listen(int signum, siginfo_t *server_info, void *context)
{
	static int	handshake = 0;
	static int	count = 1;
	static int	str_index = 0;
	char		c;

	(void) context;
	if (signum == SIGUSR1 && handshake == 0)
	{
		handshake = 1;
		ft_printf("handshake cplt");
	}
	if (signum == SIGUSR1 && str[str_index] != '\0' && count < 9 && handshake == 1)
	{
		c = str[str_index];
		if (c & (1 << (8-count)))
			kill (server_info->si_pid,SIGUSR1);
		else
			kill(server_info->si_pid,SIGUSR2);
		count ++;
	}
	if (count == 9)
	{
		count = 1;
		str_index ++;
	}
	usleep(50);
}

int	main(int argc, char **argv)
{
	pid_t pid;
	struct sigaction message_handler;

	if (argc != 3)
	{
		ft_printf("Usage : %s PID string_to_send\n", argv[0]);
		return (-1);
	}
	str = argv[2];
	message_handler.sa_sigaction = listen;
	sigemptyset(&message_handler.sa_mask);
	message_handler.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1,&message_handler,NULL);
	sigaction(SIGUSR2,&message_handler,NULL);
	pid = (pid_t) ft_atoi(argv[1]);
	talk(pid);
	while (1)
	{
		usleep(500);
	}
	return (0);
}