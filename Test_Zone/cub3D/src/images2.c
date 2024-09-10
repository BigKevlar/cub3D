/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 20:35:29 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/10 18:05:08 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**/
void	init_textures(t_game *g)
{
	g->tex->n = NULL;
	g->tex->s = NULL;
	g->tex->e = NULL;
	g->tex->w = NULL;
	g->tex->door = NULL;
	g->tex->n = mlx_load_png(g->texture_no);
	g->tex->s = mlx_load_png(g->texture_so);
	g->tex->e = mlx_load_png(g->texture_ea);
	g->tex->w = mlx_load_png(g->texture_we);
	g->tex->door = mlx_load_png("tex/Door.png");
	if (!g->tex->n || !g->tex->s || !g->tex->e || !g->tex->w || !g->tex->door)
	{
		free_error("ERROR! LOADING TEXTURES FAIL...\n", g);
	}
}

/**/
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
