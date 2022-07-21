//
// Created by corecaps on 20/07/22.
//

#ifndef MINITALK_SERVER_H
#define MINITALK_SERVER_H
#include "ft_printf/ft_printf.h"
#include <unistd.h>
#include <signal.h>
typedef struct s_message
{
	pid_t				pid;
	int 				bit;
	struct s_message	*next;
} t_message;
#endif //MINITALK_SERVER_H