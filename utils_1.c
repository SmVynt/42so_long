/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:19:27 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/20 19:35:06 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit_error(char *str)
{
	write(1, "Error\n", 6);
	perror(str);
	exit(EXIT_FAILURE);
}

void	ft_exit(char *str)
{
	write(1, "Error\n", 6);
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	exit(EXIT_FAILURE);
}

int	ft_exit_game(t_gamestate *game)
{
	if (game->mlx)
	{
		mlx_destroy_window(game->mlx, game->window);
		free(game->mlx);
	}
	if (game->enemies)
		free(game->enemies);
	// if (game->collects)
	// 	free(game->collects);

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
