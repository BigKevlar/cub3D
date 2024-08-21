/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:19:02 by arosas-j          #+#    #+#             */
/*   Updated: 2024/08/20 17:48:49 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
#include <limits.h>

int	sign(double n)
{
	if (n > 0)
		return (1);
	if (n < 0)
		return (-1);
	return (0);
}

bool	wall_hit(double x, double y, char **map)
{
	x = floor(x / TILE_SIZE);
	y = floor(y / TILE_SIZE);
	if (map[(int)y][(int)x] == '1')
		return (true);
	return (false);
}

double	get_v_distance(t_player *player, char **map, t_ray *ray)
{
	double	step_x;
	double	step_y;
	double	x_pos;
	double	y_pos;

	step_x = TILE_SIZE * sign(cos(ray->angle));
	step_y = TILE_SIZE * tan(ray->angle);
	x_pos = floor(player->pos_x / TILE_SIZE) * TILE_SIZE;
	if (cos(ray->angle) >= 0)
		x_pos += TILE_SIZE;
	y_pos =	player->pos_y + (x_pos - player->pos_x) * tan(ray->angle);
	while (!wall_hit(x_pos, y_pos, map))
	{
		x_pos += step_x;
		y_pos += step_y;
	}
	return (sqrt(pow(x_pos - player->pos_x, 2) + pow(y_pos - player->pos_y, 2)));
}

double	get_h_distance(t_player *player, char **map, t_ray *ray)
{
	double	step_x;
	double	step_y;
	double	x_pos;
	double	y_pos;

	step_x = TILE_SIZE / tan(ray->angle);
	step_y = TILE_SIZE * sign(sin(ray->angle));
	y_pos = floor(player->pos_y / TILE_SIZE) * TILE_SIZE;
	if (sin(ray->angle) >= 0)
		y_pos +=  TILE_SIZE;
	x_pos = player->pos_x + (y_pos - player->pos_y) / tan(ray->angle);
	while (!wall_hit(x_pos, y_pos, map))
	{
		x_pos += step_x;
		y_pos += step_y;
	}
	return (sqrt(pow(x_pos - player->pos_x, 2) + pow(y_pos - player->pos_y, 2)));
}

void	raycast(t_player *player, char **map, t_ray *ray)
{
	int	i;
	double	v_distance;
	double	h_distance;

	i = 0;
	ray->angle = player->angle + player->fov / 2;
	while (i < S_W)
	{
		v_distance = get_v_distance(player, map, ray);
		h_distance = get_h_distance(player, map, ray);
		if (v_distance <= h_distance)
			ray->distance = v_distance;
		else
			ray->distance = h_distance;
		ray->distance = ray->distance * cos(ray->angle);
		//render(ray);//to_do
		i++;
		ray->angle = ray->angle + player->fov / S_W;
	}
}

void	draw_line(mlx_image_t *image, double x1, double y1, double x2, double y2)
{
	double	m;
	double	n;
	double	x;
	double	y;

	m = (x2 - x1) / (y2 - y1);
	n = y1 - m * x1;
	x = x1;
	while (x <= x2)
	{
		y = round(m * x + n);
		mlx_put_pixel(image, x, y, 0xFFFFFFFF);
		x++;
	}
}