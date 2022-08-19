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
	static int	bit_sent = 0;

	(void) context;
	if (signum == SIGUSR1 && handshake == 0)
	{
		handshake = 1;
	}
	if (signum == SIGUSR1 && str &&str[str_index] != '\0' && count < 9 && handshake == 1)
	{
		if (str[str_index] & (1 << (8-count)))
			kill (server_info->si_pid,SIGUSR1);
		else
			kill(server_info->si_pid,SIGUSR2);
		count ++;
		bit_sent ++;
	}
	if (str && str[str_index] == '\0')
	{
		count = 0;
		while (count < 8)
		{
			usleep(100);
			kill(server_info->si_pid, SIGUSR2);
			count ++;
		}
		ft_printf("%d bits sent\n",bit_sent);
		str = NULL;

	}
	if (count == 9)
	{
		count = 1;
		str_index ++;
	}

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
	while (str != NULL)
	{
		usleep(50);
	}
	return (0);
}