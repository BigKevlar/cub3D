/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:50:53 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/24 14:19:54 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*
	Liberamos la memoria del juego y cerramos de mismo en caso de error.
*/
void	free_error(char *msg, t_game *game)
{
	ft_printf("%s\n", msg);
	if (game == NULL)
		exit (1);
	if (game != NULL)
	{
		ft_strd_free(game->file);
		ft_strd_free(game->map);
		free(game);
		exit (1);
	}
}
