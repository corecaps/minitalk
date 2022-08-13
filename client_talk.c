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
		i = 1;
//		ft_printf("\n[%d]\n",c);

		while (i < 9)
		{
			// binary is transmitted backward !!!!
			if (c & (1 << (8 - i)))
			{

				kill(pid, SIGUSR1);
//				write(1, "\t1", 2);

			}
			else
			{
				kill(pid, SIGUSR2);
//				write(1, "\t0", 2);
			}
			//c = c >> 1;
			i ++;
			usleep(500);
		}
//		write(1,"\n",1);
		str ++;
	}
}