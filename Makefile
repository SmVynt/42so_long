# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 16:14:14 by psmolin           #+#    #+#              #
#    Updated: 2025/05/20 19:52:05 by psmolin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# To run the game type this:
#
NAME = so_long
HEADERS = ft_printf.h
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I.
MK = make -C
#
SRCS = \
		initialize.c \
		initialize_animations.c \
		initialize_map.c \
		initialize_objs.c \
		initialize_images.c \
		initialize_sets.c \
		initialize_hero.c \
		initialize_hooks.c \
		render_animation.c \
		render_images.c \
		render_scale.c \
		update_enemies.c \
		update_hero.c \
		update_loop.c \
		utils_1.c \
		utils_2.c \
		utils_3.c \
		utils_colors.c \
		main.c
OBJS = $(SRCS:.c=.o)
#
MLX_FOLDER = mlx/
MLX_LIB = $(MLX_FOLDER)libmlx.a
MLX_FLAGS = -Lmlx -lmlx -framework openGL -framework AppKit
#
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: makeadd $(NAME)

makeadd:
	$(MK) $(MLX_FOLDER) all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(MLX_LIB) -o $(NAME)

clean:
	$(MK) $(MLX_FOLDER) clean
	$(RM) $(OBJS)

fclean:
	$(MK) $(MLX_FOLDER) fclean
	$(RM) $(OBJS)
	$(RM) $(NAME)

re: fclean all

bonus: all

norm:
	norminette	main.c \
		initialize.c \
		initialize_animations.c \
		initialize_map.c \
		initialize_objs.c \
		initialize_images.c \
		initialize_sets.c \
		initialize_hero.c \
		initialize_hooks.c \
		render_animation.c \
		render_scale.c \
		render_images.c \
		update_enemies.c \
		update_hero.c \
		update_loop.c \
		utils_1.c \
		utils_2.c \
		utils_3.c \
		utils_colors.c \
		so_long.h

.PHONY: all clean fclean re bonus norm