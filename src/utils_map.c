/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:19:27 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/23 02:27:09 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

t_map	*ft_copy_map(t_map *src)
{
	t_map	*dst;
	int		i;
	int		j;

	dst = (t_map *)malloc(sizeof(t_map));
	if (!dst)
		return (NULL);
	dst->tile = malloc(sizeof(char *) * src->w);
	if (!dst->tile)
		return (NULL);
	i = -1;
	while (++i < src->w)
	{
		dst->tile[i] = malloc(sizeof(char) * src->h);
		if (!dst->tile[i])
			return (NULL);
	}
	i = -1;
	while (++i < src->w)
	{
		j = -1;
		while (++j < src->h)
			dst->tile[i][j] = src->tile[i][j];
	}
	return (dst);
}

void	ft_allocate_map(t_map *map, t_gs *game)
{
	int	i;

	map->tile = malloc(sizeof(char *) * map->w);
	if (!map->tile)
		ft_exit("Error\nCould not allocate memory for map\n", game);
	i = -1;
	while (++i < map->w)
	{
		map->tile[i] = malloc(sizeof(char) * (map->h));
		if (!map->tile[i])
			ft_exit("Error\nCould not allocate memory for map\n", game);
	}
}

void	ft_free_map(t_map *map)
{
	int	i;

	if (map->tile)
	{
		i = -1;
		while (++i < map->w)
			free(map->tile[i]);
		free(map->tile);
	}
}
