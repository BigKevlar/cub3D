/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:35:05 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/17 21:58:02 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(void)
{
	t_game	*game;
	
	game = init_game();
	// LEER EL MAPA Y PONERLO EN GAME->MAP.
	game->map = ft_split(map, '\n');
	mlx_hook(game->window, 17, 0, exit_game, game);
	mlx_key_hook(game->window, key_press, game);
	update_game(game);
	mlx_loop(game->mlx);
	return (0);
}

/*
int	main(void)
{
	void	*mlx_connection;

	mlx_connection = mlx_init(300, 300, "cub3D", false);
	mlx_loop(mlx_connection);
	return (0);
}
*/