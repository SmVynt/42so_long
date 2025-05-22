/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readcommand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:23:02 by psmolin           #+#    #+#             */
/*   Updated: 2025/03/28 16:24:19 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief Checking initial flags.
 **/
static int	ft_checkflags(char a, t_command *command)
{
	if (a == '#')
		command->f_hash = 1;
	else if (a == '0')
		command->f_zero = 1;
	else if (a == '-')
		command->f_minus = 1;
	else if (a == '+')
		command->f_plus = 1;
	else if (a == ' ')
		command->f_space = 1;
	else
		return (0);
	return (1);
}

/**
 * @brief reads number
 */
static size_t	ft_readnumber(const char *str, int *i)
{
	int		j;
	size_t	ret;

	ret = 0;
	j = *i;
	while (str[j] >= '0' && str[j] <= '9')
	{
		ret = ret * 10 + (str[j] - '0');
		j++;
	}
	j--;
	*i = j;
	return (ret);
}

/**
 * @brief Function that reads the string after % occurance.
 * 
 * It creates the Command structure that we'll use further.
 * 
 * @param str Pointer to the position next to % in the string.
 * @return Returns generated Command structure.
 **/
t_command	ft_readcommand(const char *str)
{
	int			i;
	t_command	command;

	i = 0;
	ft_memset(&command, 0, sizeof(t_command));
	while (str[i] && ft_char_in_str("-# +0123456789.", str[i]) != -1)
	{
		if (ft_checkflags(str[i], &command) == 1)
			(void)i;
		else if (str[i] == '.')
		{
			command.f_dot = 1;
			i++;
			command.precision = ft_readnumber(str, &i);
		}
		else
			command.width = ft_readnumber(str, &i);
		i++;
	}
	return (command.command = str[i], command.length = i, command);
}
