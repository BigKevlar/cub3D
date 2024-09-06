/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:18:47 by jmartos           #+#    #+#             */
/*   Updated: 2024/08/21 16:45:48 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* system("leaks -q so_long"); */

// Libreria 42 jmartos- y la MiniLibX_42.
# include "../libft/include/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

// Variables estaticas: tamaño de nuestros sprites.
# define X 64
# define Y 64

//
# define S_W 1000
# define TILE_SIZE 32

// Variables estaticas: colores.
# define BOLD		"\033[1m"
# define BLACK		"\033[30;1m"
# define RED		"\033[31;1m"
# define GREEN		"\033[32;1m"
# define YELLOW		"\033[33;1m"
# define BLUE		"\033[34;1m"
# define MAGENTA	"\033[35;1m"
# define CYAN		"\033[36;1m"
# define WHITE		"\033[37;1m"
# define END		"\033[0m"

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

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	char			**map_copy;
	int				rows;
	int				columns;
	char			player;
	double			pos_x;
	double			pos_y;
	double			move_x;
	double			move_y;
	char			coin;
	char			exit;
	int				num_players;
	mlx_image_t		*image_floor;
	mlx_image_t		*image_wall;
	mlx_image_t		*image_player;
	//
	

}					t_game;

// FREE.C
void	win_game(t_game *game);
void	close_game(t_game *game);
// ERROR.C
void	ft_charppfree(char **str);
void	free_error(char *msg, t_game *game);
void	player_error(t_game *game);
// SINTAX.C
void	parse_ext(char *av, t_game *game);
// MAP.C
t_game	*get_map(char *map);
// GAME.C
void	make_struct(t_game *game);
int		get_columns(char *map);
int32_t	init_game(t_game *game);
// IMAGES.C
void	loading_gui(t_game *game);
void	erasing_gui(t_game *game);
// DRAW.C
void	print_map(t_game *game, char **map);
void	gui(t_game *game);
// FLOOD_FILL.C
void	player_position(t_game *game);
void	flood_fill(t_game *game, int x, int y);
// MOVEMENTS.C
void	movement(mlx_key_data_t paramkey, t_game *game);
// MOVEMENTS_UTILS.C
void	action(t_game *game, int new_x, int new_y);
// RAYCAST.C
int		sign(double n);
bool	wall_hit(double x, double y, char **map);
double	get_v_distance(t_player *player, char **map, t_ray *ray);
double	get_h_distance(t_player *player, char **map, t_ray *ray);
void	raycast(t_player *player, char **map, t_ray *ray);
//void	render(ray);

#endif