/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:57:36 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/02 18:02:18 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3D.h"

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