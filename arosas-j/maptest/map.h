/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:48:07 by arosas-j          #+#    #+#             */
/*   Updated: 2024/08/26 17:37:47 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"

# define S_W 1000
# define S_H 1000
# define MOVESPEED 4
# define ROTATESPEED 0.05

typedef struct s_textures
{
	mlx_texture_t	*blank;
	mlx_texture_t	*wall;
	mlx_texture_t	*p_right;
}				t_textures;

typedef struct s_images
{
	mlx_image_t	*blank;
	mlx_image_t	*wall;
	mlx_image_t	*p_right;
	mlx_image_t	*ray;
}				t_images;

typedef struct s_game
{
	t_images	*img;
	t_textures	*text;
	mlx_t		*mlx;
	char		**map;
	double		angle;
	int			x;
	int			y;
	double		x2;
	double		y2;
	int			move_w;
	bool		move_a;
	bool		move_d;
	int			rotate;
}				t_game;

void	get_textures(t_game *game);
void	get_images(t_game *game);
void	game_to_window(t_game *game);
void	ft_key_hook(mlx_key_data_t keydata, void *param);
void	ft_key_release(mlx_key_data_t keydata, t_game *game);
void	ft_game_hook(void *param);
void	draw_line(t_game *game);

#endif