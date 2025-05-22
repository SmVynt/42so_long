/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:21:52 by psmolin           #+#    #+#             */
/*   Updated: 2025/03/19 12:26:41 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/**
 * @brief Prints one character...
 * 
 **/
int	ft_printachar(char c)
{
	ssize_t	error;

	if (*error_status() != -1)
	{
		error = write(1, &c, 1);
		if (error == -1)
		{
			set_error(error);
			return (-1);
		}
	}
	return (1);
}

/**
 * @brief Prints one character n times.
 * 
 * @param c The character.
 * @param n Number of times.
 **/
void	ft_printnchar(char c, int n)
{
	if (*error_status() != -1)
	{
		while (n-- > 0)
			ft_printachar(c);
	}
}

/**
 * @brief Prints a string up to a certain width.
 * 
 * @param str The string to print.
 * @param width The maximum number of characters to print.
 **/
void	ft_printnstr(char *str, size_t width)
{
	ssize_t	error;

	if (*error_status() != -1)
	{
		error = write(1, str, width);
		if (error == -1)
			set_error(error);
	}
}

/**
 * @brief Function that sets error status.
 **/
void	set_error(ssize_t error)
{
	ssize_t	*status;

	status = error_status();
	*status = error;
}

/**
 * @brief Function that stores error status
 * 
 * @return Returns a pointer to the error value.
 **/
ssize_t	*error_status(void)
{
	static ssize_t	status = 0;

	return (&status);
}
