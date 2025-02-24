/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:29:53 by mait-you          #+#    #+#             */
/*   Updated: 2025/02/24 18:07:05 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	chek_character(t_game *game, t_map *map, int i, int j)
{
	i = 0;
	while (map->map_str[i])
	{
		j = 0;
		while (map->map_str[i][j])
		{
			if (!ft_strchr("01PCEX", map->map_str[i][j]))
				error_cleanup(game, "Map contains invalid characters");
			if (map->map_str[i][j] == 'P')
				game->player->players++;
			if (map->map_str[i][j] == 'C')
				game->coin->coins++;
			if (map->map_str[i][j] == 'E')
				game->exit->exits++;
			if (map->map_str[i][j] == 'X')
				game->enmy->enemys++;
			j++;
		}
		i++;
	}
	if (game->player->players != 1 || game->exit->exits != 1
		|| game->coin->coins < 1 || game->enmy->enemys < 1)
		error_cleanup
		(game, "Map must have 1 P, 1 E, and at least 1 C and 1 X");
	return (0);
}

static int	chek_len(t_game *game, t_map *map)
{
	int		i;
	int		j;
	size_t	len_chek;

	i = 0;
	len_chek = ft_strlen(map->map_str[i]);
	while (map->map_str[i])
	{
		if (ft_strlen(map->map_str[i]) != len_chek)
			error_cleanup(game, "All rows must have equal length");
		if (map->map_str[i][0] != '1')
			error_cleanup(game, "Left border must be walls");
		if (map->map_str[i][ft_strcspn(map->map_str[i], "\n") - 1] != '1')
			error_cleanup(game, "Right border must be walls");
		i++;
	}
	j = 0;
	while (map->map_str[0][j])
		if (map->map_str[0][j++] != '1')
			error_cleanup(game, "Top border must be walls");
	j = 0;
	while (map->map_str[i - 1][j])
		if (map->map_str[i - 1][j++] != '1')
			error_cleanup(game, "Bottom border must be walls");
	return (0);
}

static int	chek_rectangular(t_game *game, t_map *map)
{
	if (map->map_col < 6)
		error_cleanup(game, "Map width must be at least 6 columns");
	if (map->map_col > 40)
		error_cleanup(game, "Map width cannot exceed 40 columns");
	if (map->map_row < 3)
		error_cleanup(game, "Map height must be at least 3 rows");
	if (map->map_row > 21)
		error_cleanup(game, "Map height cannot exceed 21 rows");
	if (map->map_row >= map->map_col)
		error_cleanup(game, "Map is not rectangular enough");
	return (0);
}

static int	chek_map(t_game *game, t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (map->map_str[x])
	{
		y = 0;
		while (map->map_str[x][y])
		{
			if (map->map_str[x][y] == 'P')
			{
				game->player->x_pos = x;
				game->player->y_pos = y;
			}
			y++;
		}
		x++;
	}
	map->map_row = x;
	map->map_col = (int)ft_strlen(map->map_str[0]);
	chek_rectangular(game, map);
	chek_len(game, map);
	chek_character(game, map, 0, 0);
	flood_fill_chek(game, map);
	return (0);
}

int	get_map(t_game *game, char *file_path)
{
	t_map	*map;
	int		i;
	int		fd;

	i = 0;
	map = game->map;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		error_cleanup(game, "fd failed");
	map->map_str[i] = get_next_line(fd);
	if (!map->map_str[i])
		error_cleanup(game, "file is empty");
	while (map->map_str[i++] != NULL)
		map->map_str[i] = get_next_line(fd);
	close(fd);
	i = 0;
	while (map->map_str[i])
	{
		map->map_str[i][ft_strcspn(map->map_str[i], "\n")] = 0;
		i++;
	}
	chek_map(game, map);
	return (0);
}
