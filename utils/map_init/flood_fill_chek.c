/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_chek.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 21:34:10 by mait-you          #+#    #+#             */
/*   Updated: 2025/02/24 18:00:13 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	chak_fill_map(t_game *game, char **tmp_map)
{
	int	i;
	int	j;

	i = 0;
	while (tmp_map[i])
	{
		j = 0;
		while (tmp_map[i][j])
		{
			if (ft_strchr("PCE", tmp_map[i][j]))
			{
				args_free(tmp_map);
				error_cleanup
				(game, "Not all items are reachable by the player");
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	fill(t_map *map, char **tmp_map, int x, int y)
{
	if (x < 0 || y < 0 || x > map->map_row || y > map->map_col \
		|| tmp_map[x][y] == '1' || tmp_map[x][y] == 'X')
		return (0);
	tmp_map[x][y] = '1';
	fill(map, tmp_map, x + 1, y);
	fill(map, tmp_map, x - 1, y);
	fill(map, tmp_map, x, y + 1);
	fill(map, tmp_map, x, y - 1);
	return (0);
}

#include <stdio.h>

int	flood_fill_chek(t_game *game, t_map	*map)
{
	char	**tmp_map;
	int		i;

	tmp_map = (char **)ft_calloc(map->map_row + 1, sizeof(char *));
	if (!tmp_map)
		error_cleanup(game, "Memory allocation failed");
	i = 0;
	while (map->map_str[i])
	{
		tmp_map[i] = ft_strdup(map->map_str[i]);
		i++;
	}
	tmp_map[i] = ft_strdup(map->map_str[i]);
	fill
	(map, tmp_map, game->player->x_pos, game->player->y_pos);
	chak_fill_map(game, tmp_map);
	// i = 0;
	// while (tmp_map[i])
	// {
	// 	free(tmp_map[i]);
	// 	i++;
	// }
	// free(tmp_map);
	args_free(tmp_map);
	// printf("{%s}\n", tmp_map[0]);
	// printf("{%s}\n", tmp_map[1]);
	// printf("{%s}\n", tmp_map[2]);
	// printf("{%s}\n", tmp_map[3]);
	// printf("{%s}\n", tmp_map[4]);
	// printf("{%s}\n", tmp_map[5]);
	
	return (0);
}
