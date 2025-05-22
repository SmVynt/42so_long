/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_hero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:04:28 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/23 00:40:02 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_hero(t_gamestate *game)
{
	int	i;
	int	j;

	game->hero.wish_x = 0;
	game->hero.wish_y = 0;
	game->hero.state = STATE_IDLE;
	game->hero.flipped = 0;
	i = -1;
	while (++i < game->map.w)
	{
		j = -1;
		while (++j < game->map.h)
		{
			if (game->map.tile[i][j] == C_P)
			{
				game->hero.x = i * TS;
				game->hero.y = j * TS;
			}
		}
	}
	game->hero.x_prev = game->hero.x / TS;
	game->hero.y_prev = game->hero.y / TS;
	game->hero.x_next = game->hero.x / TS;
	game->hero.y_next = game->hero.y / TS;
}
