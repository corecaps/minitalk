# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/02 15:35:01 by jgarcia           #+#    #+#              #
#    Updated: 2022/07/02 15:35:40 by jgarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SRV = server
NAME_CLIENT = client
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAG = -g
LIB = -Lft_printf -lftprintf
PRINTF = ./ft_printf/libftprintf.a
SOURCES_SRV = server.c
SOURCES_CLIENT = client.c client_utils.c
OBJ_SRV = $(SOURCES_SRV:.c=.o)
OBJ_CLIENT = $(SOURCES_CLIENT:.c=.o)

all: 			$(NAME_SRV) $(NAME_CLIENT)

$(NAME_SRV): 	$(OBJ_SRV) $(PRINTF)
	$(CC) $(OBJ_SRV) $(LIB) $(CFLAGS) -o $(NAME_SRV)

$(NAME_CLIENT): $(OBJ_CLIENT) $(PRINTF)
	$(CC) $(OBJ_CLIENT) $(LIB) $(CFLAGS) -o $(NAME_CLIENT)

$(PRINTF):
	make -C ./ft_printf/

%.o: 			%.c
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	rm -f $(OBJ_CLIENT)
	rm -f $(OBJ_SRV)

fclean: 		clean
	rm -f $(NAME_SRV)
	rm -f $(NAME_CLIENT)

re: 			fclean all

norme:
	norminette $(SOURCES_CLIENT)
	norminette $(SOURCES_SRV)

.PHONY: all clean fclean re