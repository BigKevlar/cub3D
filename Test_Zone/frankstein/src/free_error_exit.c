/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:50:53 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/04 13:34:18 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

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
		// Y MAS COSAS!?
		free(game);
		exit (1);
	}
}

/*
	Liberamos la memoria del juego y cerramos de mismo en caso de error.
*/
void	free_game(char *msg, t_game *g)
{
	ft_printf("%s\n", msg);
	ft_strd_free(g->file);
	free(g->texture_NO);
	free(g->texture_SO);
	free(g->texture_WE);
	free(g->texture_EA);
	free(g->color_F);
	free(g->color_C);
	ft_strd_free(g->map);
	ft_strd_free(g->map_copy);
	free(g->tex);
	free(g->img);
	free(g->ray);
	free(g->ply);
	free(g->routes);
}
