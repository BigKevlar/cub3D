/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 00:08:34 by jmartos           #+#    #+#             */
/*   Updated: 2024/09/05 18:28:03 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
/*
static void print_map_copy(t_game *g) // DEBUG FT_PRINTF.
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
*/
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
				g->player_orientation = g->map_copy[g->player_Y][g->player_X];
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
		|| (g->map_copy[y][x] != '1' && g->map_copy[y][x] != '2' 
		&& g->map_copy[y][x] != 'X'	&& g->map_copy[y][x] != '0'))
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
	//print_map_copy(g); // DEBUG FT_PRINTF.
	if (flood_fill(g, g->player_X, g->player_Y))
		free_error("ERROR! MAP HAS OPEN AREA...", g);
	//print_map_copy(g); // DEBUG FT_PRINTF.
	i = 0;
	while (g->map_copy[i])
	{
		j = 0;
		while (g->map_copy[i][j])
		{
			if (g->map_copy[i][j] == '0')
				if (flood_fill(g, j, i))
					free_error("ERROR! MAP HAS OPEN AREA...", g);
			j++;
		}
		i++;
	}
	//ft_printf("PARSE MAP OK!\n"); // DEBUG FT_PRINTF.
}
