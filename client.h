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

#ifndef MINITALK_CLIENT_H
# define MINITALK_CLIENT_H

int     ft_atoi(const char *nptr);
int     ft_isdigit(int c);
size_t  ft_strlen(const char *s);
void	talk(int pid);

#endif //MINITALK_CLIENT_H
