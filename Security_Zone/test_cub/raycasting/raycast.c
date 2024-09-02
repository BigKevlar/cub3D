/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:19:02 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/02 17:54:49 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	sign(double n)
{
	if (n > 0)
		return (1);
	if (n < 0)
		return (-1);
	return (0);
}

static bool	wall_hit(double x, double y, char **map)
{
	x = floor(x / TILE_SIZE);
	y = floor(y / TILE_SIZE);
	if (y < 0 || y >= 8 || x < 0 || x >= 26)
		return (true);
	if (map[(int)y][(int)x] == '1')
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
	step_y = TILE_SIZE * tan(g->ray->angle);
	x_pos = floor(g->ply->x / TILE_SIZE) * TILE_SIZE;
	if (cos(g->ray->angle) >= 0)
		x_pos += TILE_SIZE;
	y_pos =	g->ply->y + (x_pos - g->ply->x) * tan(g->ray->angle);
	while (!wall_hit(x_pos + sign(cos(g->ray->angle)), y_pos, g->map)) //ojo con el sign(cos)
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

	step_x = TILE_SIZE / tan(g->ray->angle);
	step_y = TILE_SIZE * sign(sin(g->ray->angle));
	y_pos = floor(g->ply->y / TILE_SIZE) * TILE_SIZE;
	if (sin(g->ray->angle) >= 0)
		y_pos +=  TILE_SIZE;
	x_pos = g->ply->x + (y_pos - g->ply->y) / tan(g->ray->angle);
	while (!wall_hit(x_pos, y_pos + sign(sin(g->ray->angle)), g->map)) //ojo con el sign(sin)
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
	g->ray->angle = g->ply->angle + FOV / 2;
	ft_clear_window(g);
	while (i < S_W)
	{
		v_distance = get_v_distance(g);
		h_distance = get_h_distance(g);
		if (v_distance <= h_distance)
			g->ray->distance = v_distance;
		else
			g->ray->distance = h_distance;
		g->ray->distance = g->ray->distance * cos(g->ray->angle);
		render(g, i);
		i++;
		g->ray->angle = g->ray->angle + FOV / S_W;
	}
}
