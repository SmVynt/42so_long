/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:30:07 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/01 23:15:22 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_initialize_image(char *path,
	t_texture *texture, t_gamestate *game)
{
	int	w;
	int	h;

	printf("Loading %s\n", path);
	texture->src = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	if (!texture->src)
		ft_exit_error("Error\nCould not load that image\n");
	texture->w = w;
	texture->h = h;
	printf("Image loaded\n");
}

void	ft_initialize_texture(t_texture *texture, t_gamestate *game,
		int w, int h)
{
	texture->w = w;
	texture->h = h;
	texture->src = mlx_new_image(game->mlx, w, h);
	if (!texture->src)
		ft_exit_error("Error\nCould not create new texture\n");
}

static void	ft_initialize_tileset(t_gamestate *game)
{
	int	i;
	int	w;

	i = 0;
	ft_initialize_image("./textures/bg_tileset_01.xpm",
		&game->textures.tileset, game);
	w = game->textures.tileset.w;
	while (i < 16)
	{
		ft_initialize_texture(&game->textures.tiles[i], game, w, w);
		ft_override_images(&game->textures.tiles[i],
			&game->textures.tileset, 0, -(i * w));
		i++;
	}
}

void	ft_fill_tilemap(t_gamestate *game)
{
	int	x;
	int	y;
	int	fill;

	y = 0;
	while (y < game->map.height - 1)
	{
		x = 0;
		while (x < game->map.width - 1)
		{
			fill = 0;
			fill += (game->map.tile[x][y] == '1') * 1;
			fill += (game->map.tile[x + 1][y] == '1') * 2;
			fill += (game->map.tile[x][y + 1] == '1') * 4;
			fill += (game->map.tile[x + 1][y + 1] == '1') * 8;
			ft_override_images(&game->img.bg, &game->textures.tiles[fill],
				x * TILE_SIZE + TILE_SIZE / 2, y * TILE_SIZE + TILE_SIZE / 2);
			printf("%d", fill);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	ft_initialize_images(t_gamestate *game)
{
	ft_initialize_image("./textures/bg_tile_01.xpm",
		&game->textures.bg, game);
	ft_initialize_tileset(game);
}
