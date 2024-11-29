# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrian <adrian@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 17:44:29 by adrian            #+#    #+#              #
#    Updated: 2024/11/26 20:05:55 by adrian           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ya haremos un makefile d everdad ahora pa que no haya rollos t pongo este

CC			=	gcc
MLX			=	./mlx
CFLAGS		=	-Wall -Werror -Wextra -fsanitize=address -g3 
MLXFLAGS	=	-L$(MLX) -lmlx -lm -lX11 -lXext
SRCS		=	srcs/*.c utils/*.c main.c

all:
	$(CC) $(CFLAGS) $(SRCS) $(MLXFLAGS) -o cub3d

re:
	rm -rf cub3d all