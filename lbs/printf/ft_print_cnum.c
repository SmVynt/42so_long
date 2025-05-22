/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cnum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:24:21 by psmolin           #+#    #+#             */
/*   Updated: 2025/03/26 01:59:31 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Fill the string with number.
 * 
 * Simple function to follow NORM.
 **/
static void	ft_fillnumber(long long num, char *str,
		t_str str_dat, t_command command)
{
	long long	number;

	number = num;
	if (num < 0)
		number = -number;
	while (str_dat.len > 0)
	{
		str[--str_dat.end] = (unsigned char)(number % 10) + '0';
		number = number / 10;
		str_dat.len--;
	}
	if (command.f_minus || (command.f_zero == 1 && command.f_dot == 0))
		str_dat.end = 0;
	if (num >= 0 && command.f_plus)
		str[str_dat.end] = '+';
	if (num >= 0 && command.f_space)
		str[str_dat.end] = ' ';
	if (num < 0)
		str[str_dat.end] = '-';
}

/**
 * @brief Print Command "Integer".
 * 
 * Function that prints out the int with set flags.
 * 
 * @param num The number which we're printing.
 * @param command A set of flags, width and a format.
 * @return Returns generated string length.
 **/
int	ft_print_cnum(long long num, t_command command)
{
	char	*str;
	t_str	str_dat;

	num = (long)num;
	str_dat.len = ft_numsize(num, 10);
	if (str_dat.len < command.precision)
		str_dat.len = command.precision;
	str_dat.len *= 1 - (num == 0 && command.precision == 0 && command.f_dot);
	if (((command.f_plus || command.f_space) && num >= 0) || num < 0)
		str_dat.len++;
	if (command.width < str_dat.len)
		command.width = str_dat.len;
	str_dat.end = command.f_minus * str_dat.len
		+ (1 - command.f_minus) * command.width;
	str = (char *)malloc(command.width + 1);
	if (!str)
		return (set_error(-1), -1);
	ft_memset(str, ' ', command.width);
	if (command.f_zero == 1 && command.f_minus == 0 && command.f_dot == 0)
		ft_memset(str, '0', command.width);
	ft_fillnumber(num, str, str_dat, command);
	ft_printnstr(str, command.width);
	free (str);
	return (command.width);
}

/**
 * @brief Print Command "Unsigned".
 * 
 * Function that prints out the int with set flags.
 * 
 * @param num The number which we're printing.
 * @param command A set of flags, width and a format.
 * @return Returns generated string length.
 **/
int	ft_print_cunum(long long num, t_command command)
{
	char	*str;
	t_str	str_dat;

	num = (unsigned int)num;
	str_dat.len = ft_numsize(num, 10);
	if (str_dat.len < command.precision)
		str_dat.len = command.precision;
	str_dat.len *= 1 - (num == 0 && command.precision == 0 && command.f_dot);
	if (((command.f_plus || command.f_space) && num >= 0) || num < 0)
		str_dat.len++;
	if (command.width < str_dat.len)
		command.width = str_dat.len;
	str_dat.end = command.f_minus * str_dat.len
		+ (1 - command.f_minus) * command.width;
	str = (char *)malloc(command.width + 1);
	if (!str)
		return (set_error(-1), -1);
	ft_memset(str, ' ', command.width);
	if (command.f_zero == 1 && command.f_minus == 0 && command.f_dot == 0)
		ft_memset(str, '0', command.width);
	ft_fillnumber(num, str, str_dat, command);
	ft_printnstr(str, command.width);
	free (str);
	return (command.width);
}
