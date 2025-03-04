/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:14:33 by mait-you          #+#    #+#             */
/*   Updated: 2025/03/04 09:26:13 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
	return (0);
}

static int	ft_put_image_to_window(t_game *game, char c, int x, int y)
{
	if (c == '0' || c == 'C' || c == 'P' || c == 'X')
		mlx_put_image_to_window
		(game->mlx_ptr, game->win_ptr, game->map->_0_img,
			BLOCK * x, BLOCK * y);
	if (c == '1')
		mlx_put_image_to_window
		(game->mlx_ptr, game->win_ptr, game->map->_1_img,
			BLOCK * x, BLOCK * y);
	if (c == 'C')
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr,
			game->coin->coins_frames[game->coin->current_frame],
			BLOCK * x, BLOCK * y
			);
	if (c == 'E')
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr,
			game->exit->exit_frames[game->exit->current_frame],
			BLOCK * x, BLOCK * y
			);
	return (0);
}

static int	load_player(t_game *game, int frame)
{
	if (game->player->current_pos == 'D')
		mlx_put_image_to_window
			(game->mlx_ptr, game->win_ptr,
			game->player->player_go_down_frames[frame],
			game->player->x_pos * BLOCK, game->player->y_pos * BLOCK);
	if (game->player->current_pos == 'R')
		mlx_put_image_to_window
			(game->mlx_ptr, game->win_ptr,
			game->player->player_go_right_frames[frame],
			game->player->x_pos * BLOCK, game->player->y_pos * BLOCK);
	if (game->player->current_pos == 'L')
		mlx_put_image_to_window
			(game->mlx_ptr, game->win_ptr,
			game->player->player_go_left_frames[frame],
			game->player->x_pos * BLOCK, game->player->y_pos * BLOCK);
	if (game->player->current_pos == 'U')
		mlx_put_image_to_window
			(game->mlx_ptr, game->win_ptr,
			game->player->player_go_up_frames[frame],
			game->player->x_pos * BLOCK, game->player->y_pos * BLOCK);
	return (0);
}

static void	render_enemies(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->enemy_count)
	{
		if (game->enemys_frames[game->enemy_current_frame] && game->enemies[i])
			mlx_put_image_to_window(
				game->mlx_ptr,
				game->win_ptr,
				game->enemys_frames[game->enemy_current_frame],
				game->enemies[i]->x_pos * BLOCK,
				game->enemies[i]->y_pos * BLOCK
				);
		i++;
	}
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
	load_player(game, game->player->current_frame);
	load_text(game);
	ft_texturnbr(game, game->player->moves, 6);
	render_enemies(game);
	return (0);
}
