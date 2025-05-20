/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_objs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolin <psmolin@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 00:45:54 by psmolin           #+#    #+#             */
/*   Updated: 2025/05/20 22:43:05 by psmolin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_update_objs(t_gamestate *game)
{
	int			i;
	t_collect	*col;

	i = 0;
	while (i < game->c.collectibles)
	{
		col = &game->collects[i];
		if (game->state == STATE_CALC && col->active == 1
			&& col->x / TS == game->hero.x_next
			&& col->y / TS == game->hero.y_next)
		{
			col->active = 0;
			game->collected++;
			col->anim.current = &col->anim.idle2;
			if (game->collected == game->c.collectibles)
			{
				game->exit.anim.current = &game->exit.anim.change;
				game->exit.active = 1;
			}
		}
		ft_next_frame_to_img(&game->img.decor, col->anim.current,
			mk_vec(col->x, col->y - 4), 0);
		i++;
	}
	ft_next_frame_to_img_cover(&game->img.decor, game->exit.anim.current,
		mk_vec(game->exit.x, game->exit.y), 0);
}

void	ft_update_exit(t_gamestate *game)
{
	t_exit	*exit;

	exit = &game->exit;
	if (game->state == STATE_CALC && exit->active == 1
		&& exit->x / TS == game->hero.x_next
		&& exit->y / TS == game->hero.y_next)
	{
		ft_exit_game(game);
	}
	ft_next_frame_to_img_cover(&game->img.decor, game->exit.anim.current,
		mk_vec(game->exit.x, game->exit.y), 0);
}
