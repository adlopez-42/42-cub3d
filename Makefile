# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adlopez- <adlopez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 23:29:13 by adlopez-          #+#    #+#              #
#    Updated: 2024/11/14 00:09:07 by adlopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra #-fsanitize=address -g3
SRCS	=	srcs/*.c main.c utils/*.c

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

fclean:
	rm -rf cub3d