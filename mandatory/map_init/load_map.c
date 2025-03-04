/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:14:33 by mait-you          #+#    #+#             */
/*   Updated: 2025/03/04 09:10:15 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_put_image_to_window(t_game *game, char c, int x, int y)
{
	if (c == '0' || c == 'C' || c == 'P')
		mlx_put_image_to_window
		(game->mlx_ptr, game->win_ptr, game->map->_0_img, BLOCK * x, BLOCK * y);
	if (c == '1')
		mlx_put_image_to_window
		(game->mlx_ptr, game->win_ptr, game->map->_1_img, BLOCK * x, BLOCK * y);
	if (c == 'C')
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr,
			game->coins_frames,
			BLOCK * x,
			BLOCK * y
			);
	if (c == 'E')
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr,
			game->exit_frames,
			BLOCK * x,
			BLOCK * y
			);
	return (0);
}

static int	load_player(t_game *game)
{
	mlx_put_image_to_window
		(game->mlx_ptr, game->win_ptr,
		game->player->player_frames,
		game->player->x_pos * BLOCK,
		game->player->y_pos * BLOCK);
	return (0);
}

int	load_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->map_row)
	{
		x = 0;
		while (x < game->map->map_col)
		{
			ft_put_image_to_window(game, game->map->map_str[y][x], x, y);
			x++;
		}
		y++;
	}
	load_player(game);
	return (0);
}
