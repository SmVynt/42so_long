/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:21:52 by psmolin           #+#    #+#             */
/*   Updated: 2025/03/19 12:03:53 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Filling memory with c value.
 * 
 * @param s Memory address.
 * @param c Value to be filled with.
 * @param n Size in bytes to be filled.
 **/
void	ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		*str = (unsigned char)c;
		str++;
	}
}

/**
 * @brief String lenth.
 **/
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * @brief Find the position of character in the string.
 * 
 * @return Position. -1 if not found.
 **/
int	ft_char_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

/**
 * @brief Calculates the length of the number.
 * 
 * Function that calculates the length of a number
 * with a given Base. The result ignores minus sign.
 * 
 * @param num Initial number.
 * @param base Base of conversion.
 * @return Returns length in size_t.
 **/
size_t	ft_numsize(long long num, int base)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / base;
	}
	return (len);
}

/**
 * @brief Returns the hex value.
 * 
 * Function that convert values [0,15] -> [0,f].
 * Values that are bigger than 15 will result in f.
 * It's possile to use uppercase.
 * 
 * @param a The value, that we're converting.
 * @param uppercase 0:10 -> 'a' 1:10 -> 'A'.
 * @return Returns hex value.
 **/
char	ft_single_hex(unsigned long a, int uppercase)
{
	char	*hex;

	if (uppercase == 0)
		hex = "0123456789abcdef";
	if (uppercase == 1)
		hex = "0123456789ABCDEF";
	if (a > 15)
		a = 15;
	return (hex[a]);
}
