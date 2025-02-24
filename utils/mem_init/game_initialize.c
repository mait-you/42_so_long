/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initialize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:10:05 by mait-you          #+#    #+#             */
/*   Updated: 2025/02/24 18:05:59 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static size_t	count_line(char *file_path)
{
	char	*line;
	int		fd;
	size_t	line_count;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		error_cleanup(NULL, "Open failed");
	line_count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

static void	plyer_and_coin_initialize(t_game **new_game)
{
	(*new_game)->player = (t_player *)ft_calloc(1, sizeof(t_player));
	if (!(*new_game)->player)
		error_cleanup(*new_game, "alloction failed");
	(*new_game)->coin = (t_coin *)ft_calloc(1, sizeof(t_coin));
	if (!(*new_game)->coin)
		error_cleanup(*new_game, "alloction failed");
}

static void	enemy_and_exit_initialize(t_game **new_game)
{
	(*new_game)->exit = (t_exit *)ft_calloc(1, sizeof(t_exit));
	if (!(*new_game)->exit)
		error_cleanup(*new_game, "alloction failed");
	(*new_game)->enmy = (t_enemy *)ft_calloc(1, sizeof(t_enemy));
	if (!(*new_game)->enmy)
		error_cleanup(*new_game, "alloction failed");
}

static void	mlx_and_win_initialize(t_game **new_game)
{
	(*new_game)->mlx_ptr = mlx_init();
	if (!(*new_game)->mlx_ptr)
		error_cleanup(*new_game, "MLX init failed");
	(*new_game)->win_ptr = mlx_new_window
	(
		(*new_game)->mlx_ptr,
		BLOCK * (*new_game)->map->map_col,
		BLOCK * (*new_game)->map->map_row,
		TITLE
	);
	if (!(*new_game)->win_ptr)
		error_cleanup(*new_game, "Failed to create window");
}

t_game	*game_initialize(char *file_path)
{
	t_game		*new_game;

	new_game = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!new_game)
		error_cleanup(new_game, "alloction failed");
	new_game->map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!new_game->map)
		error_cleanup(new_game, "alloction failed");
	new_game->map->map_str
		= (char **)ft_calloc(count_line(file_path) + 1, sizeof(char *));
	if (!new_game->map)
		error_cleanup(new_game, "alloction failed");
	plyer_and_coin_initialize(&new_game);
	enemy_and_exit_initialize(&new_game);
	get_map(new_game, file_path);
	mlx_and_win_initialize(&new_game);
	return (new_game);
}
