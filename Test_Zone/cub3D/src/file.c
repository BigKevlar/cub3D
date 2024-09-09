/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:34:55 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/09 20:42:08 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**/
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

/**/
void	get_file(t_game *g, char *file)
{
	int		fd;
	char	*line;
	int		i;

	file_size(g, file);
	if (g->file_size <= 1)
		free_error("ERROR! FILE EMPTY...", g);
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

/**/
void	get_tex_color(t_game *g)
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

/**/
int	get_textures(t_game *g, int i)
{
	char	*line;
	char	**tokens;
	int		flag;

	flag = 0;
	while (g->file[i] && g->file[i][0] == '\n')
		i++;
	if (!g->file[i])
		free_error("ERROR! TEXTURES EMPTY", g);
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
			if (g->texture_no || tokens[2])
			{
				ft_strd_free(tokens);
				free_error("ERROR! DUPLICATE TEXTURE IN FILE...", g);
			}
			g->texture_no = ft_strdup(tokens[1]);
			flag++;
		}
		else if (tokens[0] && ft_strcmp(tokens[0], "SO") == 0 && tokens[1])
		{
			if (g->texture_so || tokens[2])
			{
				ft_strd_free(tokens);
				free_error("ERROR! DUPLICATE TEXTURE IN FILE...", g);
			}
			g->texture_so = ft_strdup(tokens[1]);
			flag++;
		}
		else if (tokens[0] && ft_strcmp(tokens[0], "WE") == 0 && tokens[1])
		{
			if (g->texture_we || tokens[2])
			{
				ft_strd_free(tokens);
				free_error("ERROR! DUPLICATE TEXTURE IN FILE...", g);
			}
			g->texture_we = ft_strdup(tokens[1]);
			flag++;
		}
		else if (tokens[0] && ft_strcmp(tokens[0], "EA") == 0 && tokens[1])
		{
			if (g->texture_ea || tokens[2])
			{
				ft_strd_free(tokens);
				free_error("ERROR! DUPLICATE TEXTURE IN FILE...", g);
			}
			g->texture_ea = ft_strdup(tokens[1]);
			flag++;
		}
		else
		{
			ft_strd_free(tokens);
			free_error("ERROR! TEXTURES EMPTY", g);
		}
		ft_strd_free(tokens);
		i++;
	}
	if (!g->texture_no || !g->texture_so || !g->texture_we || !g->texture_ea)
		free_error("ERROR! MISSING SOME TEXTURE PATH...", g);
	return (i);
}

/**/
int	get_rgb(t_game *g, int i)
{
	char	*line;
	char	**tokens;
	int		flag;

	flag = 0;
	while (g->file[i] && g->file[i][0] == '\n')
		i++;
	if (!g->file[i])
		free_error("ERROR! RGB EMPTY", g);
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
			if (g->color_f || tokens[2])
			{
				ft_strd_free(tokens);
				free_error("ERROR! DUPLICATE COLOR IN FILE...", g);
			}
			g->color_f = ft_strdup(tokens[1]);
			flag++;
		}
		else if (tokens[0] && ft_strcmp(tokens[0], "C") == 0 && tokens[1])
		{
			if (g->color_c || tokens[2])
			{
				ft_strd_free(tokens);
				free_error("ERROR! DUPLICATE COLOR IN FILE...", g);
			}
			g->color_c = ft_strdup(tokens[1]);
			flag++;
		}
		else
		{
			ft_strd_free(tokens);
			free_error("ERROR! RGB EMPTY", g);
		}
		ft_strd_free(tokens);
		i++;
	}
	if (!g->color_f || !g->color_c)
		free_error("ERROR! MISSING SOME COLORS...", g);
	return (i);
}
