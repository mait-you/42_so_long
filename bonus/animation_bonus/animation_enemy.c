/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_enemy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:47:26 by mait-you          #+#    #+#             */
/*   Updated: 2025/03/02 11:10:30 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	update_enemy_direction(t_game *game, int i)
{
	if (game->map->map_str[game->enemies[i]->y_pos]
		[game->enemies[i]->x_pos + game->enemies[i]->direction] == '1'
		|| game->map->map_str[game->enemies[i]->y_pos]
		[game->enemies[i]->x_pos + game->enemies[i]->direction] == 'E'
		|| ft_abs(game->enemies[i]->x_pos
			+ game->enemies[i]->direction - game->enemies[i]->initial_x)
		> game->enemies[i]->patrol_range)
	{
		game->enemies[i]->direction *= -1;
	}
}

void	update_enemies(t_game *game)
{
	int		i;

	if (game->enemy_frame_timer++ >= ANIMATION_SPEED)
	{
		i = 0;
		while (i < game->enemy_count)
		{
			update_enemy_direction(game, i);
			game->enemies[i]->x_pos += game->enemies[i]->direction;
			i++;
		}
		game->enemy_frame_timer = 0;
	}
}
