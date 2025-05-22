/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:23:36 by psmolin           #+#    #+#             */
/*   Updated: 2025/03/26 01:26:21 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Print Command "Character".
 * 
 * Function that prints out the character with set flags.
 * Can use flags: -,width.
 * 
 * @param c The character itself that we'll print.
 * @param command A set of flags, width and a format.
 * @return Returns generated string length.
 **/
int	ft_print_cc(int c, t_command command)
{
	int	space_count;

	space_count = command.width - 1;
	if (command.f_minus == 0)
		ft_printnchar(' ', space_count);
	ft_printachar(c);
	if (command.f_minus == 1)
		ft_printnchar(' ', space_count);
	if (*error_status() == -1)
		return (-1);
	if (command.width == 0)
		return (1);
	return (command.width);
}
