/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:21:17 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/02 18:55:32 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/inc/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <limits.h>

# define S_H 1000
# define S_W 1500
# define MOVESPEED 4
# define ROTATESPEED 0.05
# define TILE_SIZE 32
# define FOV 1.1

typedef struct	s_tex
{
	mlx_texture_t *n;
	mlx_texture_t *s;
	mlx_texture_t *w;
	mlx_texture_t *e;
}				t_tex;

typedef struct	s_img
{
	mlx_image_t	*window;
	mlx_image_t	*minimap;
}				t_img;

typedef struct	s_ray
{
	double	angle;
	int	x;
	int	y;
	double	distance;
}				t_ray;

typedef struct	s_player
{
	int		x;
	int		y;
	double	angle;
	int		move_w;
	bool	move_a;
	bool	move_d;
	int		rotate;
}				t_player;

typedef struct	s_routes
{
	char	*n;
	char	*s;
	char	*e;
	char	*w;
}				t_routes;

typedef struct	s_game
{
	mlx_t		*mlx;
	t_tex		*tex;
	t_img		*img;
	t_ray		*ray;
	t_player	*ply;
	char		**map;
	t_routes	*routes;
}				t_game;

void	init_data(t_game *game);
void	check_args(void);
void	run_game(t_game *game);
void	get_images(t_game *game);
void	rotate_player(t_game *game, int i);
void	init_player(t_game *g);
void	ft_key_release(mlx_key_data_t keydata, t_game *game);
void	ft_key_hook(mlx_key_data_t keydata, void *param);
void	ft_game_hook(void *param);
void	raycast(void *param);
void	render(t_game *g, int i);
void ft_clear_window(t_game *g);

#endif