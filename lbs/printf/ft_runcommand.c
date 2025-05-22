/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_runcommand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:23:02 by psmolin           #+#    #+#             */
/*   Updated: 2025/03/19 12:20:16 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Function that runs the command that we generated.
 * 
 * it runs corresponding command based on the command format.
 * 
 * @param command A set of flags, width and a format.
 * @param args Arguments from the ft_printf function.
 * @return Returns generated Command structure.
 **/
int	ft_runcommand(t_command command, va_list args)
{
	char	*str;

	if (command.command == 'c')
		return (ft_print_cc(va_arg(args, int), command));
	if (command.command == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			str = "(null)";
		return (ft_print_cstr(str, command));
	}
	if (command.command == 'd' || command.command == 'i')
		return (ft_print_cnum((long long)va_arg(args, int), command));
	if (command.command == 'u')
		return (ft_print_cunum((long long)va_arg(args, int), command));
	if (command.command == 'p')
		return (ft_print_cpoint(va_arg(args, void *), command));
	if (command.command == '%')
		return (ft_print_cc('%', command));
	if (command.command == 'x' || command.command == 'X')
		return (ft_print_chex((long long)va_arg(args, int), command));
	return (-1);
}
