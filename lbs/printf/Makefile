# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 16:14:14 by psmolin           #+#    #+#              #
#    Updated: 2025/05/22 18:04:50 by psmolin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# To use the library use this command:
# cc main.c -L. -lftprintf -I.
#
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I.
#
NAME = libftprintf.a
SRCS = ft_printf.c \
		ft_print_cc.c \
		ft_print_cnum.c \
		ft_print_cpoint.c \
		ft_print_cstr.c \
		ft_print_chex.c \
		ft_readcommand.c \
		ft_runcommand.c \
		ft_utils.c \
		ft_utils2.c
OBJS = $(SRCS:.c=.o)
HEADERS = ft_printf.h
#
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
all: $(NAME)
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
#
.PHONY: all clean fclean re