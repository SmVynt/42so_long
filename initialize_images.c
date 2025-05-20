/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:30:07 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/21 00:12:12 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_image(char *path, t_texture *texture, t_gamestate *game)
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

void	ft_init_texture(t_texture *texture, t_gamestate *game,
		int w, int h)
{
	texture->w = w;
	texture->h = h;
	texture->src = mlx_new_image(game->mlx, w, h);
	if (!texture->src)
		ft_exit_error("Error\nCould not create new texture\n");
}

void	ft_init_images(t_gamestate *game)
{
	t_vec	s;

	s.x = game->map.w * TS;
	s.y = game->map.h * TS;
	ft_init_texture(&game->img.render, game, s.x * SCALE, s.y * SCALE);
	ft_init_texture(&game->img.bg, game, s.x, s.y);
	ft_init_texture(&game->img.decor, game, s.x, s.y);
	ft_init_texture(&game->img.en, game, s.x, s.y);
	ft_init_texture(&game->img.fg, game, s.x, s.y);
	ft_init_texture(&game->img.render_sm, game, s.x, s.y);
	ft_init_image(PATH_ERASOR, &game->textures.erasor, game);
	ft_init_tileset(game);
	ft_init_set(PATH_DECOR_8, game->textures.decor_8, game);
	ft_init_set(PATH_DECOR_16, game->textures.decor_16, game);
	ft_init_set(PATH_DIGITS, game->textures.digits, game);
	ft_init_animations(game);
}
