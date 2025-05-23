/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_enemies.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 20:10:24 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/23 02:27:09 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find_next_spot(t_gs *game, t_enemy *enemy)
{
	int	i;

	enemy->x_prev = enemy->x_next;
	enemy->y_prev = enemy->y_next;
	enemy->x_next = enemy->x_dest;
	enemy->y_next = enemy->y_dest;
	if (enemy->x_dest > enemy->x / TS)
		enemy->x_next = enemy->x / TS + 1;
	if (enemy->x_dest < enemy->x / TS)
		enemy->x_next = enemy->x / TS - 1;
	if (enemy->y_dest > enemy->y / TS)
		enemy->y_next = enemy->y / TS + 1;
	if (enemy->y_dest < enemy->y / TS)
		enemy->y_next = enemy->y / TS - 1;
	i = -1;
	while (++i < game->c.enemies)
	{
		if (game->enemies[i].x_next == enemy->x_next
			&& game->enemies[i].y_next == enemy->y_next
			&& &game->enemies[i] != enemy)
		{
			enemy->x_next = enemy->x_prev;
			enemy->y_next = enemy->y_prev;
		}
	}
}
