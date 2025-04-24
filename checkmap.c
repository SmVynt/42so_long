/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:04:28 by psmolin           #+#    #+#             */
/*   Updated: 2025/04/23 21:17:39 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_bounds(t_gamestate *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.width)
	{
		if (game->map.tile[x][0] != '1'
			|| game->map.tile[x][game->map.height - 1] != '1')
			ft_exit("Error\nMap is not surrounded by walls\n");
		x++;
	}
	y = 0;
	while (y < game->map.height)
	{
		if (game->map.tile[0][y] != '1'
			|| game->map.tile[game->map.width - 1][y] != '1')
			ft_exit("Error\nMap is not surrounded by walls\n");
		y++;
	}
}

static void	ft_check_characters(t_gamestate *game)
{
	int	i;
	int	j;

	game->c_collectibles = 0;
	game->c_exit = 0;
	game->c_start = 0;
	i = -1;
	while (++i < game->map.width)
	{
		j = -1;
		while (++j < game->map.height)
		{
			if (game->map.tile[i][j] == 'C')
				game->c_collectibles++;
			else if (game->map.tile[i][j] == 'E')
				game->c_exit++;
			else if (game->map.tile[i][j] == 'P')
				game->c_start++;
			else if (game->map.tile[i][j] != '1' && game->map.tile[i][j] != '0')
				ft_exit("Error\nInvalid character in map\n");
		}
	}
}

static void	ft_check_count(t_gamestate *game)
{
	if (game->c_collectibles < 1)
		ft_exit("Error\nNo collectibles in map\n");
	if (game->c_exit != 1)
		ft_exit("Error\nThere must be exactly one exit\n");
	if (game->c_start != 1)
		ft_exit("Error\nThere must be exactly one start position\n");
}

static void	ft_check_reach(t_gamestate *game)
{
	t_map	map_reach;
	int		i;
	int		j;

	i = -1;
	while (++i < game->map.width)
	{
		j = -1;
		while (++j < game->map.height)
			map_reach.tile[i][j] = game->map.tile[i][j];
	}
	map_reach.width = game->map.width;
	map_reach.height = game->map.height;
	printf("Map reachability initialized\n");
	ft_flood_fill(&map_reach, 'P');
	printf("Map reachability filled\n");
	j = -1;
	while (++j < game->map.height)
	{
		i = -1;
		while (++i < game->map.width)
		{
			if (map_reach.tile[i][j] == 'C' || map_reach.tile[i][j] == 'E')
				ft_exit("Error\nMap is not reachable\n");
		}
	}
}

void	ft_check_map(t_gamestate *game)
{
	if (game->map.width < 3 || game->map.height < 3)
		ft_exit("Error\nMap is too small\n");
	ft_check_bounds(game);
	printf("Map bounds checked\n");
	ft_check_characters(game);
	printf("Map characters checked\n");
	ft_check_count(game);
	printf("Map counts checked\n");
	ft_check_reach(game);
	printf("Map reachability checked\n");
}
