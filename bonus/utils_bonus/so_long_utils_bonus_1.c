/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:14:33 by mait-you          #+#    #+#             */
/*   Updated: 2025/03/03 17:17:52 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	enemy_initialize(t_game *game, int index, int x, int y)
{
	game->enemies[index] = (t_enemy *)ft_calloc(1, sizeof(t_enemy));
	if (!game->enemies[index])
		error_cleanup(game, "alloction failed");
	game->enemies[index]->direction = 1;
	game->enemies[index]->patrol_range = 5;
	game->enemies[index]->x_pos = x;
	game->enemies[index]->y_pos = y;
	game->enemies[index]->initial_x = x;
	return (0);
}

static int	enemies_initialize(t_game *game)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	while (game->map->map_str[y])
	{
		x = 0;
		while (game->map->map_str[y][x])
		{
			if (game->map->map_str[y][x] == 'X')
				enemy_initialize(game, i++, x, y);
			x++;
		}
		y++;
	}
	return (0);
}

int	get_enemy(t_game *game)
{
	game->enemies
		= (t_enemy **)ft_calloc(game->enemy_count + 1, sizeof(t_enemy));
	if (!game->enemies)
		error_cleanup(game, "alloction failed");
	enemies_initialize(game);
	return (0);
}

int	get_player_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map->map_str[y])
	{
		x = 0;
		while (game->map->map_str[y][x])
		{
			if (game->map->map_str[y][x] == 'P')
			{
				game->player->y_pos = y;
				game->player->x_pos = x;
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	is_player_lose_or_win(t_game *game)
{
	int	i;

	i = 0;
	if (game->map->map_str[game->player->y_pos][game->player->x_pos] == 'E'
		&& game->player->player_coins == game->coin->coin_count)
		return (1);
	while (i < game->enemy_count)
	{
		if (game->player->y_pos == game->enemies[i]->y_pos
			&& game->player->x_pos == game->enemies[i]->x_pos)
			return (-1);
		i++;
	}
	return (0);
}
