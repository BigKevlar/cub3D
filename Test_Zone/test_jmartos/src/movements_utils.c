/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:44:35 by jmartos           #+#    #+#             */
/*   Updated: 2024/08/20 13:47:32 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	action(t_game *game, int new_x, int new_y)
{
	if (game->map[new_x][new_y] != '1')
	{
		game->map[(int)game->pos_x][(int)game->pos_y] = '0';
		game->map[new_x][new_y] = 'P';
		game->pos_x = new_x;
		game->pos_y = new_y;
		print_map(game, game->map);
	}
}
