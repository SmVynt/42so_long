# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 16:14:14 by psmolin           #+#    #+#              #
#    Updated: 2025/04/23 22:18:46 by psmolin          ###   ########.fr        #
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
		checkmap.c \
		initialize.c \
		hooks.c \
		utils_1.c \
		main.c
OBJS = $(SRCS:.c=.o)
#
MLX_FOLDER = mlx/
MLX_LIB = $(MLX_FOLDER)libmlx.a
MLX_FLAGS = -Lmlx -lmlx -framework openGL -framework AppKit
#
LIBFT_FOLDER = libft/
LIBFT_LIB = $(LIBFT_FOLDER)libft.a
#
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: makeadd $(NAME)

makeadd:
	$(MK) $(MLX_FOLDER) all
	$(MK) $(LIBFT_FOLDER) all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)

clean:
	$(MK) $(MLX_FOLDER) clean
	$(MK) $(LIBFT_FOLDER) clean
	$(RM) $(OBJS)

fclean: clean
	$(MK) $(MLX_FOLDER) fclean

	$(RM) $(NAME)

re: fclean all

bonus: all

norm:
	norminette main.c checkmap.c \
	initialize.c hooks.c utils_1.c so_long.h 

.PHONY: all clean fclean re bonus norm