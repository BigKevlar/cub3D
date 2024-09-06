/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:34:55 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/04 21:02:50 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	file_size(t_game *g, char *file)
{
	int		fd;
	char	*line;

	g->file_size = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		free_error("ERROR! FILE DOESN'T EXIST...", g);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		g->file_size++;
	}
	close(fd);
}

void	get_file(t_game *g, char *file)
{
	int		fd;
	char	*line;
	int		i;

	file_size(g, file);
	i = 0;
	g->file = ft_calloc(g->file_size + 1, sizeof(char *));
	if (!g->file)
		free_error("ERROR! FILE MEMORY ALLOCATION FAILED...", g);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		free_error("ERROR! FILE DOESN'T OPEN...", g);
	line = get_next_line(fd);
	while (line != NULL)
	{
		g->file[i] = line;
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	get_texture(t_game *g)
{
	int		i;
	int		j;
	char	*line;
	char	**tokens;

	i = 0;
	while (g->file[i])
	{
		line = ft_strtrim(g->file[i], " \t\n");
		if (!line)
			free_error("ERROR! MEMORY ALLOCATION FAILED...", g);
		tokens = ft_split(line, ' ');
		free(line);
		if (!tokens)
			free_error("ERROR! MEMORY ALLOCATION FAILED...", g);
		if (tokens[0] && ft_strcmp(tokens[0], "NO") == 0 && tokens[1])
			g->texture_NO = ft_strdup(tokens[1]);
		else if (tokens[0] && ft_strcmp(tokens[0], "SO") == 0 && tokens[1])
			g->texture_SO = ft_strdup(tokens[1]);
		else if (tokens[0] && ft_strcmp(tokens[0], "WE") == 0 && tokens[1])
			g->texture_WE = ft_strdup(tokens[1]);
		else if (tokens[0] && ft_strcmp(tokens[0], "EA") == 0 && tokens[1])
			g->texture_EA = ft_strdup(tokens[1]);
		j = 0;
		while (tokens[j])
		{
			free(tokens[j]);
			j++;
		}
		free(tokens);
		i++;
	}
	if (!g->texture_NO || !g->texture_SO || !g->texture_WE || !g->texture_EA)
		free_error("ERROR! MISSING SOME TEXTURE PATH...", g);
	// CHEQUEAMOS LAS TEXTURAS???
}

void	get_rgb(t_game *g)
{
	int		i;
	int		j;
	char	*line;
	char	**tokens;

	i = 0;
	while (g->file[i])
	{
		line = ft_strtrim(g->file[i], " \t\n");
		if (!line)
			free_error("ERROR! MEMORY ALLOCATION FAILED...", g);
		tokens = ft_split(line, ' ');
		free(line);
		if (!tokens)
			free_error("ERROR! MEMORY ALLOCATION FAILED...", g);
		if (tokens[0] && ft_strcmp(tokens[0], "F") == 0 && tokens[1])
			g->color_F = ft_strdup(tokens[1]);
		else if (tokens[0] && ft_strcmp(tokens[0], "C") == 0 && tokens[1])
			g->color_C = ft_strdup(tokens[1]);
		j = 0;
		while (tokens[j])
		{
			free(tokens[j]);
			j++;
		}
		free(tokens);
		i++;
	}
	if (!g->color_F || !g->color_C)
	{
		free_error("ERROR! MISSING SOME COLORS...", g);
	}
}

static void	fill_map(t_game *g)
{
	int	i;
	int	max_X;
	int	size_X;
	char *line;

	i = 0;
	max_X = 0;
	size_X = 0;
	while (g->map[i])
	{
		size_X = ft_strlen(g->map[i]);
		if (size_X > max_X)
			max_X = size_X;
		i++;
	}
	i = 0;
	while (g->map[i])
	{
		size_X = ft_strlen(g->map[i]);
		if (size_X < max_X)
		{
			line = ft_calloc(max_X + 1, sizeof(char));
			if (!line)
				free_error("ERROR! MEMORY ALLOCATION FAILED...", g);
			ft_memcpy(line, g->map[i], size_X);
			ft_memset(line + size_X, ' ', max_X - size_X);
			free(g->map[i]);
			g->map[i] = line;
		}
		i++;
	}
}

void	get_map(t_game *g)
{
	int		i;
	int		j;
	int		map_start;
	char	*line;

	i = 0;
	while (g->file[i])
	{
		j = 0;
		while (g->file[i][j]
			&& (g->file[i][j] == ' ' || g->file[i][j] == '\t'))
			j++;
		if (g->file[i][j] == '1')
			break;
		i++;
	}
    map_start = i;
    g->map_rows = g->file_size - map_start - 1;
    g->map = ft_calloc(g->map_rows + 1, sizeof(char *));
    g->map_copy = ft_calloc(g->map_rows + 1, sizeof(char *));
    if (!g->map || !g->map_copy)
        free_error("ERROR! MAP MEMORY ALLOCATION FAILED...", g);
    j = 0;
	while (g->file[i])
	{
		line = ft_strtrim(g->file[i], "\n");
		g->map[j] = ft_strdup(line);
		g->map_copy[j] = ft_strdup(line);
		free(line);
		if ((int)ft_strlen(g->file[i]) > g->map_columns)
			g->map_columns = ft_strlen(g->file[i]);
		if (!g->map[j] || !g->map_copy[j])
			free_error("ERROR! MAP MEMORY ALLOCATION FAILED...", g);
		i++;
		j++;
	}
	fill_map(g);
}
