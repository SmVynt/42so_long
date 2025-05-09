/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_tiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:30:07 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/09 02:14:02 by psmolin          ###   ########.fr       */
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
				mk_vec(x * TILE_S + TILE_S / 2, y * TILE_S + TILE_S / 2), 0);
			printf("%d", fill);
			x++;
		}
		printf("\n");
		y++;
	}
}
