/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:16:23 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/06 12:21:38 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
/*
static uint32_t get_color(t_game *g)
{
	if (g->ray->side == NORTH)
		return (0xFFFFFFFF);
	if (g->ray->side == SOUTH)
		return (0xFF0000FF);
	if (g->ray->side == EAST)
		return (0x0000FFFF);
	if (g->ray->side == WEST)
		return (0x00FF00FF);
	return (0);
}
*/
int	get_size(t_ray *ray)
{
	int	size;

	size = ((S_H * TILE_SIZE) / ray->distance);
	return (size);
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
	int	j;
	int	tex_colum;

	j = 0;
	size = get_size(g->ray);
	tex_colum = get_colum(g);
	if (size > S_H)
	{
		j = (size - S_H) / 2;
		size = S_H;
	}
	start = (S_H - size) / 2;
	size += j;
	while (j < size)
	{
		if (start >= 0 && start < S_H &&  i < S_W)
		{
			color = get_pixel_color(g, j, tex_colum);
			mlx_put_pixel(g->img->window, i, start, color);
		}
		j++;
		start++;
	}
}

void	get_v_surface(t_game *g)
{
	if (sign(cos(g->ray->angle)) == 1)
	{
		g->ray->side = EAST;
		g->ray->tex = g->tex->e;
	}
	else
	{
		g->ray->side = WEST;
		g->ray->tex = g->tex->w;
	}
}

void get_h_surface(t_game *g)
{
	if (sign(sin(g->ray->angle)) == 1)
	{
		g->ray->side = NORTH;
		g->ray->tex = g->tex->n;
	}
	else
	{
		g->ray->side = SOUTH;
		g->ray->tex = g->tex->s;
	}
}
