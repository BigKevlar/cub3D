/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:45:50 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/17 22:13:29 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "MLX42.h"

# define size_tileset 64 // Tamaño de los tilesets.
# define FOV 66 // Angulo de vision del jugador (mismo que en Wolfenstein3D).
# define WIDTH 1920
# define HEIGHT 1080
# define MINIMAP 300

typedef struct s_player
{
	int		move_up;
	int		move_down;
	int		move_right;
	int		move_left;
	int		move_speed;
	int		look_speed;
	int		look_right;
	int		look_left;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_game
{
	mlx_t	*mlx;
	char	**map;
	int		row_x;
	int		colum_y;
	mlx_image_t		*image_floor;
	mlx_image_t		*image_wall;
}	t_game;

typedef struct s_raycast
{
	double	wallhit_distance;
}	t_raycast;

#endif