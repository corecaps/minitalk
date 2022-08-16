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

/* send Handshake request
 * TODO : retry handshake until server's ready to take datas
 **/

void talk(pid_t pid)
{
	kill(pid,SIGUSR1);
	/*	while (str && *str != '\0')
	{
		c = *str;
		i = 1;

		while (i < 9)
		{
			if (c & (1 << (8 - i)))
			{
				kill(pid, SIGUSR1);
			}
			else
				kill(pid, SIGUSR2);
			i ++;
			usleep(500);
		}
		str ++;
	}
*/
	}
