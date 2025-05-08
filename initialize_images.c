/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:30:07 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/08 14:43:25 by psmolin          ###   ########.fr       */
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

static void	ft_initialize_animation(char *path,
	t_texture *texture, t_animation *anim, t_gamestate *game)
{
	int i;
	int fc;

	i = 0;
	ft_initialize_image(path, &game->textures.temp, game);
	fc = game->textures.temp.h / game->textures.temp.w;
	while (i < fc)
	{
		ft_initialize_texture(&texture[i], game,
			game->textures.temp.w, game->textures.temp.w);
		ft_override_images(&texture[i], &game->textures.temp,
			0, -(i * game->textures.temp.w));
		i++;
	}
	anim->frame = 0;
	anim->frame_count = fc;
	anim->frame_time = FRAME_TIME;
	anim->delta = FRAME_TIME;
	anim->src = texture;
	//mlx_destroy_image(game->mlx, game->textures.temp.src);
}


static void	ft_initialize_tileset(t_gamestate *game)
{
	int	i;
	int	w;

	i = 0;
	ft_initialize_image(PATH_TILES,	&game->textures.tileset, game);
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
	ft_initialize_tileset(game);
	ft_initialize_animation(PATH_HERO_IDLE,
		game->textures.hero_idle, &game->hero.anim.idle, game);
	printf("Hero idle animation initialized\n");
}
