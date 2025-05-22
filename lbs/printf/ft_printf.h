/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:22:29 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/22 18:35:09 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_command
{
	size_t	width;
	size_t	precision;
	char	command;
	size_t	length;
	char	f_minus;
	char	f_plus;
	char	f_zero;
	char	f_hash;
	char	f_space;
	char	f_dot;
}	t_command;

typedef struct s_str
{
	size_t	len;
	size_t	end;
}	t_str;

int			ft_printf(const char *str, ...);
int			ft_printf_sub(const char *str, va_list args);
int			ft_print_cstr(char *str, t_command command);
int			ft_print_cc(int c, t_command command);
int			ft_print_cnum(long long num, t_command command);
int			ft_print_cunum(long long num, t_command command);
int			ft_print_cpoint(void *ptr, t_command command);
int			ft_print_chex(long long num, t_command command);
int			ft_runcommand(t_command command, va_list args);
t_command	ft_readcommand(const char *str);
void		ft_memset(void *s, int c, size_t n);
int			ft_char_in_str(char *str, char c);
size_t		ft_strlen(const char *str);
size_t		ft_numsize(long long num, int base);
char		ft_single_hex(unsigned long a, int uppercase);
int			ft_printachar(char c);
void		ft_printnchar(char c, int n);
void		ft_printnstr(char *str, size_t width);
void		set_error(ssize_t error);
ssize_t		*error_status(void);

#endif