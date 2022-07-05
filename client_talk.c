/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_talk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:56:56 by jgarcia           #+#    #+#             */
/*   Updated: 2022/07/06 00:57:02 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "client.h"
#include "ft_printf/ft_printf.h"

void talk(pid_t pid,char *str)
{
	int 	i;
	char	c;

	while (str && *str != '\0')
	{
		c = *str;
		i = 0;
		while (i < 8)
		{
			if (c & 1)
			{
				kill(pid, SIGUSR1);
				write(1, "1\n", 2);
			}
			else
			{
				kill(pid, SIGUSR2);
				write(1, "0\n", 2);
			}
			c = c >> 1;
			i ++;
			usleep(200);
		}
		str ++;
	}
}
