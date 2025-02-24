/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 11:14:33 by mait-you          #+#    #+#             */
/*   Updated: 2025/02/24 19:31:35 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	game_free(t_game *game)
{
	if (!game)
		return ;
	destroy_images(game);
	if (game->map)
	{
		if (game->map->map_str)
			args_free(game->map->map_str);
		free(game->map);
	}
	if (game->player)
		free(game->player);
	if (game->coin)
		free(game->coin);
	if (game->exit)
		free(game->exit);
	if (game->enmy)
		free(game->enmy);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);	
	free(game->mlx_ptr);
	free(game);
}

void args_free(char **ptr)
{
	int	i;
	
	if (!ptr)
		return;
	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	// ptr = NULL;
}

void	error_cleanup(t_game *game, char *error_msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error_msg, 2);
	exit_prog(game, 1);
}

void	exit_prog(t_game *game, int _exit)
{
	game_free(game);
	exit(_exit);
}
