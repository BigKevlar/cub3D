/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 00:08:34 by jmartos           #+#    #+#             */
/*   Updated: 2024/09/09 17:05:50 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**/
void	player_position(t_game *g)
{
	int	c1;
	int	c2;

	c1 = 0;
	while (g->map[c1])
	{
		c2 = 0;
		while (g->map[c1][c2])
		{
			if (g->map[c1][c2] == 'N' || g->map[c1][c2] == 'S'
				|| g->map[c1][c2] == 'E' || g->map[c1][c2] == 'W')
			{
				g->player_y = c1;
				g->player_x = c2;
				g->player_orientation = g->map[g->player_y][g->player_x];
				g->map[g->player_y][g->player_x] = '0';
				return ;
			}
			c2++;
		}
		c1++;
	}
}

/**/
static int	check_zero(t_game *g, int y, int x)
{
	if (x <= 0 || y <= 0
		|| x >= g->map_columns || y >= g->map_rows - 1)
	{
		printf("x: %d\n", x);
		printf("char: %c\n", g->map[y][x]);
		return (0);
	}
	if (!g->map[y + 1][x]
		|| g->map[y + 1][x] == ' '
		|| g->map[y - 1][x] == ' '
		|| !g->map[y][x + 1]
		|| g->map[y][x + 1] == ' '
		|| g->map[y][x - 1] == ' ')
		return (0);
	return (1);
}

/**/
void	check_map(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			if (g->map[y][x] == '0')
			{
				if (!check_zero(g, y, x))
					free_error("ERROR! MAP HAS OPEN AREA...", g);
			}
			x++;
		}
		y++;
	}
}
