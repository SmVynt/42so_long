# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 16:14:14 by psmolin           #+#    #+#              #
#    Updated: 2025/04/22 21:50:24 by psmolin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
NAME = libft.a
#
SRCS = \
		ft_atoi.c \
		ft_calloc.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strhay.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_strnstr.c
OBJS = $(SRCS:.c=.o)
#
HEADERS = libft.h
#
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I.
#
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
#
all: $(NAME)
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
#
clean:
	$(RM) $(OBJS)
#
fclean: clean
	$(RM) $(NAME)
#
re: fclean all
#
.PHONY: all clean fclean re