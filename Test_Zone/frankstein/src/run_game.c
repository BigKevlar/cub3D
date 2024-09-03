/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:12:59 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/03 20:18:55 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	draw_background(t_game *g)
{
	int	y;
	int	x;
	uint32_t	color;

	x = 0;
	y = 0;
	color = interpretate_color(g->color_C);
	while (y < S_H / 2)
	{
		x = 0;
		while (x < S_W)
		{
			mlx_put_pixel(g->img->background, x, y, color);
			x++;
		}
		y++;
	}
	color = interpretate_color(g->color_F);
	while (y < S_H)
	{
		x = 0;
		while (x < S_W)
		{
			mlx_put_pixel(g->img->background, x, y, color);
			x++;
		}
		y++;
	}
}

void	run_game(t_game *g)
{
	g->mlx = mlx_init(S_W, S_H, "cub3D", true); //LEAKS??? TERMINATE???
	g->img = ft_calloc(1, sizeof(t_img));
	g->img->background = mlx_new_image(g->mlx, S_W, S_H); //LEAKS???
	g->img->window = mlx_new_image(g->mlx, S_W, S_H); //LEAKS???
	mlx_image_to_window(g->mlx, g->img->window, 0, 0);
	mlx_image_to_window(g->mlx, g->img->background, 0, 0);
	draw_background(g);
	mlx_key_hook(g->mlx, &ft_key_hook, g);
	mlx_loop_hook(g->mlx, &ft_game_hook, g);
	mlx_loop_hook(g->mlx, &raycast, g);
	mlx_loop(g->mlx);
	mlx_close_window(g->mlx);
}
