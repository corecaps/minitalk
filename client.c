/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:56:17 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/30 00:24:10 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf/ft_printf.h"
#include "client.h"

char	*g_str;

void	listen(int signum, siginfo_t *server_info, void *context)
{
	static int	handshake = 0;
	static int	count = 1;
	static int	str_index = 0;

	(void) context;
	if (signum == SIGUSR1 && handshake == 0)
		handshake = 1;
	if (signum == SIGUSR2 && handshake == 0)
		handshake_retry(server_info);
	if (signum == SIGUSR1 && g_str
		&& g_str[str_index] != '\0' && count < 9 && handshake == 1)
	{
		if (g_str[str_index] & (1 << (8 - count)))
			kill(server_info->si_pid, SIGUSR1);
		else
			kill(server_info->si_pid, SIGUSR2);
		count++;
	}
	if (g_str && g_str[str_index] == '\0')
		count = send_null(server_info, count);
	if (count == 9)
	{
		count = 1;
		str_index++;
	}
}

void	handshake_retry(const siginfo_t *server_info)
{
	usleep(200);
	kill(server_info->si_pid, SIGUSR1);
}

int	send_null(const siginfo_t *server_info, int count)
{
	count = 0;
	while (count < 8)
	{
		usleep(110);
		kill(server_info->si_pid, SIGUSR2);
		count++;
	}
	g_str = NULL;
	return (count);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	message_handler;

	if (argc != 3)
	{
		ft_printf("Usage : %s PID string_to_send\n", argv[0]);
		return (-1);
	}
	g_str = argv[2];
	message_handler.sa_sigaction = listen;
	sigemptyset(&message_handler.sa_mask);
	message_handler.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &message_handler, NULL);
	sigaction(SIGUSR2, &message_handler, NULL);
	pid = (pid_t) ft_atoi(argv[1]);
	kill(pid, SIGUSR1);
	while (g_str != NULL)
		usleep(100);
	return (0);
}
