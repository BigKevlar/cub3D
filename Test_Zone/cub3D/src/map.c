/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 20:18:05 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/09 19:02:44 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**/
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

/**/
double	get_colum(t_game *g)
{
	double	colum;

	colum = 0;
	if (g->ray->side == SOUTH)
	{
		g->ray->x = fmod(g->ray->x, TILE_SIZE);
		colum = g->ray->x;
	}
	else if (g->ray->side == NORTH)
	{
		g->ray->x = fmod(g->ray->x, TILE_SIZE);
		colum = TILE_SIZE - g->ray->x;
	}
	else if (g->ray->side == WEST)
	{
		g->ray->y = fmod(g->ray->y, TILE_SIZE);
		colum = TILE_SIZE - g->ray->y;
	}
	else if (g->ray->side == EAST)
	{
		g->ray->y = fmod(g->ray->y, TILE_SIZE);
		colum = g->ray->y;
	}
	return ((colum * g->ray->tex->width));
}

/**/
static void	fill_map(t_game *g)
{
	int		i;
	int		max_x;
	int		size_x;
	char	*line;

	i = 0;
	max_x = 0;
	size_x = 0;
	while (g->map[i])
	{
		size_x = ft_strlen(g->map[i]);
		if (size_x > max_x)
			max_x = size_x;
		i++;
	}
	i = 0;
	while (g->map[i])
	{
		size_x = ft_strlen(g->map[i]);
		if (size_x < max_x)
		{
			line = ft_calloc(max_x + 1, sizeof(char));
			if (!line)
				free_error("ERROR! FILL MAP FAILED...", g);
			ft_memcpy(line, g->map[i], size_x);
			ft_memset(line + size_x, ' ', max_x - size_x);
			free(g->map[i]);
			g->map[i] = line;
		}
		i++;
	}
}

/**/
void	get_map(t_game *g, int i)
{
	int		j;
	int		map_start;
	char	*line;

	while (g->file[i] && g->file[i][0] == '\n')
		i++;
	if (!g->file[i])
		free_error("ERROR! MAP EMPTY", g);
	while (g->file[i])
	{
		j = 0;
		while (g->file[i][j] && g->file[i][j] == ' ')
			j++;
		if (g->file[i][j] != '1')
			free_error("ERROR! INVALID MAP...", g);
		else
			break ;
		i++;
	}
	map_start = i;
	g->map_rows = g->file_size - map_start - 1;
	g->map = ft_calloc(g->map_rows + 1, sizeof(char *));
	if (!g->map)
		free_error("ERROR! MAP MEMORY ALLOCATION FAILED...", g);
	j = 0;
	while (g->file[i])
	{
		line = ft_strtrim(g->file[i], "\n");
		g->map[j] = ft_strdup(line);
		free(line);
		if ((int)ft_strlen(g->file[i]) > g->map_columns)
			g->map_columns = ft_strlen(g->file[i]);
		if (!g->map[j])
			free_error("ERROR! MAP MEMORY ALLOCATION FAILED...", g);
		i++;
		j++;
	}
	fill_map(g);
}
