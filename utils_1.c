/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:19:27 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/08 20:47:38 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_exit(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	exit(EXIT_FAILURE);
}

int	ft_exit_game(t_gamestate *game)
{
	exit(0);
	return (game->steps);
}

static void	ft_check_neighbour(t_map *map, int i, int j, char start)
{
	if (!(map->tile[i][j] == '1' || map->tile[i][j] == start))
	{
		map->tile[i][j] = start;
		map->checked = 0;
	}
}

void	ft_flood_fill(t_map *map, char start)
{
	int	i;
	int	j;

	map->checked = 0;
	while (map->checked == 0)
	{
		map->checked = 1;
		i = 0;
		while (++i < map->w - 1)
		{
			j = 0;
			while (++j < map->h - 1)
			{
				if (map->tile[i][j] == start)
				{
					ft_check_neighbour(map, i + 1, j, start);
					ft_check_neighbour(map, i - 1, j, start);
					ft_check_neighbour(map, i, j + 1, start);
					ft_check_neighbour(map, i, j - 1, start);
				}
			}
		}
	}
}
