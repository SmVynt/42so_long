/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_animations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:30:07 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/13 00:05:00 by psmolin          ###   ########.fr       */
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
	i = -1;
	while (++i < game->c.enemies)
	{
		game->enemies[i].anim.idle = game->enemies[0].anim.idle;
		game->enemies[i].anim.move = game->enemies[0].anim.move;
		game->enemies[i].anim.current = &game->enemies[i].anim.idle;
	}
	game->hero.anim.current = &game->hero.anim.idle;
}
