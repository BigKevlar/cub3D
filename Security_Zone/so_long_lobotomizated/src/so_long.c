/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:31:51 by jmartos           #+#    #+#             */
/*   Updated: 2024/08/19 19:01:34 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if ((ac == 1) || (ac == 2 && av[1] == NULL))
		free_error("ERROR CON ARGUMENTOS VACIOS", NULL);
	game = get_map(av[1]);
	parse_ext(av[1], game);
	init_game(game);
	win_game(game);
	return (0);
}
