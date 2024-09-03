/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:12:59 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/03 13:13:15 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3D.h"

static void	draw_background(t_game *g)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (y < S_H / 2)
	{
		x = 0;
		while (x < S_W)
		{
			mlx_put_pixel(g->img->background, x, y, 0xFFA500FF);
			x++;
		}
		y++;
	}
	while (y < S_H)
	{
		x = 0;
		while (x < S_W)
		{
			mlx_put_pixel(g->img->background, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
}

void	run_game(t_game *g)
{
	g->mlx = mlx_init(S_W, S_H, "cub3D", true);
	g->img = ft_calloc(1, sizeof(t_img));
	g->img->background = mlx_new_image(g->mlx, S_W, S_H);
	g->img->window = mlx_new_image(g->mlx, S_W, S_H);
	mlx_image_to_window(g->mlx, g->img->window, 0, 0);
	mlx_image_to_window(g->mlx, g->img->background, 0, 0);
	draw_background(g);
	mlx_key_hook(g->mlx, &ft_key_hook, g);
	mlx_loop_hook(g->mlx, &ft_game_hook, g);
	mlx_loop_hook(g->mlx, &raycast, g);
	mlx_loop(g->mlx);
	mlx_close_window(g->mlx);
}
