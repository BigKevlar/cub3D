/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:57:36 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/03 18:21:15 by jmartos-         ###   ########.fr       */
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

void	get_textures(t_game *game)
{
	game->routes->n = game->texture_NO;
	game->routes->s = game->texture_SO;
	game->routes->e = game->texture_WE;
	game->routes->w = game->texture_EA;
	game->tex = ft_calloc(1, sizeof(t_tex));
	game->tex->n = mlx_load_png(game->routes->n);
	game->tex->s = mlx_load_png(game->routes->s);
	game->tex->e = mlx_load_png(game->routes->e);
	game->tex->w = mlx_load_png(game->routes->w);
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

uint32_t	interpretate_color (char *color)
{
	char	**RGB;
	int		red;
	int		green;
	int		blue;
	int		i;
	
	RGB = ft_split(color, ',');
	red = ft_atoi(RGB[0]);
	green = ft_atoi(RGB[1]);
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
