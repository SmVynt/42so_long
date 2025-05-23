/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_animations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:30:07 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/23 02:27:09 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_animation(char *path,
	t_texture *texture, t_animation *anim, t_gs *game)
{
	int	i;
	int	fc;

	i = 0;
	ft_init_image(path, &game->textures.temp, game);
	fc = game->textures.temp.h / game->textures.temp.w;
	while (i < fc)
	{
		ft_init_texture(&texture[i], game,
			game->textures.temp.w, game->textures.temp.w);
		ft_override_images(&texture[i], &game->textures.temp,
			mk_vec(0, -(i * game->textures.temp.w)), 0);
		i++;
	}
	anim->frame = 0;
	anim->frame_count = fc;
	anim->frame_time = FRAME_TIME;
	anim->delta = FRAME_TIME;
	anim->src = texture;
	anim->next = NULL;
}

static void	ft_init_enemies_animations(t_gs *game)
{
	int	i;

	ft_init_animation(PATH_ENEMY_IDLE, game->textures.enemy_idle,
		&game->enemies[0].anim.idle, game);
	ft_init_animation(PATH_ENEMY_MOVE, game->textures.enemy_move,
		&game->enemies[0].anim.move, game);
	i = -1;
	while (++i < game->c.enemies)
	{
		game->enemies[i].anim.idle = game->enemies[0].anim.idle;
		game->enemies[i].anim.move = game->enemies[0].anim.move;
		game->enemies[i].anim.current = &game->enemies[i].anim.idle;
	}
}

static void	ft_init_collectibles_animations(t_gs *game)
{
	int	i;

	ft_init_animation(PATH_CRYSTAL, game->textures.coll_idle,
		&game->collects[0].anim.idle, game);
	ft_init_animation(PATH_CRYSTAL_TAKE, game->textures.coll_idle2,
		&game->collects[0].anim.idle2, game);
	i = -1;
	while (++i < game->c.collectibles)
	{
		game->collects[i].anim.idle = game->collects[0].anim.idle;
		game->collects[i].anim.idle2 = game->collects[0].anim.idle2;
		game->collects[i].anim.current = &game->collects[i].anim.idle;
	}
}

void	ft_init_animations(t_gs *game)
{
	ft_init_animation(PATH_HERO_IDLE, game->textures.hero_idle,
		&game->hero.anim.idle, game);
	ft_init_animation(PATH_HERO_MOVE, game->textures.hero_move,
		&game->hero.anim.move, game);
	game->hero.anim.current = &game->hero.anim.idle;
	ft_init_animation(PATH_EXIT_C, game->textures.exit_idle,
		&game->exit.anim.idle, game);
	ft_init_animation(PATH_EXIT_O, game->textures.exit_idle2,
		&game->exit.anim.idle2, game);
	ft_init_animation(PATH_EXIT_OP, game->textures.exit_open,
		&game->exit.anim.change, game);
	game->exit.anim.change.next = &game->exit.anim.idle2;
	game->exit.anim.current = &game->exit.anim.idle;
	ft_init_enemies_animations(game);
	ft_init_collectibles_animations(game);
}
