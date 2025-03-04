/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initialize_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:10:05 by mait-you          #+#    #+#             */
/*   Updated: 2025/03/01 10:02:29 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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

static void	mlx_and_win_initialize(t_game *new_game)
{
	new_game->mlx_ptr = mlx_init();
	if (!new_game->mlx_ptr)
		error_cleanup(new_game, "MLX init failed");
	new_game->win_ptr = mlx_new_window
		(
			new_game->mlx_ptr,
			BLOCK * new_game->map->map_col,
			BLOCK * new_game->map->map_row,
			TITLE
			);
	if (!new_game->win_ptr)
		error_cleanup(new_game, "Failed to create window");
}

void	game_initialize(t_game *game, char *file_path)
{
	ft_memset(game->map, 0, sizeof(t_map));
	ft_memset(game->player, 0, sizeof(t_player));
	ft_memset(game->coin, 0, sizeof(t_coin));
	ft_memset(game->exit, 0, sizeof(t_exit));
	game->player->current_pos = 'D';
	game->map->map_str
		= (char **)ft_calloc(count_line(file_path) + 1, sizeof(char *));
	if (!game->map)
		error_cleanup(game, "alloction failed");
	get_map(game, file_path);
	get_enemy(game);
	mlx_and_win_initialize(game);
	imgs_initialize(game);
}
