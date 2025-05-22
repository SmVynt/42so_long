/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:23:36 by psmolin           #+#    #+#             */
/*   Updated: 2025/03/18 21:58:46 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Print Command "String".
 * 
 * Function that prints out the string with set flags.
 * 
 * @param str The string itself that we'll print.
 * @param command A set of flags, width and a format.
 * @return Returns generated string length.
 **/
int	ft_print_cstr(char *str, t_command command)
{
	size_t	i;
	int		space_count;
	size_t	str_len;

	str_len = ft_strlen(str);
	if (command.f_dot == 1 && command.precision < str_len)
		str_len = command.precision;
	space_count = command.width - str_len;
	if (command.f_minus == 0)
		ft_printnchar(' ', space_count);
	i = 0;
	while (i++ < str_len)
		ft_printachar(str[i - 1]);
	if (command.f_minus == 1)
		ft_printnchar(' ', space_count);
	if (command.width < str_len)
		return (str_len);
	return (command.width);
}
