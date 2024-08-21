/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 23:46:20 by jmartos           #+#    #+#             */
/*   Updated: 2024/08/20 14:58:44 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//
static void	imgs2map_1(t_game *game, char **map, int c1, int c2)
{
	if (map[c1][c2] == '1')
	{
		mlx_image_to_window(game->mlx, game->image_wall, c2 * X, c1 * Y);
	}
	else if (map[c1][c2] == '0'	|| map[c1][c2] == 'P')
	{
		mlx_image_to_window(game->mlx, game->image_floor, c2 * X, c1 * Y);
	}
}

//
static void	imgs2map_2(t_game *game, char **map, int c1, int c2)
{
	if (map[c1][c2] == 'P')
	{
		mlx_image_to_window(game->mlx, game->image_player, c2 * X, c1 * Y);
	}
}

//
void	print_map(t_game *game, char **map)
{
	int	c1;
	int	c2;

	c1 = 0;
	while (c1 < game->rows)
	{
		c2 = 0;
		while (c2 < game->columns)
		{
			imgs2map_1(game, map, c1, c2);
			imgs2map_2(game, map, c1, c2);
			// IMPLEMENTACION DEL RAYCAST???
			c2++;
		}
		c1++;
	}
}

//
void	gui(t_game *game)
{
	loading_gui(game);
	print_map(game, game->map);
	player_position(game);
	flood_fill(game, game->pos_x, game->pos_y);
}

