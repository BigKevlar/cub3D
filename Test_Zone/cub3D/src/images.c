/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:57:36 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/06 17:08:56 by jmartos-         ###   ########.fr       */
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

void	get_images(t_game *game)
{
	game->img = ft_calloc(1, sizeof(t_img));
	game->img->minimap = NULL; //to_do
	free_textures(game->tex);
}

static uint32_t rgb_to_uint32(uint8_t r, uint8_t g, uint8_t b)
{
    uint32_t color = (r << 24) | (g << 16) | (b << 8) | 0xFF; // Assuming full opacity (alpha = 0xFF)
    return color;
}

static int check_comas(char *rgb)
{
	int	comas;
	int i;
	
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

uint32_t	interpretate_color (t_game *g, char *color)
{
	char	**RGB;
	int		red;
	int		green;
	int		blue;
	int		i;
	
	if (!check_comas(color))
		free_error("ERROR! COLORS FAIL.\n", g);
	RGB = ft_split(color, ',');
	if(ft_isdigit_str(RGB[0]) && RGB[0])
		red = ft_atoi(RGB[0]);
	if(ft_isdigit_str(RGB[1]))
		green = ft_atoi(RGB[1]);
	if(ft_isdigit_str(RGB[2]))
		blue = ft_atoi(RGB[2]);
		
	i = 0;
	while (RGB[i])
	{
		free (RGB[i]);
		i++;
	}
	free (RGB);
	return (rgb_to_uint32(red, green, blue));
}

double	get_colum(t_game *g)
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

uint32_t	get_pixel_color(t_game *g, int	size, int tex_colum)
{
	uint32_t	color;

	color = get_row_color(g, tex_colum, size);
	return (color);
}