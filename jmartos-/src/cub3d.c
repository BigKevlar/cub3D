/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:35:05 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/28 21:57:36 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_struct(t_game *g)
{
	g->mlx = NULL;
	g->file = NULL;
	g->file_size = 0;
	g->texture_NO = NULL;
	g->texture_SO = NULL;
	g->texture_WE = NULL;
	g->texture_EA = NULL;
	g->color_F = NULL;
	g->color_C = NULL;
	g->map = NULL;
	g->map_copy = NULL;
	g->map_rows = 0;
	g->map_columns = 0;
	g->player_X = 0;
	g->player_Y = 0;
	g->player_orientation = 0;
}

int	main(int ac, char **av)
{
	t_game	*g;

	if ((ac != 2) || (ac == 2 && av[1] == NULL))
		free_error("ERROR! WRONG ARGUMENTS SINTAXIS...", NULL);
	g = ft_calloc(1, sizeof(t_game));
	if (!g)
		return (0);
	parse_ext(av[1]);
	init_struct(g);
	get_file(g, av[1]);
	get_texture(g);
	get_rgb(g);
	get_map(g);
	parse_map(g);
	free_error("THE END", g);
	return (0);
}
