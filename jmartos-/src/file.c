/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:34:55 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/24 16:49:15 by jmartos-         ###   ########.fr       */
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
		free_error("ERROR! FILE DOESN'T EXIST...", game);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		game->file_size++;
	}
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
		game->file[i] = line;
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	get_texture(t_game *game)
{
	int		i;
	int		j;
	char	*line;
	char	**tokens;

	i = 0;
	while (game->file[i])
	{
		line = ft_strtrim(game->file[i], " \t\n");
		if (!line)
			free_error("ERROR! MEMORY ALLOCATION FAILED...", game);
		tokens = ft_split(line, ' ');
		free(line);
		if (!tokens)
			free_error("ERROR! MEMORY ALLOCATION FAILED...", game);
		if (tokens[0] && ft_strcmp(tokens[0], "NO") == 0 && tokens[1])
		{
			game->texture_NO = ft_strdup(tokens[1]);
			ft_printf("*** NO DEBUG PRINT: %s\n", game->texture_NO);
		}
		else if (tokens[0] && ft_strcmp(tokens[0], "SO") == 0 && tokens[1])
		{
			game->texture_SO = ft_strdup(tokens[1]);
			ft_printf("*** SO DEBUG PRINT: %s\n", game->texture_SO);
		}
		else if (tokens[0] && ft_strcmp(tokens[0], "WE") == 0 && tokens[1])
		{
			game->texture_WE = ft_strdup(tokens[1]);
			ft_printf("*** WE DEBUG PRINT: %s\n", game->texture_WE);
		}
		else if (tokens[0] && ft_strcmp(tokens[0], "EA") == 0 && tokens[1])
		{
			game->texture_EA = ft_strdup(tokens[1]);
			ft_printf("*** EA DEBUG PRINT: %s\n", game->texture_EA);
		}
		j = 0;
		while (tokens[j])
		{
			free(tokens[j]);
			j++;
		}
		free(tokens);
		i++;
	}
	if (!game->texture_NO || !game->texture_SO || !game->texture_WE || !game->texture_EA)
	{
		free_error("ERROR! MISSING SOME TEXTURE PATH...", game);
	}
}

void	get_rgb(t_game *game)
{
	int		i;
	int		j;
	char	*line;
	char	**tokens;

	i = 0;
	while (game->file[i])
	{
		line = ft_strtrim(game->file[i], " \t\n");
		if (!line)
			free_error("ERROR! MEMORY ALLOCATION FAILED...", game);
		tokens = ft_split(line, ' ');
		free(line);
		if (!tokens)
			free_error("ERROR! MEMORY ALLOCATION FAILED...", game);
		if (tokens[0] && ft_strcmp(tokens[0], "F") == 0 && tokens[1])
		{
			game->color_F = ft_strdup(tokens[1]);
			ft_printf("*** F DEBUG PRINT: %s\n", game->color_F);
		}
		else if (tokens[0] && ft_strcmp(tokens[0], "C") == 0 && tokens[1])
		{
			game->color_C = ft_strdup(tokens[1]);
			ft_printf("*** C DEBUG PRINT: %s\n", game->color_C);
		}
		j = 0;
		while (tokens[j])
		{
			free(tokens[j]);
			j++;
		}
		free(tokens);
		i++;
	}
	if (!game->color_F || !game->color_C)
	{
		free_error("ERROR! MISSING SOME COLORS...", game);
	}
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
			if (!line)
				free_error("ERROR! MEMORY ALLOCATION FAILED...", game);
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
	char	*line;

	i = 0;
	while (game->file[i])
	{
		j = 0;
		while (game->file[i][j]
			&& (game->file[i][j] == ' ' || game->file[i][j] == '\t'))
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
		line = ft_strtrim(game->file[i], "\n");
		game->map[j] = ft_strdup(line);
		free(line);
		if (!game->map[j])
			free_error("ERROR! MAP MEMORY ALLOCATION FAILED...", game);
		i++;
		j++;
	}
	fill_map(game);
}
