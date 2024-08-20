/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:18:42 by arosas-j          #+#    #+#             */
/*   Updated: 2024/08/19 12:38:14 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "MLX42.h"

# define S_W 1000
# define TILE_SIZE 32

typedef enum	e_side
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}				t_side;

typedef struct	s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	fov;
	double	angle;
}				t_player;

typedef struct s_ray
{
	double	angle;
	double	v_x;
	double	v_y;
	double	h_x;
	double	h_y;
	double	distance;
	t_side	side;
}				t_ray;

#endif