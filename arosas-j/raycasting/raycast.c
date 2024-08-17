/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:19:02 by arosas-j          #+#    #+#             */
/*   Updated: 2024/08/17 22:25:33 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

double	get_v_distance(t_player player, char **map, t_ray *ray)
{
	double	step_x;
	double	step_y;
	double	x_pos;
	double	y_pos;

	step_x = TILE_SIZE;
	step_y = 
	
	x_pos = 
	y_pos =	TILE_SIZE;
}

double	get_v_distance(t_player player, char **map, t_ray *ray)
{}

void	raycast(t_player player, char **map, t_ray *ray)
{
	int	i;
	double	v_distance;
	double	h_distance;

	i = 0;
	//Calcular angulo del primer rayo
	while (i < S_W)
	{
		v_distance = get_v_distance(player, map, ray);
		h_distance = get_h_distance(player, map, ray);
		if (v_distance <= h_distance)
			ray->distance = v_distance;
		else
			ray->distance = h_distance;
		//Render
		i++;
		ray->angle = new_angle();//Calcular el angulo del proximo rayo
	}
}
