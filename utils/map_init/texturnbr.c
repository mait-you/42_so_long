/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texturnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-you <mait-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:58:53 by mait-you          #+#    #+#             */
/*   Updated: 2025/02/23 17:23:01 by mait-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	ft_put_texturnbr(t_game *game, int nb, int position, int block)
{
	mlx_put_image_to_window(
		game->mlx_ptr,
		game->win_ptr,
		game->numbers_textures[nb],
		(BLOCK / 2) * position + (BLOCK / 2) * block,
		0);
	return (0);
}

static int	ft_texturnbr_recursive(
	t_game *game, int nb, int *position, int block
	)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb >= 10)
	{
		ft_texturnbr_recursive(game, nb / 10, position, block);
		(*position)++;
	}
	ft_put_texturnbr(game, base[nb % 10] - '0', *position, block);
	return (0);
}

int	ft_texturnbr(t_game *game, int nb, int block)
{
	int	position;

		position = 0;
		if (nb < 0)
			error_cleanup(game, "too many moves");
	ft_texturnbr_recursive(game, nb, &position, block);
	return (0);
}
