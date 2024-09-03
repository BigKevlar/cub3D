/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:53:22 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/03 16:30:39 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	rotate_player(t_game *game, int i)
{
	if (i == 1)
	{
		game->ply->angle += ROTATESPEED;
		if (game->ply->angle > 2 * M_PI)
			game->ply->angle -= 2 * M_PI;
	}
	else
	{
		game->ply->angle -= ROTATESPEED;
		if (game->ply->angle < 0)
			game->ply->angle += 2 * M_PI;
	}
}

static void	move_player(t_game *game, double move_x, double move_y)
{
	int		new_x;
	int		new_y;

	new_x = 0;
	new_y = 0;
	new_x = roundf(game->ply->x + move_x);
	new_y = roundf(game->ply->y + move_y);
	if (new_x >= 0 && new_x <= S_W && game->map[game->ply->y/TILE_SIZE][(new_x)/TILE_SIZE] != '1'
		&& game->map[game->ply->y/TILE_SIZE][(new_x - 1)/TILE_SIZE] != '1')
		game->ply->x = new_x;
	if  (new_y >= 0 && new_y <= S_H && game->map[(new_y)/TILE_SIZE][game->ply->x/TILE_SIZE] != '1'
		&&game->map[(new_y - 1)/TILE_SIZE][game->ply->x/TILE_SIZE] != '1')
		game->ply->y = new_y;
}

void	ft_game_hook(void *param)
{
	t_game	*game;
	double	move_x;
	double	move_y;

	move_x = 0;
	move_y = 0;
	game = param;
	if (game->ply->rotate == 1)
		rotate_player(game, 1);
	if (game->ply->rotate == -1)
		rotate_player(game, 0);
	if (game->ply->move_d == true)
	{
		move_x = -sin(game->ply->angle) * MOVESPEED;
		move_y = cos(game->ply->angle) * MOVESPEED;
	}
	if (game->ply->move_a == true)
	{
		move_x = sin(game->ply->angle) * MOVESPEED;
		move_y = -cos(game->ply->angle) * MOVESPEED;
	}
	if (game->ply->move_w)
	{
		move_x = cos(game->ply->angle) * MOVESPEED * game->ply->move_w;
		move_y = sin(game->ply->angle) * MOVESPEED * game->ply->move_w;
	}
	move_player(game, move_x, move_y);
	printf("x: %d, y: %d\n", game->ply->x, game->ply->y);
}

void	ft_key_release(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_RELEASE))
		game->ply->move_d = false;
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_RELEASE))
		game->ply->move_a = false;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_RELEASE))
		game->ply->move_w = 0;
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_RELEASE))
		game->ply->move_w = 0;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		game->ply->rotate = 0;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		game->ply->rotate = 0;
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS))
		game->ply->move_a = true;
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS))
		game->ply->move_d = true;
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS))
		game->ply->move_w = -1;
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		game->ply->move_w = 1;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		game->ply->rotate = -1;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		game->ply->rotate = 1;
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	ft_key_release(keydata, game);
}
