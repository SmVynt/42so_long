/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:30:07 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/23 03:16:37 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

void	ft_init_image(char *path, t_texture *texture, t_gs *game)
{
	ft_printf(COLOR_W "Loading %s " COLOR_X, path);
	texture->src = mlx_load_png(path);
	if (!texture->src)
		ft_exit_error("Could not load that image\n", game);
	texture->w = (int)texture->src->width;
	texture->h = (int)texture->src->height;
	ft_printf(COLOR_G "Loaded\n" COLOR_X);
}

void	ft_init_texture(t_texture *texture, t_gs *game, int w, int h,
		uint8_t clear_a)
{
	size_t	i;
	size_t	total;

	texture->src = malloc(sizeof(mlx_texture_t));
	if (!texture->src)
		ft_exit_error("Could not create new texture\n", game);
	texture->src->width = (uint32_t)w;
	texture->src->height = (uint32_t)h;
	texture->src->bytes_per_pixel = 4;
	texture->src->pixels = malloc((size_t)w * (size_t)h * 4);
	if (!texture->src->pixels)
	{
		free(texture->src);
		texture->src = NULL;
		ft_exit_error("Could not create new texture\n", game);
	}
	total = (size_t)w * (size_t)h * 4;
	memset(texture->src->pixels, 0, total);
	i = 0;
	while (i < total)
	{
		texture->src->pixels[i + 3] = clear_a;
		i += 4;
	}
	texture->w = w;
	texture->h = h;
}

void	ft_init_images(t_gs *game)
{
	t_vec	s;
	size_t	i;
	size_t	total;

	s.x = game->map.w * TS;
	s.y = game->map.h * TS;
	ft_printf(COLOR_Y "Loading images.\n" COLOR_X);
	ft_init_texture(&game->img.render, game, s.x * SCALE, s.y * SCALE, 255);
	ft_init_texture(&game->img.bg, game, s.x, s.y, 255);
	ft_init_texture(&game->img.decor, game, s.x, s.y, 0);
	ft_init_texture(&game->img.en, game, s.x, s.y, 0);
	ft_init_texture(&game->img.fg, game, s.x, s.y, 0);
	ft_init_texture(&game->img.render_sm, game, s.x, s.y, 255);
	ft_init_image(PATH_ERASOR, &game->textures.erasor, game);
	ft_init_tileset(game);
	ft_init_set(PATH_DECOR_8, game->textures.decor_8, game, 16);
	ft_init_set(PATH_DECOR_16, game->textures.decor_16, game, 16);
	ft_init_set(PATH_DIGITS, game->textures.digits, game, 10);
	ft_init_image(PATH_SCREEN_WON, &game->textures.screen_won, game);
	ft_init_image(PATH_SCREEN_LOST, &game->textures.screen_lost, game);
	ft_init_animations(game);
	game->screen = mlx_new_image(game->mlx, (uint32_t)game->img.render.w,
			(uint32_t)game->img.render.h);
	if (!game->screen)
		ft_exit_error("Could not create window image\n", game);
	if (mlx_image_to_window(game->mlx, game->screen, 0, 0) < 0)
		ft_exit_error("Could not attach image to window\n", game);
	total = (size_t)game->img.render.w * (size_t)game->img.render.h * 4;
	memset(game->screen->pixels, 0, total);
	i = 0;
	while (i < total)
	{
		game->screen->pixels[i + 3] = 255;
		i += 4;
	}
}

static void	ft_free_tex(t_texture *t)
{
	if (!t || !t->src)
		return ;
	mlx_delete_texture(t->src);
	t->src = NULL;
}

static void	ft_free_tex_arr(t_texture *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_free_tex(&arr[i]);
		i++;
	}
}

void	ft_destroy_game_textures(t_gs *game)
{
	ft_free_tex(&game->img.bg);
	ft_free_tex(&game->img.decor);
	ft_free_tex(&game->img.en);
	ft_free_tex(&game->img.fg);
	ft_free_tex(&game->img.render_sm);
	ft_free_tex(&game->img.render);
	ft_free_tex(&game->textures.tileset);
	ft_free_tex_arr(game->textures.tiles, 16);
	ft_free_tex_arr(game->textures.hero_idle, 4);
	ft_free_tex_arr(game->textures.hero_move, 4);
	ft_free_tex_arr(game->textures.hero_death, 4);
	ft_free_tex_arr(game->textures.enemy_idle, 4);
	ft_free_tex_arr(game->textures.enemy_move, 4);
	ft_free_tex_arr(game->textures.enemy_death, 4);
	ft_free_tex_arr(game->textures.coll_idle, 4);
	ft_free_tex_arr(game->textures.coll_take, 4);
	ft_free_tex_arr(game->textures.coll_idle2, 4);
	ft_free_tex_arr(game->textures.exit_idle, 4);
	ft_free_tex_arr(game->textures.exit_open, 5);
	ft_free_tex_arr(game->textures.exit_idle2, 4);
	ft_free_tex(&game->textures.erasor);
	ft_free_tex(&game->textures.erasor_sm);
	ft_free_tex_arr(game->textures.decor_8, 16);
	ft_free_tex_arr(game->textures.decor_16, 16);
	ft_free_tex_arr(game->textures.digits, 10);
	ft_free_tex(&game->textures.screen_won);
	ft_free_tex(&game->textures.screen_lost);
	ft_free_tex(&game->textures.temp);
}
