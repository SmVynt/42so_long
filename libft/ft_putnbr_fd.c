/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:23:55 by psmolin           #+#    #+#             */
/*   Updated: 2025/04/04 11:06:22 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	a;
	int		sign;

	sign = 1;
	if (n < 0)
	{
		write(fd, "-", 1);
		sign *= -1;
	}
	if (n >= 10 || n <= -10)
	{
		ft_putnbr_fd((n / 10) * sign, fd);
	}
	a = (n % 10) * sign + '0';
	write(fd, &a, 1);
}
