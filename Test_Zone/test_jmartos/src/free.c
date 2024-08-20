/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 22:06:18 by jmartos           #+#    #+#             */
/*   Updated: 2024/08/19 20:02:09 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	win_game(t_game *game)
{
	erasing_gui(game);
	ft_charppfree(game->map);
	ft_charppfree(game->map_copy);
	mlx_terminate(game->mlx);
	free(game);
	exit (1);
}

void	close_game(t_game *game)
{
	ft_printf("JUEGO CERRADO.\n");
	erasing_gui(game);
	ft_charppfree(game->map);
	ft_charppfree(game->map_copy);
	mlx_terminate(game->mlx);
	free(game);
	exit (1);
}
