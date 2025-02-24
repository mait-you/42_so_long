/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:24:49 by mait-you          #+#    #+#             */
/*   Updated: 2025/02/24 17:39:26 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	update_game(t_game *game)
{
	if (game->map && game->map->map_str[game->player->x_pos][game->player->y_pos] == 'X')
		return (player_lose(game), 1);
	if (game->map && game->map->map_str[game->player->x_pos][game->player->y_pos] == 'E'
	&& game->player->player_coins == game->coin->coins)
		return (player_win(game), 1);
	update_animation(game);
	load_map(game);
	return (0);
}

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		exit_prog(game, 0);
	control_moves
	(keysym, game, game->player->x_pos, game->player->y_pos);
	return (0);
}

int handle_exit(t_game *game)
{
	exit_prog(game, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_game		*game;

	chek_args(ac, av[1]);
	game = game_initialize(av[1]);
	imgs_initialize(game);
	mlx_hook(
		game->win_ptr,
		KeyPress,
		KeyPressMask,
		handle_keypress,
		game);
	mlx_hook(
		game->win_ptr,
		DestroyNotify,
		NoEventMask,
		handle_exit,
		game);
	mlx_loop_hook(
		game->mlx_ptr,
		update_game,
		game);
	mlx_loop(game->mlx_ptr);
	return (exit_prog(game, 0), 0);
}
