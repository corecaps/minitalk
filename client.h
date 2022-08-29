/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:56:32 by jgarcia           #+#    #+#             */
/*   Updated: 2022/07/06 00:56:35 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include <signal.h>

void	handshake_retry(const siginfo_t *server_info);
int		send_null(const siginfo_t *server_info, int count);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
#endif