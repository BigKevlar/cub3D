/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:18:42 by arosas-j          #+#    #+#             */
/*   Updated: 2024/08/17 22:25:37 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include <math.h>
# include "MLX42.h"

# define S_W 1000
# define TILE_SIZE 32

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	fov;
}				t_player;

typedef struct s_ray
{
	double	angle;
	double	v_x;
	double	v_y;
	double	h_x;
	double	h_y;
	double	distance;
}				t_ray;

#endif