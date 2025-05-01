/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:30:07 by psmolin           #+#    #+#             */
/*   Updated: 2025/04/30 03:48:26 by psmolin          ###   ########.fr       */
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

void	ft_initialize_texture(t_texture *texture, t_gamestate *game, int w, int h)
{
	texture->w = w;
	texture->h = h;
	texture->src = mlx_new_image(game->mlx, w, h);
	if (!texture->src)
		ft_exit_error("Error\nCould not create new texture\n");
}

// static void ft_initialize_frame(char *path,
// 	t_animation *anim, t_gamestate *game)
// {
// 	int		w;
// 	int		h;
// 	int 	i;

// 	i = path[ft_strlen(path) - 5] - '0';
// 	if (i < 0 || i > 9)
// 		ft_exit_error("Error\nInvalid animation frame number\n");
// 	if (i == 0 || i > anim->frame_count)
// 		anim->frame_count = i;
// 	anim->frame_time = 0;
// 	anim->cur_frame = 0;
// 	anim->textures[i].srs = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
// 	if (!anim->textures[i].srs)
// 		ft_exit_error("Error\nCould not load that image\n");
// 	anim->textures[i].w = w;
// 	anim->textures[i].h = h;
// }

void	ft_initialize_images(t_gamestate *game)
{
	ft_initialize_image("./textures/bg_tile_01.xpm",
		&game->textures.bg, game);
}
