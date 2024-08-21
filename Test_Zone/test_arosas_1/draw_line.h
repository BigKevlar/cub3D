/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:18:42 by arosas-j          #+#    #+#             */
/*   Updated: 2024/08/20 15:13:00 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_LINE_H
# define DRAW_LINE_H

# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"

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