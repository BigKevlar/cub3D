/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:49:34 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/04 13:40:10 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	map_orientation(t_game *g)
{
	if (g->player_orientation == 'N')
		g->ply->angle = 3 * (M_PI / 2);
	else if (g->player_orientation == 'S')
		g->ply->angle = M_PI / 2;
	else if (g->player_orientation == 'E')
		g->ply->angle = 0;
	else if (g->player_orientation == 'S')
		g->ply->angle = M_PI;
}

void	init_player(t_game *g)
{
	map_orientation(g);
	g->ply->move_a = false;
	g->ply->move_d = false;
	g->ply->move_w = 0;
	g->ply->rotate = 0;
	g->ply->x = g->player_X * TILE_SIZE;
	g->ply->y = g->player_Y * TILE_SIZE;
}

void	init_data(t_game *game)
{
	game->mlx = NULL;
	game->img = NULL;
	game->tex = NULL;
	game->ply = malloc(sizeof(t_player));
	game->ray = malloc(sizeof(t_ray));
	game->routes = malloc(sizeof(t_routes));
	init_player(game);
}

void	init_struct(t_game *g)
{
	g->mlx = NULL;
	g->file = NULL;
	g->file_size = 0;
	g->texture_NO = NULL;
	g->texture_SO = NULL;
	g->texture_WE = NULL;
	g->texture_EA = NULL;
	g->color_F = NULL;
	g->color_C = NULL;	
	g->map = NULL;
	g->map_copy = NULL;
	g->map_rows = 0;
	g->map_columns = 0;
	g->player_X = 0;
	g->player_Y = 0;
	g->player_orientation = 0;
}


void	check_inits(t_game *g)
{
	if (!g->file || !g->texture_NO || !g->texture_SO
		|| !g->texture_WE || !g->texture_EA || !g->color_F || !g->color_C
		|| !g->map || !g->map_copy || !g->player_orientation
		|| !g->mlx || !g->tex || !g->img || !g->ray || !g->ply || !g->routes)
	{
		ft_strd_free(g->file);
		free(g->texture_NO);
		free(g->texture_SO);
		free(g->texture_WE);
		free(g->texture_EA);
		free(g->color_F);
		free(g->color_C);
		ft_strd_free(g->map);
		ft_strd_free(g->map_copy);
		free(g->mlx);
		free(g->tex);
		free(g->img);
		free(g->ray);
		free(g->ply);
		free(g->routes);
		ft_printf("ERROR! SOMETHINGS WRONG WITH DATAS, PLEASE TRY AGAIN...\n");
	}
}
