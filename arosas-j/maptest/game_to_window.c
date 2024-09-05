/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_to_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:04:00 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/05 16:25:20 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdio.h>

/*static void	draw_floor(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;

	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x])
				mlx_image_to_window(game->mlx, game->img->blank, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

static void	draw_wall(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;

	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->img->wall, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}*/

void	game_to_window(t_game *game)
{
	//draw_floor(game);
	//draw_wall(game);
	mlx_image_to_window(game->mlx, game->img->p_right, game->x, game->y);
	game->img->ray = mlx_new_image(game->mlx, 0, 0);
}
