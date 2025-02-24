/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:14:33 by mait-you          #+#    #+#             */
/*   Updated: 2025/02/24 15:30:17 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	player_win(t_game *game)
{
	ft_putstr_fd("\nYou win\n", 1);
	exit_prog(game, 0);
	return (0);
}

int	player_lose(t_game *game)
{
	ft_putstr_fd("\nYou lose\n", 1);
	exit_prog(game, 0);
	return (0);
}

int	chak_move(t_game *game, int x, int y)
{
	if (game->map->map_str[x][y] == '1' || (game->map->map_str[x][y] == 'E'
		&& game->player->player_coins != game->coin->coins))
		return (0);
	if (game->map->map_str[x][y] == 'C')
	{
		game->map->map_str[x][y] = '0';
		game->player->player_coins++;
	}
	game->player->x_pos = x;
	game->player->y_pos = y;
	game->player->moves++;
	ft_putstr_fd("\r", 1);
	ft_putstr_fd("count moves :", 1);
	ft_putnbr(game->player->moves);
	ft_putstr_fd(" ", 1);
	return (1);
}

int	control_moves(int keysym, t_game *game, int x, int y)
{
	if (keysym == XK_a || keysym == XK_Left)
	{
		game->player->current_pos = 'L';
		y--;
	}
	else if (keysym == XK_d || keysym == XK_Right)
	{
		game->player->current_pos = 'R';
		y++;
	}
	else if (keysym == XK_w || keysym == XK_Up)
	{
		game->player->current_pos = 'U';
		x--;
	}
	else if (keysym == XK_s || keysym == XK_Down)
	{
		game->player->current_pos = 'D';
		x++;
	}
	chak_move(game, x, y);
	return (0);
}

int	chek_args(int ac, char *file_path)
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
