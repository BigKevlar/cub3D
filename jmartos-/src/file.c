/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:34:55 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/24 13:12:29 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	file_size(t_game *game, char *file)
{
	int		fd;
	char	*line;

	game->file_size = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		free_error("ERROR! FILE DOESN'T OPEN...", game);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		game->file_size++;
	}
	ft_printf("*** DEBUG PRINT Nº2: %i\n", game->file_size);
	close(fd);
}

void	get_file(t_game *game, char *file)
{
	int		fd;
	char	*line;
	int		i;

	file_size(game, file);
	i = 0;
	game->file = ft_calloc(game->file_size + 1, sizeof(char *));
	if (!game->file)
		free_error("ERROR! FILE MEMORY ALLOCATION FAILED...", game);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		free_error("ERROR! FILE DOESN'T OPEN...", game);
	line = get_next_line(fd);
	while (line != NULL)
	{
		ft_printf("*** DEBUG PRINT Nº3: %s", line);
		game->file[i] = line;
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	get_texture(t_game *game)
{
	int	i;

	i = 0;
	while (game->file[i])
	{
		if (ft_strncmp(game->file[i], "NO ", 3) == 0)
		{
			game->texture_NO = ft_strdup(game->file[i] + 3);
			ft_printf("\n*** DEBUG PRINT Nº4: %s", game->texture_NO);
		}
		else if (ft_strncmp(game->file[i], "SO ", 3) == 0)
		{
			game->texture_SO = ft_strdup(game->file[i] + 3);
			ft_printf("*** DEBUG PRINT Nº5: %s", game->texture_SO);
		}
		else if (ft_strncmp(game->file[i], "WE ", 3) == 0)
		{
			game->texture_WE = ft_strdup(game->file[i] + 3);
			ft_printf("*** DEBUG PRINT Nº6: %s", game->texture_WE);
		}
		else if (ft_strncmp(game->file[i], "EA ", 3) == 0)
		{
			game->texture_EA = ft_strdup(game->file[i] + 3);
			ft_printf("*** DEBUG PRINT Nº7: %s", game->texture_EA);
		}
		i++;
	}
	if (!game->texture_NO || !game->texture_SO
		|| !game->texture_WE || !game->texture_EA)
		free_error("ERROR! MISSING SOME TEXTURE PATH...", game);
}

void	get_rgb(t_game *game)
{
	int i;

	i = 0;
	while (game->file[i])
	{
		if (ft_strncmp(game->file[i], "F ", 2) == 0)
		{
			game->color_F = ft_strdup(game->file[i] + 2);
			ft_printf("*** DEBUG PRINT Nº8: %s", game->color_F);
		}
		else if (ft_strncmp(game->file[i], "C ", 2) == 0)
		{
			game->color_C = ft_strdup(game->file[i] + 2);
			ft_printf("*** DEBUG PRINT Nº9: %s", game->color_C);
		}
		i++;
	}
	if (!game->color_F || !game->color_C)
		free_error("ERROR! MISSING SOME COLORS...", game);
}

static void	fill_map(t_game *game)
{
	int	i;
	int	max_X;
	int	size_X;
	char *line;

	i = 0;
	max_X = 0;
	size_X = 0;
	while (game->map[i])
	{
		size_X = ft_strlen(game->map[i]);
		if (size_X > max_X)
			max_X = size_X;
		i++;
	}
	i = 0;
	while (game->map[i])
	{
		size_X = ft_strlen(game->map[i]);
		if (size_X < max_X)
		{
			line = ft_calloc(max_X + 1, sizeof(char));
			ft_memcpy(line, game->map[i], size_X);
			ft_memset(line + size_X, ' ', max_X - size_X);
			free(game->map[i]);
			game->map[i] = line;
		}
		i++;
	}
}

void	get_map(t_game *game)
{
	int		i;
	int		j;
	int		map_start;

	i = 0;
	while (game->file[i])
	{
		j = 0;
		while (game->file[i][j] && (game->file[i][j] == ' ' || game->file[i][j] == '\t'))
			j++;
		if (game->file[i][j] == '1')
			break;
		i++;
	}
	map_start = i;
	game->map = ft_calloc(game->file_size - map_start + 1, sizeof(char *));
	if (!game->map)
		free_error("ERROR! MAP MEMORY ALLOCATION FAILED...", game);
	j = 0;
	while (game->file[i])
	{
		game->map[j] = ft_strdup(game->file[i]);
		if (!game->map[j])
			free_error("ERROR! MAP MEMORY ALLOCATION FAILED...", game);
		i++;
		j++;
	}
	fill_map(game);
	i = 0;
	while (game->map[i])
	{
		ft_printf("*** DEBUG PRINT Nº10: %s", game->map[i]);
		i++;
	}
}
