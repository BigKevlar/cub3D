/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:01:12 by jmartos           #+#    #+#             */
/*   Updated: 2024/08/19 20:03:02 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void	loading_gui(t_game *game)
{
	mlx_texture_t	*texture;
	
	texture = mlx_load_png("./images/floor.png");
	game->image_floor = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./images/wall.png");
	game->image_wall = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./images/player.png");
	game->image_player = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	//game->image_floor = mlx_new_image(game->mlx, 1024, 720);
	//mlx_image_to_window(game->mlx, game->image_floor, 0, 0);
	//mlx_put_pixel(game->image_floor, 420, 420, 0xff0000ff);
	//
	//texture = mlx_load_png("./images/floor.png");
	//game->image_floor = mlx_texture_to_image(game->mlx, texture);
	//mlx_image_to_window(game->mlx, game->image_floor, 420, 420);
	//mlx_delete_texture(texture);
}

void	erasing_gui(t_game *game)
{
	mlx_delete_image(game->mlx, game->image_floor);
	mlx_delete_image(game->mlx, game->image_wall);
	mlx_delete_image(game->mlx, game->image_player);
}
