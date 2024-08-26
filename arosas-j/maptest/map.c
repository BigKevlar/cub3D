/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:42:27 by arosas-j          #+#    #+#             */
/*   Updated: 2024/08/26 17:37:42 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	init_struct(t_game *game)
{
	game->img = NULL;
	game->mlx = NULL;
	game->text = NULL;
	game->map = NULL;
	game->x = 500;
	game->y = 500;
	game->angle = 0;
	game->move_w = 0;
	game->move_a = false;
	game->move_d = false;
	game->rotate = 0;
}

static void	init_map(t_game *game)
{
	game->map = malloc(10 * sizeof(char *));
}

int	main(void)
{
	t_game game;
	
	init_struct(&game);
	game.mlx = mlx_init(S_W, S_H, "Map", false);
	get_textures(&game);
	get_images(&game);
	game_to_window(&game);
	mlx_key_hook(game.mlx, &ft_key_hook, &game);
	mlx_loop_hook(game.mlx, &ft_game_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	free(game.img);
	return (0);
}
