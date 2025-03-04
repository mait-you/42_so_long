/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:24:49 by mait-you          #+#    #+#             */
/*   Updated: 2025/03/03 17:26:13 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	update_game(t_game *game)
{
	ft_putstr_fd("\r", 1);
	ft_putstr_fd("count moves :", 1);
	ft_putnbr(game->player->moves);
	ft_putstr_fd(" ", 1);
	if (game->map->map_str[game->player->y_pos][game->player->x_pos] == 'E'
	&& game->player->player_coins == game->coins)
		return (player_win(game), 1);
	if (game->map->map_str[game->player->y_pos][game->player->x_pos] == 'C')
	{
		game->map->map_str[game->player->y_pos][game->player->x_pos] = '0';
		game->player->player_coins++;
	}
	load_map(game);
	return (0);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 53)
		exit_prog(game, 0);
	control_moves
	(keycode, game, game->player->x_pos, game->player->y_pos);
	return (0);
}

int	handle_exit(t_game *game)
{
	exit_prog(game, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_game		game;
	t_map		map;
	t_player	player;

	check_args(ac, av[1]);
	game_initialize(&game, &map, &player, av[1]);
	imgs_initialize(&game);
	mlx_hook(
		game.win_ptr,
		2,
		0,
		handle_keypress,
		&game);
	mlx_hook(
		game.win_ptr,
		17,
		0,
		handle_exit,
		&game);
	mlx_loop_hook(
		game.mlx_ptr,
		update_game,
		&game);
	mlx_loop(&game.mlx_ptr);
	return (exit_prog(&game, 0), 0);
}
