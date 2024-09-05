/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:57:36 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/05 20:00:55 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3D.h"



void	get_textures(t_game *game)
{
	game->tex = ft_calloc(1, sizeof(t_tex));
	game->tex->n = mlx_load_png("Textures/Mona_Lisa.png");
	game->tex->s = mlx_load_png("Textures/Mona_Lisa.png");
	game->tex->e = mlx_load_png("Textures/Mona_Lisa.png");
	game->tex->w = mlx_load_png("Textures/Mona_Lisa.png");
}

static double	get_colum(t_game *g)
{
	double colum;

	colum = 0;
	if (g->ray->side == SOUTH)
	{
		g->ray->x = fmod(g->ray->x, TILE_SIZE);
		colum = g->ray->x;
	}
	else if (g->ray->side == NORTH)
	{
		g->ray->x = fmod(g->ray->x, TILE_SIZE);
		colum =  TILE_SIZE - g->ray->x;
	}
	else if (g->ray->side == WEST)
	{
		g->ray->y = fmod(g->ray->y, TILE_SIZE);
		colum = TILE_SIZE - g->ray->y;
	}
	else if (g->ray->side == EAST)
	{
		g->ray->y = fmod(g->ray->y, TILE_SIZE);
		colum = g->ray->y;
	}
	return ((colum * g->ray->tex->width));
}

static int	reverse_bytes(int c)
{
	unsigned int	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
}

static uint32_t	get_row_color(t_game *g, int colum, int h)
{
	int			pix_h;
	uint32_t	color;
	uint32_t	*pixels;

	pixels = (uint32_t *)g->ray->tex->pixels;
	pix_h = g->ray->distance * g->ray->tex->height * h /(g->ratio);
	color = pixels[(pix_h * g->ray->tex->width) + colum / TILE_SIZE];
	color = reverse_bytes(color);
	return (color);
}

uint32_t	get_pixel_color(t_game *g, int	size)
{
	int	tex_colum;
	uint32_t	color;

	tex_colum = get_colum(g);
	color = get_row_color(g, tex_colum, size);
	return (color);
}