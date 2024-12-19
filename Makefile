#                                                     +:+ +:+         +:+      #
#    By: izperez <izperez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 17:44:29 by adrian            #+#    #+#              #
#    Updated: 2024/12/17 13:17:37 by izperez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
MLXFLAGS = -L$(MLX_DIR) -lm -lmlx -lX11 -lXext

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a

SRCS = main.c \
		srcs/00_error.c \
		srcs/0x_freedom.c \
		srcs/01_setup_checker.c \
		srcs/02_parse.c \
		srcs/03_setup_data.c \
		srcs/04_setup_map.c \
		srcs/05_utils_function.c \
		srcs/06_render_map.c \
		srcs/07_hooks.c \
		srcs/08_3d.c \
		srcs/09_textures.c \
		utils/00_utils.c \
		utils/01_utils_libft.c \
		utils/02_utils_textures.c

OBJS = $(SRCS:.c=.o)

.SILENT:
all: $(MLX_LIB) $(NAME)

# Compilación de la MLX
$(MLX_LIB):
	@echo "🛠️  Compilando librería MLX..."
	@make -C $(MLX_DIR)
	@echo "✅ Librería MLX compilada correctamente!"

# Compilación del programa
$(NAME): $(OBJS)
	@echo "🛠️  Compilando $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)
	@echo "✅ Compilación correcta!"

# Regla para generar archivos .o
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Limpieza
clean:
	@rm -f $(OBJS)
	@make -C $(MLX_DIR) clean
	@echo "🧹 Archivos .o eliminados!"

fclean: clean
	@rm -f $(NAME)
	@make -C $(MLX_DIR) clean
	@echo "🗑️ Ejecutable eliminado!"

re: fclean all

