/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_to_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:04:00 by arosas-j          #+#    #+#             */
/*   Updated: 2024/08/25 20:04:18 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <stdio.h>

void	game_to_window(t_game *game)
{
	mlx_image_to_window(game->mlx, game->img->p_right, game->x, game->y);
	game->img->ray = mlx_new_image(game->mlx, 0, 0);
}
