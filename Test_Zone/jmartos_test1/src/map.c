/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:50:28 by jmartos           #+#    #+#             */
/*   Updated: 2024/08/19 19:01:17 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//
static void	copy_map(t_game *game)
{
	int	c;

	c = 0;
	while (game->map[c] != NULL)
	{
		game->map_copy[c] = ft_strdup(game->map[c]);
		c++;
	}
}

//
void	get_form(t_game *game)
{
	int	c;

	game->columns = ft_strlen(game->map[0]) - 1;
	c = 0;
	while (game->map[c] != NULL)
		c++;
	game->rows = c;
}

//
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
	game->map_copy = ft_calloc(get_columns(map) + 1, sizeof(char *));
	fd = open(map, O_RDONLY);
	if (fd == -1)
		free_error("ERROR AL ABRIR MAPA", game);
	line = get_next_line(fd);
	while (line != NULL)
	{
		game->map[c] = line;
		line = get_next_line(fd);
		c++;
	}
	get_form(game);
	copy_map(game);
	close(fd);
	return (game);
}
