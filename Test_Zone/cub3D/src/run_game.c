/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:12:59 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/09 17:45:46 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**/
static void	draw_background(t_game *g)
{
	int			y;
	int			x;
	uint32_t	ceiling_color;
	uint32_t	floor_color;

	y = 0;
	x = 0;
	ceiling_color = interpretate_color(g, g->color_c);
	floor_color = interpretate_color(g, g->color_f);
	while (y < S_H)
	{
		x = 0;
		while (x < S_W)
		{
			if (y < S_H / 2)
				mlx_put_pixel(g->img->background, x, y, ceiling_color);
			else
				mlx_put_pixel(g->img->background, x, y, floor_color);
			x++;
		}
		y++;
	}
}

/**/
void	run_game(t_game *g)
{
	g->mlx = mlx_init(S_W, S_H, "cub3D", true);
	g->img->background = mlx_new_image(g->mlx, S_W, S_H);
	g->img->window = mlx_new_image(g->mlx, S_W, S_H);
	mlx_image_to_window(g->mlx, g->img->window, 0, 0);
	mlx_image_to_window(g->mlx, g->img->background, 0, 0);
	load_torch_textures(g);
	draw_background(g);
	g->img->background->instances->z = 0;
	mlx_key_hook(g->mlx, &ft_key_hook, g);
	mlx_loop_hook(g->mlx, &ft_game_hook, g);
	mlx_loop_hook(g->mlx, &raycast, g);
	mlx_loop(g->mlx);
	mlx_close_window(g->mlx);
}
