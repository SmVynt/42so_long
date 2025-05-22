# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 16:14:14 by psmolin           #+#    #+#              #
#    Updated: 2025/05/22 20:41:15 by psmolin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
HEADERS = so_long.h
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g -I.
MK = make -C
SRC = src/
#
SRCS = \
		$(SRC)initialize.c \
		$(SRC)initialize_animations.c \
		$(SRC)initialize_map.c \
		$(SRC)initialize_objs.c \
		$(SRC)initialize_images.c \
		$(SRC)initialize_hero.c \
		$(SRC)initialize_hooks.c \
		$(SRC)initialize_tilemap.c \
		$(SRC)render_animation.c \
		$(SRC)render_images.c \
		$(SRC)render_scale.c \
		$(SRC)update_count.c \
		$(SRC)update_enemies.c \
		$(SRC)update_hero.c \
		$(SRC)update_objs.c \
		$(SRC)update_loop.c \
		$(SRC)utils_1.c \
		$(SRC)utils_2.c \
		$(SRC)utils_3.c \
		$(SRC)utils_colors.c \
		$(SRC)utils_enemies.c \
		$(SRC)main.c
OBJS = $(SRCS:.c=.o)
#
MLX_FOLDER = mlx/
MLX_LIB = $(MLX_FOLDER)libmlx.a
MLX_FLAGS = -Lmlx -lmlx -framework openGL -framework AppKit
#
GNL_FOLDER = lbs/gnl/
GNL_LIB = $(GNL_FOLDER)libgnl.a
GNL_FLAGS = -L$(GNL_FOLDER) -lgnl
PRT_FOLDER = lbs/printf/
PRT_LIB = $(PRT_FOLDER)libftprintf.a
PRT_FLAGS = -L$(PRT_FOLDER) -lftprintf
#
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

all: makeadd $(NAME)

makeadd:
	$(MK) $(MLX_FOLDER) all
	$(MK) $(GNL_FOLDER) all
	$(MK) $(PRT_FOLDER) all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(GNL_FLAGS) $(PRT_FLAGS) \
	$(OBJS) $(MLX_LIB) $(GNL_LIB) $(PRT_LIB) -o $(NAME)

clean:
	$(MK) $(MLX_FOLDER) clean
	$(MK) $(GNL_FOLDER) clean
	$(MK) $(PRT_FOLDER) clean
	$(RM) $(OBJS)

fclean:
	$(MK) $(MLX_FOLDER) fclean
	$(MK) $(GNL_FOLDER) fclean
	$(MK) $(PRT_FOLDER) fclean
	$(RM) $(OBJS)
	$(RM) $(NAME)

re: fclean all

bonus: all

norm:
	norminette	$(SRC)main.c \
		$(SRC)initialize.c \
		$(SRC)initialize_animations.c \
		$(SRC)initialize_map.c \
		$(SRC)initialize_objs.c \
		$(SRC)initialize_images.c \
		$(SRC)initialize_hero.c \
		$(SRC)initialize_hooks.c \
		$(SRC)initialize_tilemap.c \
		$(SRC)render_animation.c \
		$(SRC)render_scale.c \
		$(SRC)render_images.c \
		$(SRC)update_count.c \
		$(SRC)update_enemies.c \
		$(SRC)update_hero.c \
		$(SRC)update_objs.c \
		$(SRC)update_loop.c \
		$(SRC)utils_1.c \
		$(SRC)utils_2.c \
		$(SRC)utils_3.c \
		$(SRC)utils_colors.c \
		$(SRC)utils_enemies.c \
		$(SRC)so_long.h

.PHONY: all clean fclean re bonus norm