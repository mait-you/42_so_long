/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:14:33 by mait-you          #+#    #+#             */
/*   Updated: 2025/03/03 17:26:05 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	player_win(t_game *game)
{
	ft_putstr_fd("\nYou win\n", 1);
	exit_prog(game, 0);
	return (0);
}

int	check_move(t_game *game, int x, int y)
{
	if (game->map->map_str[y][x] == '1')
		return (0);
	if (x == game->player->x_pos && y == game->player->y_pos)
		return (0);
	game->player->x_pos = x;
	game->player->y_pos = y;
	game->player->moves++;
	return (1);
}

int	control_moves(int keycode, t_game *game, int x, int y)
{
	if (keycode == 0 || keycode == 123)
		x--;
	else if (keycode == 2 || keycode == 124)
		x++;
	else if (keycode == 13 || keycode == 126)
		y--;
	else if (keycode == 1 || keycode == 125)
		y++;
	check_move(game, x, y);
	return (0);
}

int	check_args(int ac, char *file_path)
{
	if (ac != 2)
		error_cleanup(NULL, "./so_long <path_of_map>");
	while (*file_path && *file_path != '.')
		file_path++;
	if (ft_memcmp(".ber", file_path, 5))
		error_cleanup
		(NULL, "the <path_of_map> sould ending with the `.ber` extension");
	return (0);
}
