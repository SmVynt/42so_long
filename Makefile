# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 16:14:14 by psmolin           #+#    #+#              #
#    Updated: 2025/05/27 02:40:42 by psmolin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
HEADERS = $(SRC)so_long.h
CC = cc
RM = rm -f
MK = make -C
SRC = src/

MLX42_DIR := MLX42
MLX42_LIB := $(MLX42_DIR)/libmlx42.a
MLX42_REPO := https://github.com/codam-coding-college/MLX42.git

CFLAGS = -Wall -Wextra -Werror -g -I. -I$(MLX42_DIR)/include -I/opt/homebrew/include
SANFLAGS = -fsanitize=address -fno-omit-frame-pointer

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	MLXFLAGS := -L$(MLX42_DIR) -lmlx42 -lglfw -ldl -lGL -lm -pthread
endif
ifeq ($(UNAME_S),Darwin)
	MLXFLAGS := -L$(MLX42_DIR) -lmlx42 -L/opt/homebrew/lib -lglfw -framework OpenGL -framework AppKit \
		-framework AudioToolbox -framework CoreAudio -framework CoreFoundation
endif

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
		$(SRC)utils_map.c \
		$(SRC)main.c
OBJS = $(SRCS:.c=.o)
#
GNL_FOLDER = lbs/gnl/
GNL_LIB = $(GNL_FOLDER)libgnl.a
GNL_FLAGS = -L$(GNL_FOLDER) -lgnl
PRT_FOLDER = lbs/printf/
PRT_LIB = $(PRT_FOLDER)libftprintf.a
PRT_FLAGS = -L$(PRT_FOLDER) -lftprintf
#
%.o: %.c $(HEADERS) $(MLX42_LIB)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

makeadd:
	$(MK) $(GNL_FOLDER) all
	$(MK) $(PRT_FOLDER) all

$(NAME): $(OBJS) $(MLX42_LIB) makeadd
	$(CC) $(CFLAGS) $(OBJS) $(GNL_FLAGS) $(PRT_FLAGS) $(MLXFLAGS) -o $(NAME)

$(MLX42_LIB):
	@echo "Checking for MLX42..."
	@if [ ! -d "$(MLX42_DIR)" ]; then \
		echo "Cloning MLX42 into $(MLX42_DIR)..."; \
		git clone $(MLX42_REPO) $(MLX42_DIR); \
	else \
		echo "MLX42 already exists in $(MLX42_DIR). Skipping clone."; \
	fi
	@if [ ! -f "$(MLX42_LIB)" ]; then \
		echo "Building MLX42 library..."; \
		cmake -S $(MLX42_DIR) -B $(MLX42_DIR)/build; \
		cmake --build $(MLX42_DIR)/build; \
		cp $(MLX42_DIR)/build/libmlx42.a $(MLX42_DIR)/; \
	else \
		echo "MLX42 library already built."; \
	fi

clean:
	$(MK) $(GNL_FOLDER) clean
	$(MK) $(PRT_FOLDER) clean
	$(RM) $(OBJS)

fclean:
	$(MK) $(GNL_FOLDER) fclean
	$(MK) $(PRT_FOLDER) fclean
	$(RM) $(OBJS)
	$(RM) $(NAME)

re: fclean all

san: fclean
	$(MAKE) all CFLAGS="$(CFLAGS) $(SANFLAGS)"

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
		$(SRC)utils_map.c \
		$(SRC)so_long.h

.PHONY: all clean fclean re san bonus norm
