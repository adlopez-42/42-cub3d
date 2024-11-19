# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 23:29:13 by adlopez-          #+#    #+#              #
#    Updated: 2024/11/19 12:59:17 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address -g3 -lXext -lX11 -lm -lbsd 
SRCS	=	srcs/*.c main.c utils/*.c mlx/*.c

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

fclean:
	rm -rf cub3d