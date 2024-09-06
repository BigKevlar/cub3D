/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 00:08:34 by jmartos           #+#    #+#             */
/*   Updated: 2024/09/06 20:25:56 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	print_map_copy(t_game *g) // DEBUG FT_PRINTF.
{
	int	i;

	i = 0;
	while (i < g->map_rows)
	{
		ft_printf("%s\n", g->map_copy[i]);
		i++;
	}
	ft_printf("\n");
}

//
void	player_position(t_game *g)
{
	int	c1;
	int	c2;

	c1 = 0;
	while (g->map_copy[c1])
	{
		c2 = 0;
		while (g->map_copy[c1][c2])
		{
			if (g->map_copy[c1][c2] == 'N' || g->map_copy[c1][c2] == 'S'
				|| g->map_copy[c1][c2] == 'E' || g->map_copy[c1][c2] == 'W')
			{
				g->player_Y = c1;
				g->player_X = c2;
				g->player_orientation = g->map_copy[g->player_Y][g->player_X];
				g->map_copy[g->player_Y][g->player_X] = '0';
				return ;
			}
			c2++;
		}
		c1++;
	}
}

static int	check_zero(char **map, int x, int y)
{
	if (x <= 0 || y <= 0)
		return (0);
	if (!map[y + 1][x] || map[y + 1][x] == ' ' || map[y - 1][x] == ' '
		|| !map[y][x + 1] || map[y][x + 1] == ' ' || map[y][x - 1] == ' ')
		return (0);
	return (1);
}

void	check_close(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (g->map_copy[y])
	{
		x = 0;
		while (g->map_copy[y][x])
		{
			if (g->map_copy[y][x] == '0')
			{
				if (!check_zero(g->map_copy, x, y))
					free_error("ERROR! MAP HAS OPEN AREA...", g);
			}
			x++;
		}
		y++;
	}
}
