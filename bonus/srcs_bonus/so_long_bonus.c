/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:24:49 by mait-you          #+#    #+#             */
/*   Updated: 2025/03/04 09:25:51 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	update_game(t_game *game)
{
	ft_putstr_fd("\r", 1);
	ft_putstr_fd("count moves :", 1);
	ft_putnbr(game->player->moves);
	ft_putstr_fd(" ", 1);
	if (is_player_lose_or_win(game) == 1)
		return (player_win(game));
	if (is_player_lose_or_win(game) == -1)
		return (player_lose(game));
	if (game->map->map_str[game->player->y_pos][game->player->x_pos] == 'C')
	{
		game->map->map_str[game->player->y_pos][game->player->x_pos] = '0';
		game->player->player_coins++;
	}
	update_animation(game);
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
	t_coin		coin;
	t_exit		exit;

	check_args(ac, av[1]);
	ft_memset(&game, 0, sizeof(t_game));
	game.map = &map;
	game.player = &player;
	game.coin = &coin;
	game.exit = &exit;
	game_initialize(&game, av[1]);
	imgs_initialize(&game);
	mlx_hook(game.win_ptr, 2, 0, handle_keypress, &game);
	mlx_hook(game.win_ptr, 17, 0, handle_exit, &game);
	mlx_loop_hook(game.mlx_ptr, update_game, &game);
	mlx_loop(&game.mlx_ptr);
	return (exit_prog(&game, 0), 0);
}
