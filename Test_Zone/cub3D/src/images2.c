/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 20:35:29 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/06 20:36:29 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	free_textures(t_tex *textures)
{
	mlx_delete_texture(textures->n);
	mlx_delete_texture(textures->s);
	mlx_delete_texture(textures->e);
	mlx_delete_texture(textures->w);
	free(textures);
}

void	init_textures(t_game *game)
{
	game->tex = ft_calloc(1, sizeof(t_tex));
	game->tex->n = mlx_load_png(game->texture_NO);
	game->tex->s = mlx_load_png(game->texture_SO);
	game->tex->e = mlx_load_png(game->texture_WE);
	game->tex->w = mlx_load_png(game->texture_EA);
	if (!game->tex->w || !game->tex->s || !game->tex->e || !game->tex->w)
		free_error("ERROR! LOADING TEXTURES FAIL.\n", game);
	game->tex->door = mlx_load_png("tex/Door.png");
}

int	check_comas(char *rgb)
{
	int	comas;
	int	i;

	i = 0;
	comas = 0;
	while (rgb[i])
	{
		if (rgb[i] == ',')
			comas++;
		i++;
	}
	if (comas == 2)
		return (1);
	else
		return (0);
}
