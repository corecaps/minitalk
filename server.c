/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:56:09 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/31 11:28:12 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	g_buffer[BUFFER_SIZE];

void	listen(int signum, siginfo_t *client_info, void *context)
{
	static pid_t	client_pid = 0;
	static int		count = 1;
	static int		handshake = 0;
	static int		buffer_index = 0;

	(void)context;
	if (client_pid == 0)
		client_pid = client_info->si_pid;
	if (client_info->si_pid != client_pid)
	{
		usleep(50);
		kill(client_info->si_pid, SIGUSR2);
		return ;
	}
	if (handshake == 1)
	{
		count = get_data(signum, count, buffer_index);
		if (count == 9)
			client_pid = next_byte(&client_pid,
					&count, &handshake, &buffer_index);
	}
	else if (signum == SIGUSR1)
		handshake = 1;
	if (client_pid != 0)
		kill(client_pid, SIGUSR1);
}

pid_t	next_byte(pid_t *client_pid, int *count,
			int *handshake, int *buffer_index)
{
	if (g_buffer[(*buffer_index)] == 0)
	{
		write (1, &g_buffer, *buffer_index + 1);
		g_buffer[0] = 0;
		(*handshake) = 0;
		(*buffer_index) = 0;
		(*count) = 1;
		(*client_pid) = 0;
		return (0);
	}
	(*buffer_index)++;
	if ((*buffer_index) == BUFFER_SIZE)
	{
		write(1, &g_buffer, BUFFER_SIZE);
		(*buffer_index) = 0;
	}
	(*count) = 1;
	return (*client_pid);
}

int	get_data(int signum, int count, int buffer_index)
{
	if (signum == SIGUSR1)
	{
		g_buffer[buffer_index] = (char)(g_buffer[buffer_index] << 1);
		g_buffer[buffer_index] |= 1;
		count ++;
	}
	else if (signum == SIGUSR2)
	{
		g_buffer[buffer_index] = (char)(g_buffer[buffer_index] << 1);
		count ++;
	}
	return (count);
}

int	main(void)
{
	pid_t				server_pid;
	struct sigaction	message_handler;

	message_handler.sa_sigaction = listen;
	sigemptyset(&message_handler.sa_mask);
	message_handler.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &message_handler, NULL);
	sigaction(SIGUSR2, &message_handler, NULL);
	server_pid = getpid();
	ft_printf("%d\n", server_pid);
	while (1)
	{
		usleep(500);
	}
	return (0);
}
