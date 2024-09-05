/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:19:02 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/03 16:57:57 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	sign(double n)
{
	if (n > 0)
		return (1);
	if (n < 0)
		return (-1);
	return (0);
}

static bool	wall_hit(t_game *g, double x, double y)
{
	x = floor(x / TILE_SIZE);
	y = floor(y / TILE_SIZE);
	if (y < 0 || y >= g->map_rows || x < 0 || x >= g->map_columns)
		return (true);
	if (g->map[(int)y][(int)x] == '1')
		return (true);
	return (false);
}

static double	get_v_distance(t_game *g)
{
	double	step_x;
	double	step_y;
	double	x_pos;
	double	y_pos;

	step_x = TILE_SIZE * sign(cos(g->ray->angle));
	step_y = TILE_SIZE * tan(g->ray->angle) * sign(cos(g->ray->angle));
	x_pos = floor(g->ply->x / TILE_SIZE) * TILE_SIZE;
	if (cos(g->ray->angle) >= 0)
		x_pos += TILE_SIZE;
	y_pos =	g->ply->y + (x_pos - g->ply->x) * tan(g->ray->angle);
	while (!wall_hit(g, x_pos + sign(cos(g->ray->angle)), y_pos)) //ojo con el sign(cos)
	{
		x_pos += step_x;
		y_pos += step_y;
	}
	return (sqrt(pow(x_pos - g->ply->x, 2) + pow(y_pos - g->ply->y, 2)));
}

static double	get_h_distance(t_game *g)
{
	double	step_x;
	double	step_y;
	double	x_pos;
	double	y_pos;

	step_x = TILE_SIZE / tan(g->ray->angle) * sign(sin(g->ray->angle));
	step_y = TILE_SIZE * sign(sin(g->ray->angle));
	y_pos = floor(g->ply->y / TILE_SIZE) * TILE_SIZE;
	if (sin(g->ray->angle) >= 0)
		y_pos +=  TILE_SIZE;
	x_pos = g->ply->x + (y_pos - g->ply->y) / tan(g->ray->angle);
	while (!wall_hit(g, x_pos, y_pos + sign(sin(g->ray->angle)))) //ojo con el sign(sin)
	{
		x_pos += step_x;
		y_pos += step_y;
	}
	return (sqrt(pow(x_pos - g->ply->x, 2) + pow(y_pos - g->ply->y, 2)));
}

void	raycast(void *param)
{
	int	i;
	double	v_distance;
	double	h_distance;
	t_game	*g;

	g = param;
	i = 0;
	g->ray->angle = g->ply->angle - (FOV / 2);
	ft_clear_window(g);
	while (i < S_W)
	{
		v_distance = get_v_distance(g);
		h_distance = get_h_distance(g);
		if (v_distance <= h_distance)
		{
			g->ray->distance = v_distance;
			get_v_surface(g);
		}
		else
		{
			g->ray->distance = h_distance;
			get_h_surface(g);
		}
		g->ray->distance = g->ray->distance * cos(fabs(g->ray->angle - g->ply->angle));
		render(g, i);
		i++;
		g->ray->angle = g->ray->angle + FOV / S_W;
	}
}
