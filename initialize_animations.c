/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_animations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:30:07 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/20 21:17:11 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_animations(t_gamestate *game)
{
	int	i;

	ft_init_animation(PATH_HERO_IDLE, game->textures.hero_idle,
		&game->hero.anim.idle, game);
	ft_init_animation(PATH_HERO_MOVE, game->textures.hero_move,
		&game->hero.anim.move, game);
	ft_init_animation(PATH_ENEMY_IDLE, game->textures.enemy_idle,
		&game->enemies[0].anim.idle, game);
	ft_init_animation(PATH_ENEMY_MOVE, game->textures.enemy_move,
		&game->enemies[0].anim.move, game);
	printf("Loading 0\n");
	ft_init_animation(PATH_EXIT_C, game->textures.exit_idle,
		&game->exit.anim.idle, game);
	printf("Loading 1\n");
	ft_init_animation(PATH_EXIT_O, game->textures.exit_idle2,
		&game->exit.anim.idle2, game);
	printf("Loading 2\n");
	ft_init_animation(PATH_EXIT_OP, game->textures.exit_open,
		&game->exit.anim.change, game);
	game->exit.anim.current = &game->exit.anim.idle;
	printf("Loading 3\n");
	ft_init_animation(PATH_CRYSTAL, game->textures.coll_idle,
		&game->collects[0].anim.idle, game);
	printf("Loading 4\n");
	ft_init_animation(PATH_CRYSTAL_TAKE, game->textures.coll_idle2,
		&game->collects[0].anim.idle2, game);
	printf("Loading enemies\n");
	i = -1;
	while (++i < game->c.enemies)
	{
		game->enemies[i].anim.idle = game->enemies[0].anim.idle;
		game->enemies[i].anim.move = game->enemies[0].anim.move;
		game->enemies[i].anim.current = &game->enemies[i].anim.idle;
	}
	printf("Loading collecs\n");
	i = -1;
	while (++i < game->c.collectibles)
	{
		game->collects[i].anim.idle = game->collects[0].anim.idle;
		game->collects[i].anim.idle2 = game->collects[0].anim.idle2;
		game->collects[i].anim.current = &game->collects[i].anim.idle;
	}
	printf("Loaded....\n");
	game->hero.anim.current = &game->hero.anim.idle;
}
