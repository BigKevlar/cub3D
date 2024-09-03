/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:16:23 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/03 18:55:15 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	get_size(t_ray *ray)
{
	int	size;

	size = ((S_H * TILE_SIZE) / ray->distance);
	return (size);
}

static uint32_t get_color(t_game *g)
{
	if (g->ray->side == NORTH)
		return (0xFFFFFFFF); // WARNING!!!!!!!!!!!!
	if (g->ray->side == SOUTH)
		return (0xFF0000FF); // WARNING!!!!!!!!!!!!
	if (g->ray->side == EAST)
		return (0x0000FFFF); // WARNING!!!!!!!!!!!!
	if (g->ray->side == WEST)
		return (0x00FF00FF); // WARNING!!!!!!!!!!!!
	return (0);
}

void ft_clear_window(t_game *g)
{
	mlx_delete_image(g->mlx, g->img->window);
	g->img->window = mlx_new_image(g->mlx, S_W, S_H);
	mlx_image_to_window(g->mlx, g->img->window, 0, 0);
}

void render(t_game *g, int i)
{
	int	start;
	int	size;
	uint32_t color;

	size = 0;
	size = get_size(g->ray);
	if (size > S_H)
		size = S_H;
	start = (S_H / 2) - (size / 2);
	color = get_color(g);
	while (size > 0)
	{
		if (start >= 0 && start < S_H && i >= 0 && i < S_W)
			mlx_put_pixel(g->img->window, i, start, color);
		size--;
		start++;
	}
}

void	get_v_surface(t_game *g)
{
	if (sign(cos(g->ray->angle)) == 1)
	{
		g->ray->side = WEST;
	}
	else
		g->ray->side = EAST;
}

void get_h_surface(t_game *g)
{
	if (sign(sin(g->ray->angle)) == 1)
	{
		g->ray->side = SOUTH;
	}
	else
		g->ray->side = NORTH;
}