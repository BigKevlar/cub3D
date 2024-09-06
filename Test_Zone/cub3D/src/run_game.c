/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:12:59 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/06 17:02:56 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void draw_background(t_game *g)
{
    int y;
    int x;
    //float intensity;
    uint32_t ceiling_color = interpretate_color(g, g->color_C); // Original ceiling color
    uint32_t floor_color = interpretate_color(g, g->color_F);   // Original floor color

    for (y = 0; y < S_H; y++)
    {
        // Calculate intensity based on y-coordinate
        //intensity = 1.0f - ((float)y * 2 / (float)S_H);

        for (x = 0; x < S_W; x++)
        {
            if (y < S_H / 2)
            {
                // Apply shadow effect to ceiling
                mlx_put_pixel(g->img->background, x, y, ceiling_color);
            }
            else
            {
                // Apply shadow effect to floor
                mlx_put_pixel(g->img->background, x, y, floor_color);
            }
        }
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
	load_torch_textures(g);
    draw_background(g);
    g->img->background->instances->z = 0;
	mlx_key_hook(g->mlx, &ft_key_hook, g);
	mlx_loop_hook(g->mlx, &ft_game_hook, g);
	mlx_loop_hook(g->mlx, &raycast, g);
	mlx_loop(g->mlx);
	mlx_close_window(g->mlx);
}