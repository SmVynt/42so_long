/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:24:21 by psmolin           #+#    #+#             */
/*   Updated: 2025/03/26 01:58:17 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Fill the string with number.
 * 
 * Simple function to follow NORM.
 **/
static void	ft_fillhexnumber(long long num, char *str,
	t_str str_dat, t_command command)
{
	long long	number;

	number = num;
	while (str_dat.len > 0)
	{
		str[--str_dat.end] = ft_single_hex(number % 16, command.command == 'X');
		number = number / 16;
		str_dat.len--;
	}
	if (command.f_minus || (command.f_zero == 1 && command.f_dot == 0))
		str_dat.end = 0;
	if (command.f_hash && num != 0)
	{
		str[str_dat.end] = '0';
		str[str_dat.end + 1] = command.command;
	}
}

/**
 * @brief Print Command "Hex".
 * 
 * Function that prints out the pointer with set flags.
 * 
 * @param num The pointer.
 * @param command A set of flags, width and a format.
 * @return Returns generated string length.
 **/
int	ft_print_chex(long long num, t_command command)
{
	char		*str;
	t_str		str_dat;

	num = (unsigned int) num;
	str_dat.len = ft_numsize(num, 16);
	if (str_dat.len < command.precision)
		str_dat.len = command.precision;
	if (command.f_hash && num != 0)
		str_dat.len += 2;
	if (num == 0 && command.precision == 0 && command.f_dot)
		str_dat.len = 0;
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
	ft_fillhexnumber(num, str, str_dat, command);
	ft_printnstr(str, command.width);
	free (str);
	return (command.width);
}
