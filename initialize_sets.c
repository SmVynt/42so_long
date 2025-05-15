/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_sets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:30:07 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/15 23:13:49 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_tileset(t_gamestate *game)
{
	int	i;
	int	w;

	i = 0;
	ft_init_image(PATH_TILES, &game->textures.tileset, game);
	w = game->textures.tileset.w;
	while (i < 16)
	{
		ft_init_texture(&game->textures.tiles[i], game, w, w);
		ft_override_images(&game->textures.tiles[i],
			&game->textures.tileset, mk_vec(0, -(i * w)), 0);
		i++;
	}
}

void	ft_init_set(char *path, t_texture *texture, t_gamestate *game)
{
	int i;
	int count;

	i = 0;
	ft_init_image(path, &game->textures.temp, game);
	count = game->textures.temp.h / game->textures.temp.w;
	while (i < count)
	{
		ft_init_texture(&texture[i], game,
			game->textures.temp.w, game->textures.temp.w);
		ft_override_images(&texture[i], &game->textures.temp,
			mk_vec(0, -(i * game->textures.temp.w)), 0);
		i++;
	}
}

static void ft_place_decor(t_gamestate *game, t_texture *tex, t_vec cords, t_vec range)
{
	int	num;
	int	b;

	b = 8;
	num = ft_random(range.x, range.y);
	ft_cover_images(&game->img.bg, &tex[num],
		mk_vec(cords.x + ft_random(b, TS - b) - 8,
		cords.y + ft_random(b, TS - b) - 8),
		ft_random(0, 1));
}

static void ft_add_decor(t_gamestate *game)
{
	int i;
	int j;

	i = -1;
	while (++i < game->map.w)
	{
		j = -1;
		while (++j < game->map.h)
		{
			if (game->map.tile[i][j] == '1')
				ft_place_decor(game, game->textures.decor_8,
					mk_vec(i * TS, j * TS), mk_vec(8, 15));
			if (game->map.tile[i][j] == '0')
			{
				ft_place_decor(game, game->textures.decor_8,
					mk_vec(i * TS, j * TS), mk_vec(0, 7));
				ft_place_decor(game, game->textures.decor_8,
					mk_vec(i * TS, j * TS), mk_vec(0, 3));
			}
		}
	}
}

void	ft_fill_tilemap(t_gamestate *game)
{
	int	x;
	int	y;
	int	fill;

	y = 0;
	while (y < game->map.h - 1)
	{
		x = 0;
		while (x < game->map.w - 1)
		{
			fill = 0;
			fill += (game->map.tile[x][y] == '1') * 1;
			fill += (game->map.tile[x + 1][y] == '1') * 2;
			fill += (game->map.tile[x][y + 1] == '1') * 4;
			fill += (game->map.tile[x + 1][y + 1] == '1') * 8;
			ft_override_images(&game->img.bg, &game->textures.tiles[fill],
				mk_vec(x * TS + TS / 2, y * TS + TS / 2), 0);
			x++;
		}
		printf("\n");
		y++;
	}
	ft_add_decor(game);
}
