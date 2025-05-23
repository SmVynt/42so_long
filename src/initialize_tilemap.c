/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_tilemap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:30:07 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/23 03:18:20 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_tileset(t_gs *game)
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

void	ft_init_set(char *path, t_texture *texture, t_gs *game)
{
	int	i;
	int	count;

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

static void	ft_place_decor(t_gs *game, t_texture *tex,
		t_vec coords, t_vec range)
{
	int	num;
	int	max;

	max = TS - game->textures.decor_8[0].w;
	num = ft_random(range.x, range.y);
	ft_cover_images(&game->img.bg, &tex[num],
		mk_vec(coords.x + ft_random(0, max),
			coords.y + ft_random(0, max)),
		ft_random(0, 1));
}

static void	ft_add_decor(t_gs *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.w)
	{
		j = -1;
		while (++j < game->map.h)
		{
			if (game->map.tile[i][j] == C_W)
			{
				ft_place_decor(game, game->textures.decor_8,
					mk_vec(i * TS, j * TS), mk_vec(8, 15));
			}
			if (game->map.tile[i][j] == C_E)
			{
				ft_place_decor(game, game->textures.decor_8,
					mk_vec(i * TS, j * TS), mk_vec(0, 7));
				if (ft_random(0, 3) == 0)
					ft_place_decor(game, game->textures.decor_8,
						mk_vec(i * TS, j * TS), mk_vec(0, 3));
			}
		}
	}
}

void	ft_fill_tilemap(t_gs *game)
{
	int	x;
	int	y;
	int	fill;

	ft_printf(COLOR_Y "Genarating map.\n" COLOR_X);
	y = 0;
	while (y < game->map.h - 1)
	{
		x = 0;
		while (x < game->map.w - 1)
		{
			fill = 0;
			fill += (game->map.tile[x][y] == C_W) * 1;
			fill += (game->map.tile[x + 1][y] == C_W) * 2;
			fill += (game->map.tile[x][y + 1] == C_W) * 4;
			fill += (game->map.tile[x + 1][y + 1] == C_W) * 8;
			ft_override_images(&game->img.bg, &game->textures.tiles[fill],
				mk_vec(x * TS + TS / 2, y * TS + TS / 2), 0);
			x++;
		}
		y++;
	}
	ft_add_decor(game);
	ft_printf(COLOR_G "Map generated\n" COLOR_X);
	ft_printf(COLOR_Y "Starting.\n" COLOR_X);
}
