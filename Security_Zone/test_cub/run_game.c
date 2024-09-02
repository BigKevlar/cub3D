/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:12:59 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/02 17:52:03 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3D.h"

void	run_game(t_game *g)
{
	g->mlx = mlx_init(S_W, S_H, "cub3D", false);
	g->img = ft_calloc(1, sizeof(t_img));
	g->img->window = mlx_new_image(g->mlx, S_W, S_H);
	mlx_image_to_window(g->mlx, g->img->window, 0, 0);
	//get_textures(g);
	mlx_key_hook(g->mlx, &ft_key_hook, g);
	mlx_loop_hook(g->mlx, &raycast, g);
	mlx_loop_hook(g->mlx, &ft_game_hook, g);
	mlx_loop(g->mlx);
	mlx_close_window(g->mlx);
}
