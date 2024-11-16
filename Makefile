# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izperez <izperez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 23:29:13 by adlopez-          #+#    #+#              #
#    Updated: 2024/11/16 12:49:39 by izperez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d
INCLUDE =	includes/cub3d.h
CC		=	cc -g3 -O2 -Wuninitialized
CFLAGS	=	-Wall -Werror -Wextra #-fsanitize=address -g3
SRC_DIR	=	srcs/
SRC_FILES = main \
			00_error \
			01_parse \
			02_mapcheck \
			03_redgreenblue \
			04_textures \
			05_parse_utils \
			06_parse_utils_2 \
			07_init_struct \
			utils/00_split \
			utils/01_split_utils \
			
OBJ_DIR	=	objs/
MLX_DIR	=	mlx
LIBS	=	$(MLX_DIR)/libmlx.a $(MLX)
SRC			=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS		=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
MLX			=	-lXext -lX11 -lm -lbsd 


.SILENT:
all: MLX_DIR $(NAME) 

$(NAME):  $(OBJS) 
	$(CC) $(OBJS) $(LIBS) -o $(NAME)
	@echo "\033[32mCub3d no payo compiled!\033[0m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/utils
	echo "compilando cosas"
	@$(CC) $(CFLAGS)  -o  $@ -c $<

MLX_DIR:
	make -C $(MLX_DIR) all

clean:
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(OBJS)

re: fclean all