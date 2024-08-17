/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:19:02 by arosas-j          #+#    #+#             */
/*   Updated: 2024/08/17 20:57:54 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

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

	}
	
}
