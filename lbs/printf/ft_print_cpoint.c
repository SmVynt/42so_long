/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cpoint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:24:21 by psmolin           #+#    #+#             */
/*   Updated: 2025/03/18 21:58:29 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Print Command "Pointer".
 * 
 * Function that prints out the pointer with set flags.
 * 
 * @param ptr The void pointer which address we're printing.
 * @param command A set of flags, width and a format.
 * @return Returns generated string length.
 **/
int	ft_print_cpoint(void *ptr, t_command command)
{
	unsigned int	str_start;
	unsigned long	address;
	char			str[19];

	str[18] = '\0';
	str_start = 18;
	address = (unsigned long)ptr;
	if (address == 0)
		str[--str_start] = '0';
	while (address > 0)
	{
		str[--str_start] = ft_single_hex(address % 16, 0);
		address = address / 16;
	}
	str[--str_start] = 'x';
	str[--str_start] = '0';
	if (command.width < (18 - str_start))
		command.width = 0;
	command.f_dot = 0;
	return (ft_print_cstr(&str[str_start], command));
}
