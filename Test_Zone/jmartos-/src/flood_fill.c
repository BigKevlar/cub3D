/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 00:08:34 by jmartos           #+#    #+#             */
/*   Updated: 2024/08/28 22:29:56 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void print_map_copy(t_game *g)
{
	int i;

	i = 0;
	while (i < g->map_rows)
	{
		ft_printf("%s\n", g->map_copy[i]);
		i++;
	}
	ft_printf("\n");
}

//
static void player_position(t_game *g)
{
	int c1;
	int c2;

	c1 = 0;
	while (g->map_copy[c1])
	{
		c2 = 0;
		while (g->map_copy[c1][c2])
		{
			if (g->map_copy[c1][c2] == 'N' || g->map_copy[c1][c2] == 'S' || g->map_copy[c1][c2] == 'E' || g->map_copy[c1][c2] == 'W')
			{
				g->player_Y = c1;
				g->player_X = c2;
				ft_printf("PLAYER_POSITION: posición del jugador = [%d][%d]\n", g->player_X, g->player_Y);
				g->player_orientation = g->map_copy[g->player_Y][g->player_X];
				ft_printf("PLAYER_POSITION: player_orientation = %c\n", g->player_orientation);
				g->map_copy[g->player_Y][g->player_X] = '0';
				return;
			}
			c2++;
		}
		c1++;
	}
}

//
static int flood_fill(t_game *g, int x, int y)
{
	//ft_printf("test\n");
	if (x < 0 || y < 0 || y > g->map_rows || x > g->map_columns 
		|| (g->map_copy[y][x] != '1' && g->map_copy[y][x] != 'X'
		&& g->map_copy[y][x] != '0'))
			return (1);
	if (g->map_copy[y][x] == '1' || g->map_copy[y][x] == 'X')
			return (0);
	g->map_copy[y][x] = 'X';
	if (flood_fill(g, x - 1, y)
		|| flood_fill(g, x + 1, y)
		|| flood_fill(g, x, y - 1)
		|| flood_fill(g, x, y + 1))
		return (1);
	return (0);
}

//
void parse_map(t_game *g)
{
	int i;
	int j;

	player_position(g);
	ft_printf("PARSE_MAP: g->map_rows = %i:\n", g->map_rows);
	ft_printf("PARSE_MAP: g->map_columns = %i:\n", g->map_columns);
	ft_printf("PARSE_MAP: Mapa antes de flood_fill:\n");
	print_map_copy(g);
	if (flood_fill(g, g->player_X, g->player_Y))
		free_error("ERROR_1! MAP HAS OPEN AREA...", g);
	ft_printf("PARSE_MAP: g->map_rows = %i:\n", g->map_rows);
	ft_printf("PARSE_MAP: g->map_columns = %i:\n", g->map_columns);
	ft_printf("PARSE_MAP: Mapa después de flood_fill:\n");
	print_map_copy(g);
	// ENCONTRAR 0 Y HACER FLOOD_FILL
	i = 0;
	while (g->map_copy[i])
	{
		j = 0;
		while (g->map_copy[i][j])
		{
			if (g->map_copy[i][j] == '0')
				if (flood_fill(g, j, i))
					free_error("ERROR_2! MAP HAS OPEN AREA...", g);
			j++;
		}
		i++;
	}
	ft_printf("PARSE_MAP: el jugador y el mapa estan cerrados. Todo OK!\n");
}
