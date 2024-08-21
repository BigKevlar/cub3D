/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:18:47 by jmartos           #+#    #+#             */
/*   Updated: 2024/08/19 20:02:20 by jmartos-         ###   ########.fr       */
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

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	char			**map_copy;
	int				rows;
	int				columns;
	char			player;
	int				pos_x;
	int				pos_y;
	int				move_x;
	int				move_y;
	char			coin;
	char			exit;
	int				num_players;
	mlx_image_t		*image_floor;
	mlx_image_t		*image_wall;
	mlx_image_t		*image_player;

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

#endif