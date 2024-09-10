/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:57:36 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/10 14:02:06 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**/
static uint32_t	rgb_to_uint32(uint8_t r, uint8_t g, uint8_t b)
{
	uint32_t	color;

	color = (r << 24) | (g << 16) | (b << 8) | 0xFF;
	return (color);
}

/**/
uint32_t	interpretate_color(t_game *g, char *color)
{
	char	**rgb;
	int		red;
	int		green;
	int		blue;
	int		i;

	if (!check_comas(color))
		free_error("ERROR! COLORS FAIL.\n", g);
	rgb = ft_split(color, ',');
	if (ft_isdigit_str(rgb[0]) && rgb[0])
		red = ft_atoi(rgb[0]);
	if (ft_isdigit_str(rgb[1]))
		green = ft_atoi(rgb[1]);
	if (ft_isdigit_str(rgb[2]))
		blue = ft_atoi(rgb[2]);
	i = 0;
	while (rgb[i])
	{
		free (rgb[i]);
		i++;
	}
	free (rgb);
	return (rgb_to_uint32(red, green, blue));
}

/**/
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

/**/
static uint32_t	get_row_color(t_game *g, int colum, int h)
{
	int			pix_h;
	uint32_t	color;
	uint32_t	*pixels;

	pixels = (uint32_t *)g->ray->tex->pixels;
	pix_h = g->ray->distance * g->ray->tex->height * h / (g->ratio);
	color = pixels[(pix_h * g->ray->tex->width) + colum / TILE_SIZE];
	color = reverse_bytes(color);
	return (color);
}

static uint32_t apply_shadow(uint32_t color, float shadow)
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;

	r = ((color >> 24) & 0xFF) * shadow;
	g = ((color >> 16) & 0xFF) * shadow;
	b = ((color >> 8) & 0xFF) * shadow;
	a = color & 0xFF;
	return ((r << 24) | (g << 16) | (b << 8) | a);
}
/**/
uint32_t	get_pixel_color(t_game *g, int size, int tex_colum)
{
	uint32_t	color;
	float shadow;

	color = get_row_color(g, tex_colum, size);
	shadow = 1.0f / (1.0f + g->ray->distance * 0.005f);
	color = apply_shadow(color, shadow);
	return (color);
}
