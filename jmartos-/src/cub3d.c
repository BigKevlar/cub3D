/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:35:05 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/24 14:18:42 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_struct(t_game *game)
{
	game->mlx = NULL;
	game->file = NULL;
	game->file_size = 0;
	game->texture_NO = NULL;
	game->texture_SO = NULL;
	game->texture_WE = NULL;
	game->texture_EA = NULL;
	game->color_F = NULL;
	game->color_C = NULL;
	game->map = NULL;
	game->map_size_X = 0;
	game->map_size_Y = 0;
}

int	main(int ac, char **av)
{
	t_game	*game;

	if ((ac != 2) || (ac == 2 && av[1] == NULL))
		free_error("ERROR! WRONG ARGUMENTS SINTAXIS...", NULL);
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (0);
	parse_ext(av[1]);
	init_struct(game);
	get_file(game, av[1]);
	get_texture(game);
	get_rgb(game);
	get_map(game);
	free_error("THE END", game);
	return (0);
}

/*
	void	*mlx_connection;

	mlx_connection = mlx_init(W_MAP, H_MAP, "cub3D", false);
	//CODIGO
	mlx_loop(mlx_connection);
	return (0);
*/