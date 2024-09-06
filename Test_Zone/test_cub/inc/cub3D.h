/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:21:17 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/06 20:34:18 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/inc/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <limits.h>

# define S_H 768
# define S_W 1024
# define MOVESPEED 3
# define ROTATESPEED 0.05
# define TILE_SIZE 32
# define FOV 1.15192

typedef struct	s_tex
{
	mlx_texture_t	*n;
	mlx_texture_t	*s;
	mlx_texture_t	*w;
	mlx_texture_t	*e;
	mlx_texture_t	*door;
}				t_tex;

typedef enum	e_side
{
	NORTH,
	SOUTH,
	WEST,
	EAST,
}				t_side;

typedef struct	s_img
{
	mlx_image_t	*window;
	mlx_image_t	*minimap;
	mlx_image_t	*background;
}				t_img;

typedef struct	s_ray
{
	double	angle;
	double	x;
	double	y;
	double	x2;
	double	y2;
	mlx_texture_t	*tex;
	double	distance;
	t_side	side;
	bool	door_h;
	bool	door_v;
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
	int			ratio;
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
void	ft_clear_window(t_game *g);
int		sign(double n);
void	get_h_surface(t_game *g);
void	get_v_surface(t_game *g);
uint32_t	get_pixel_color(t_game *g, int	size, int tex_colum);
void	get_textures(t_game *game);
double	get_colum(t_game *g);

#endif