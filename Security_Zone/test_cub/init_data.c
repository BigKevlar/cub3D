/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:49:34 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/02 18:49:32 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3D.h"

char	**get_map(void)
{
	char	**map;

	map = calloc(10, sizeof(char *));
	map[0] = ft_strdup("1111111111111111111111111");
	map[1] = ft_strdup("1000000000000000000100001");
	map[2] = ft_strdup("1001000000000P00000000001");
	map[3] = ft_strdup("1001000000000000001000001");
	map[4] = ft_strdup("1001000000000100001000001");
	map[5] = ft_strdup("1001000000100000001000001");
	map[6] = ft_strdup("1001000000000000001000001");
	map[7] = ft_strdup("1001000000001000001000001");
	map[8] = ft_strdup("1111111111111111111111111");
	map[9] = NULL;
	return (map);
}

void	init_player(t_game *g)
{
	g->ply->angle = 0;
	g->ply->move_a = false;
	g->ply->move_d = false;
	g->ply->move_w = 0;
	g->ply->rotate = 0;
	g->ply->x = 12 * TILE_SIZE;
	g->ply->y = 2 * TILE_SIZE;
}

void	init_data(t_game *game)
{
	game->mlx = NULL;
	game->img = NULL;
	game->tex = NULL;
	game->ply = malloc(sizeof(t_player));
	game->ray = malloc(sizeof(t_ray));
	game->map = get_map();
	init_player(game);
}