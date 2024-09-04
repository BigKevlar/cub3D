/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:21:17 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/04 14:22:22 by arosas-j         ###   ########.fr       */
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
# define MOVESPEED 6
# define ROTATESPEED 0.05
# define TILE_SIZE 64
# define FOV 1.1

typedef struct	s_tex
{
	mlx_texture_t *n;
	mlx_texture_t *s;
	mlx_texture_t *w;
	mlx_texture_t *e;
}				t_tex;

typedef enum	e_side
{
	NORTH,
	SOUTH,
	WEST,
	EAST
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
	int	x;
	int	y;
	double	distance;
	t_side	side;
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
	char	**file;
	int		file_size;
	char	*texture_NO;//OK
	char	*texture_SO;//OK
	char	*texture_WE;//OK
	char	*texture_EA;//OK
	char	*color_F;
	char	*color_C;
	char	**map;
	char	**map_copy;
	int		map_rows;
	int		map_columns;
	int		player_X;//OK
	int		player_Y;//OK
	char	player_orientation;//OK
	/**/
	mlx_t		*mlx;
	t_tex		*tex;
	t_img		*img;
	t_ray		*ray;
	t_player	*ply;
	t_routes	*routes;
}				t_game;

/**/
void		free_error(char *msg, t_game *game);
void		init_data(t_game *game);
void		parse_ext(char *av);
void		get_file(t_game *game, char *file);
void		get_texture(t_game *game);
void		get_rgb(t_game *game);
void		get_map(t_game *game);
void		parse_map(t_game *g);
/**/
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
uint32_t	interpretate_color (char *color);
void		check_inits(t_game *g);
void		free_game(char *msg, t_game *g);

#endif