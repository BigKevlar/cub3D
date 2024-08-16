/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:32:30 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/16 19:03:22 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void    parse_map_file()
{
    
}

void	check_walls(t_game *game)
{
	int	c1;
	int	c2;

	c1 = 0;
	while (game->map[c1] != NULL)
	{
		c2 = 0;
		if (c1 == 0 || c1 == game->row_x - 1)
		{
			while (c2 < game->colum_y)
			{
				if (game->map[c1][c2] != '1')
					free_error("ERROR EN MUROS SUP./INF.", game);
				c2++;
			}
		}
		else if (game->map[c1][0] != '1'
		|| game->map[c1][game->y - 1] != '1')
			free_error("ERROR EN MUROS DER./IZQ.", game);
		c1++;
	}
}

t_game	*get_map(char *map)
{
	int		fd;
	char	*line;
	int		c;
	t_game	*game;
    
	c = 0;
	game = ft_calloc(1, sizeof(t_game));
	make_struct(game);
	game->map = ft_calloc(get_columns(map) + 1, sizeof(char *));
	fd = open(map, O_RDONLY);
	if (fd == -1)
		free_error("ERROR AL ABRIR MAPA", game);
	line = get_next_line(fd);
	while (line != NULL)
	{
		cont_objects(game, line);
		game->map[c] = line;
		line = get_next_line(fd);
		c++;
	}
	copy_map(game);
	objects_error(game);
	close(fd);
	return (game);
}
