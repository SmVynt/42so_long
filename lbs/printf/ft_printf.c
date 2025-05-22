/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:23:02 by psmolin           #+#    #+#             */
/*   Updated: 2025/03/26 01:25:36 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Prints provided string.
 * 
 * My version of printf.
 * Can work with cspdiuxX% format.
 * Can work with theese flags:
 * -0.# + width and precision.
 * 
 * @return The length of the resulting string.
 **/
int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			len;

	len = 0;
	*error_status() = 0;
	va_start(args, str);
	len = ft_printf_sub (str, args);
	va_end(args);
	if (*error_status() != -1)
		return (len);
	return (-1);
}

int	ft_printf_sub(const char *str, va_list args)
{
	t_command	newcommand;
	int			i;
	int			len;
	int			len_add;	

	i = 0;
	len = 0;
	while (str[i] && *error_status() != -1)
	{
		if (str[i] == '%')
		{
			i++;
			newcommand = ft_readcommand(str + i);
			i += newcommand.length;
			len_add = ft_runcommand(newcommand, args);
		}
		else
			len_add = ft_printachar(str[i]);
		if (len_add == -1)
			return (-1);
		len += len_add;
		i++;
	}
	return (len);
}
