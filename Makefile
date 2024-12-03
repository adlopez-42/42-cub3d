# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izperez <izperez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 17:44:29 by adrian            #+#    #+#              #
#    Updated: 2024/12/02 11:24:45 by izperez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ya haremos un makefile d everdad ahora pa que no haya rollos t pongo este

CC			=	gcc
MLX			=	./mlx
CFLAGS		=	-Wall -Werror -Wextra -fsanitize=address -g3 
MLXFLAGS	=	-L$(MLX) -lm -lmlx -lX11 -lXext 
SRCS		=	srcs/*.c utils/*.c main.c

all:
	$(CC) $(CFLAGS) $(SRCS) -o cub3d $(MLXFLAGS)

re:
	rm -rf cub3d all