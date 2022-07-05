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

int	main(int argc, char **argv)
{
	pid_t pid;

	if (argc != 3)
	{
		ft_printf("Usage : %s PID string_to_send\n", argv[0]);
		return (-1);
	}
	pid = (pid_t) ft_atoi(argv[1]);
	talk(pid, argv[2]);
	return (0);
}