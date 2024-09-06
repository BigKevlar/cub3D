/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:21:17 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/06 12:13:37 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/inc/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include <limits.h>
# include <unistd.h> // usleep()

# define S_W 1024
# define S_H 768
# define MOVESPEED 2
# define ROTATESPEED 0.05
# define TILE_SIZE 32
# define FOV 1.15192

typedef struct	s_tex
{
	mlx_texture_t *n;
	mlx_texture_t *s;
	mlx_texture_t *w;
	mlx_texture_t *e;
}	t_tex;

typedef enum	e_side
{
	NORTH,
	SOUTH,
	WEST,
	EAST
}	t_side;

typedef struct	s_img
{
	mlx_image_t	*window;
	mlx_image_t	*minimap;
	mlx_image_t	*background;
}	t_img;

typedef struct	s_ray
{
	double			angle;
	double			x;
	double			y;
	double			x2;
	double			y2;
	mlx_texture_t	*tex;
	double			distance;
	t_side			side;
}	t_ray;

typedef struct	s_player
{
	int		x;
	int		y;
	double	angle;
	int		move_w;
	bool	move_a;
	bool	move_d;
	int		rotate;
}	t_player;

typedef struct	s_routes
{
	char	*n;
	char	*s;
	char	*e;
	char	*w;
}	t_routes;

typedef struct	s_game
{
	char			**file;
	int				file_size;
	char			*texture_NO;
	char			*texture_SO;
	char			*texture_WE;
	char			*texture_EA;
	char			*color_F;
	char			*color_C;
	char			**map;
	char			**map_copy;
	int				map_rows;
	int				map_columns;
	int				player_X;
	int				player_Y;
	char			player_orientation;
	int				ratio;
	mlx_texture_t	*t_texture00;
    mlx_texture_t	*t_texture01;
    mlx_texture_t	*t_texture02;
    mlx_texture_t	*t_texture03;
    mlx_texture_t	*t_texture04;
    mlx_texture_t	*t_texture05;
    mlx_texture_t	*t_texture06;
    mlx_texture_t	*t_texture07;
	mlx_texture_t 	*torch_texture;
	mlx_image_t		*t_image00;
    mlx_image_t		*t_image01;
    mlx_image_t		*t_image02;
    mlx_image_t		*t_image03;
    mlx_image_t		*t_image04;
    mlx_image_t		*t_image05;
    mlx_image_t		*t_image06;
    mlx_image_t		*t_image07;
	mlx_image_t		*torch_image;
	int				torch_animation_speed;
	int				actual_torch_frame;
	int				torch_frame_counter;
	mlx_t			*mlx;
	t_tex			*tex;
	t_img			*img;
	t_ray			*ray;
	t_player		*ply;
	t_routes		*routes;
}	t_game;

void		free_error(char *msg, t_game *game);
void		init_data(t_game *game);
void		parse_ext(char *av);
void		get_file(t_game *game, char *file);
void		get_texture(t_game *game);
void		get_rgb(t_game *game);
void		get_map(t_game *game);
void		parse_map(t_game *g);
void		malloc_data(t_game *game);
void		check_args(void);
void		run_game(t_game *game);
void		get_images(t_game *game);
void		rotate_player(t_game *game, int i);
void		init_player(t_game *g);
void		ft_key_release(mlx_key_data_t keydata, t_game *game);
void		ft_key_hook(mlx_key_data_t keydata, void *param);
void		ft_game_hook(void *param);
void		raycast(void *param);
void		render(t_game *g, int i);
void		ft_clear_window(t_game *g);
int			sign(double n);
void		get_h_surface(t_game *g);
void		get_v_surface(t_game *g);
uint32_t	get_pixel_color(t_game *g, int	size, int tex_colum);
void		get_textures(t_game *game);
double		get_colum(t_game *g);
uint32_t	interpretate_color (char *color);
void		check_inits(t_game *g);
void		free_game(char *msg, t_game *g);
void		load_torch_textures(t_game *g);
void		draw_torch(t_game *g);

#endif