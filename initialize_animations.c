/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_animations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 23:30:07 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/09 00:56:51 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_animations(t_gamestate *game)
{
	ft_init_animation(PATH_HERO_IDLE, game->textures.hero_idle,
		&game->hero.anim.idle, game);
	ft_init_animation(PATH_HERO_MOVE, game->textures.hero_move,
		&game->hero.anim.move, game);
	game->hero.anim.current = &game->hero.anim.idle;
}
