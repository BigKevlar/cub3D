/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:53:22 by arosas-j          #+#    #+#             */
/*   Updated: 2024/08/27 17:02:06 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	rotate_player(t_game *game, int i)
{
	if (i == 1)
	{
		game->angle += ROTATESPEED;
		if (game->angle > 2 * M_PI)
			game->angle -= 2 * M_PI;
	}
	else
	{
		game->angle -= ROTATESPEED;
		if (game->angle < 0)
			game->angle += 2 * M_PI;
	}
}

void	move_player(t_game *game, double move_x, double move_y)
{
	int		new_x;
	int		new_y;

	new_x = 0;
	new_y = 0;
	new_x = roundf(game->x + move_x);
	new_y = roundf(game->y + move_y);
	if (new_x >= 0 && new_x <= S_W)
		game->x = new_x;
	if  (new_y >= 0 && new_y <= S_H)
		game->y = new_y;
	game->img->p_right->instances->x = game->x;
	game->img->p_right->instances->y = game->y;
}

void	ft_game_hook(void *param)
{
	t_game	*game;
	double	move_x;
	double	move_y;

	move_x = 0;
	move_y = 0;
	game = param;
	if (game->rotate == 1)
		rotate_player(game, 1);
	if (game->rotate == -1)
		rotate_player(game, 0);
	if (game->move_d == true)
	{
		move_x = -sin(game->angle) * MOVESPEED;
		move_y = cos(game->angle) * MOVESPEED;
	}
	if (game->move_a == true)
	{
		move_x = sin(game->angle) * MOVESPEED;
		move_y = -cos(game->angle) * MOVESPEED;
	}
	if (game->move_w)
	{
		move_x = cos(game->angle) * MOVESPEED * game->move_w;
		move_y = sin(game->angle) * MOVESPEED * game->move_w;
	}
	move_player(game, move_x, move_y);
	draw_line(game);
}

void	ft_key_release(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_RELEASE))
		game->move_d = false;
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_RELEASE))
		game->move_a = false;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_RELEASE))
		game->move_w = 0;
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_RELEASE))
		game->move_w = 0;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		game->rotate = 0;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		game->rotate = 0;
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS))
		game->move_a = true;
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS))
		game->move_d = true;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS))
		game->move_w = -1;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		game->move_w = 1;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		game->rotate = -1;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		game->rotate = 1;
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	ft_key_release(keydata, game);
}