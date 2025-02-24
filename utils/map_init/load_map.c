/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:14:33 by mait-you          #+#    #+#             */
/*   Updated: 2025/02/24 17:25:43 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	load_text(t_game *game)
{
	mlx_put_image_to_window
	(game->mlx_ptr, game->win_ptr, game->txt_texture[0], 0, 0);
	mlx_put_image_to_window
	(game->mlx_ptr, game->win_ptr, game->txt_texture[1], BLOCK / 2, 0);
	mlx_put_image_to_window
	(game->mlx_ptr, game->win_ptr, game->txt_texture[2], BLOCK / 2 * 2, 0);
	mlx_put_image_to_window
	(game->mlx_ptr, game->win_ptr, game->txt_texture[3], BLOCK / 2 * 3, 0);
	mlx_put_image_to_window
	(game->mlx_ptr, game->win_ptr, game->txt_texture[4], BLOCK / 2 * 4, 0);
	mlx_put_image_to_window
	(game->mlx_ptr, game->win_ptr, game->txt_texture[5], BLOCK / 2 * 5, 0);

	mlx_put_image_to_window
	(game->mlx_ptr, game->win_ptr, game->txt_texture[6],
	BLOCK * game->map->map_col - (BLOCK * 2), 0);
	return (0);
}


static int	ft_put_image_to_window(t_game *game, char c, int x, int y)
{
	if (c == '0' || c == 'C' || c == 'P' || c == 'X')
		mlx_put_image_to_window
		(game->mlx_ptr, game->win_ptr, game->map->_0_img, BLOCK * y, BLOCK * x);
	if (c == '1' )
		mlx_put_image_to_window
		(game->mlx_ptr, game->win_ptr, game->map->_1_img, BLOCK * y, BLOCK * x);
	if (c == 'C')
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr,
			game->coin->coins_frames[game->coin->current_frame],
			BLOCK * y, BLOCK * x
			);
	if (c == 'E')
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr,
			game->exit->exit_frames[game->exit->current_frame],
			BLOCK * y, BLOCK * x
			);
	if (c == 'X')
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr,
			game->enmy->enemys_frames[game->enmy->current_frame],
			BLOCK * y, BLOCK * x
			);
	return (0);
}

static int	load_player(t_game *game, int frame)
{
	if (game->player->current_pos == 'D')
		mlx_put_image_to_window
			(game->mlx_ptr, game->win_ptr,
			game->player->player_go_down_frames[frame],
			game->player->y_pos * BLOCK, game->player->x_pos * BLOCK);
	if (game->player->current_pos == 'R')
		mlx_put_image_to_window
			(game->mlx_ptr, game->win_ptr,
			game->player->player_go_right_frames[frame],
			game->player->y_pos * BLOCK, game->player->x_pos * BLOCK);
	if (game->player->current_pos == 'L')
		mlx_put_image_to_window
			(game->mlx_ptr, game->win_ptr,
			game->player->player_go_left_frames[frame],
			game->player->y_pos * BLOCK, game->player->x_pos * BLOCK);
	if (game->player->current_pos == 'U')
		mlx_put_image_to_window
			(game->mlx_ptr, game->win_ptr,
			game->player->player_go_up_frames[frame],
			game->player->y_pos * BLOCK, game->player->x_pos * BLOCK);
	return (0);
}

int	load_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map->map_row)
	{
		y = 0;
		while (y < game->map->map_col)
		{
			ft_put_image_to_window(game, game->map->map_str[x][y], x, y);
			y++;
		}
		x++;
	}
	load_player(game, game->player->current_frame);
	load_text(game);
	ft_texturnbr(game, game->player->moves, 6);
	ft_texturnbr(game, game->player->player_coins, (game->map->map_col - 3) * 2);
	ft_texturnbr(game, game->coin->coins, (game->map->map_col - 1) * 2 );
	return (0);
}
