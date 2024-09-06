/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:34:55 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/06 20:18:28 by jmartos-         ###   ########.fr       */
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

void	choose_tex_color(t_game *g)
{
	int	i;

	i = 0;
	while (g->file[i][0] == '\n')
		i++;
	if (g->file[i][0] == 'F' || g->file[i][0] == 'C')
	{
		i = get_rgb(g, i);
		i = get_textures(g, i);
	}
	else
	{
		i = get_textures(g, i);
		i = get_rgb(g, i);
	}
	get_map(g, i);
}

int	get_textures(t_game *g, int i)
{
	int		j;
	char	*line;
	char	**tokens;
	int		flag;

	flag = 0;
	while (g->file[i][0] == '\n')
		i++;
	while (g->file[i] && flag != 4)
	{
		line = ft_strtrim(g->file[i], " \n");
		if (!line)
			free_error("ERROR! MEMORY ALLOCATION FAILED...", g);
		tokens = ft_split(line, ' ');
		free(line);
		if (!tokens)
			free_error("ERROR! MEMORY ALLOCATION FAILED...", g);
		if (tokens[0] && ft_strcmp(tokens[0], "NO") == 0 && tokens[1])
		{
			if (g->texture_NO)
				free_error("ERROR! DUPLICATE TEXTURE IN FILE...", g);
			g->texture_NO = ft_strdup(tokens[1]);
			flag++;
		}
		else if (tokens[0] && ft_strcmp(tokens[0], "SO") == 0 && tokens[1])
		{
			if (g->texture_SO)
				free_error("ERROR! DUPLICATE TEXTURE IN FILE...", g);
			g->texture_SO = ft_strdup(tokens[1]);
			flag++;
		}
		else if (tokens[0] && ft_strcmp(tokens[0], "WE") == 0 && tokens[1])
		{
			if (g->texture_WE)
				free_error("ERROR! DUPLICATE TEXTURE IN FILE...", g);
			g->texture_WE = ft_strdup(tokens[1]);
			flag++;
		}
		else if (tokens[0] && ft_strcmp(tokens[0], "EA") == 0 && tokens[1])
		{
			if (g->texture_EA)
				free_error("ERROR! DUPLICATE TEXTURE IN FILE...", g);
			g->texture_EA = ft_strdup(tokens[1]);
			flag++;
		}
		else
			free_error("ERROR! INVALID ELEMENT IN FILE...", g);
		j = 0;
		while (tokens[j])
			free(tokens[j++]);
		free(tokens);
		i++;
	}
	if (!g->texture_NO || !g->texture_SO || !g->texture_WE || !g->texture_EA)
		free_error("ERROR! MISSING SOME TEXTURE PATH...", g);
	return (i);
}

int	get_rgb(t_game *g, int i)
{
	int		j;
	char	*line;
	char	**tokens;
	int		flag;

	flag = 0;
	while (g->file[i][0] == '\n')
		i++;
	while (g->file[i] && flag != 2)
	{
		line = ft_strtrim(g->file[i], " \n");
		if (!line)
			free_error("ERROR! MEMORY ALLOCATION FAILED...", g);
		tokens = ft_split(line, ' ');
		free(line);
		if (!tokens)
			free_error("ERROR! MEMORY ALLOCATION FAILED...", g);
		if (tokens[0] && ft_strcmp(tokens[0], "F") == 0 && tokens[1])
		{
			if (g->color_F)
				free_error("ERROR! DUPLICATE COLOR IN FILE...", g);
			g->color_F = ft_strdup(tokens[1]);
			flag++;
		}
		else if (tokens[0] && ft_strcmp(tokens[0], "C") == 0 && tokens[1])
		{
			if (g->color_C)
				free_error("ERROR! DUPLICATE COLOR IN FILE...", g);
			g->color_C = ft_strdup(tokens[1]);
			flag++;
		}
		else
			free_error("ERROR! INVALID ELEMENT IN FILE...", g);
		j = 0;
		while (tokens[j])
			free(tokens[j++]);
		free(tokens);
		i++;
	}
	if (!g->color_F || !g->color_C)
		free_error("ERROR! MISSING SOME COLORS...", g);
	return (i);
}
