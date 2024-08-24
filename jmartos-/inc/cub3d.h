/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:45:50 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/24 14:18:03 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "MLX42.h"

# define size_tileset 64 // Tamaño de los tilesets.
# define FOV 66 // Angulo de vision del jugador (mismo que en Wolfenstein3D).
# define W_MAP 1920
# define H_MAP 1080
# define W_MMAP 640
# define H_MMAP 480

typedef struct s_game
{
	mlx_t	*mlx;
	char	**file;
	int		file_size;
	char	*texture_NO;
	char	*texture_SO;
	char	*texture_WE;
	char	*texture_EA;
	char	*color_F;
	char	*color_C;
	char	**map;
	int		map_size_X;
	int		map_size_Y;
}	t_game;

/*
	FUNCIONES
*/
void	free_error(char *msg, t_game *game);
void	init_struct(t_game *game);
void	parse_ext(char *av);
void	get_file(t_game *game, char *file);
void	get_texture(t_game *game);
void	get_rgb(t_game *game);
void	get_map(t_game *game);

#endif