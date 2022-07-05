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

int	main(int argc, char **argv)
{
	int pid;

	if (argc != 3)
	{
		ft_printf("Usage : %s PID string_to_send\n", argv[0]);
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	(void) pid;
}