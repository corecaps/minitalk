/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 23:10:23 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/30 00:24:00 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <signal.h>
# define BUFFER_SIZE 1024

pid_t	next_byte(pid_t *client_pid, int *count, int *handshake,
			int *buffer_index);
int		get_data(int signum, int count, int buffer_index);
#endif
