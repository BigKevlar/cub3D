/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:21:33 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/03 20:19:33 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	main(int ac, char **av)
{	
	t_game	g;

	ft_memset(&g, '0', sizeof(t_game));
	if ((ac != 2) || (ac == 2 && av[1] == NULL))
		free_error("ERROR! WRONG ARGUMENTS SINTAXIS...", NULL);
	parse_ext(av[1]);
	init_struct(&g);
	get_file(&g, av[1]);
	get_texture(&g);
	get_rgb(&g);
	get_map(&g);
	parse_map(&g);
	//
	init_data(&g);
	//check_inits(&g);
	run_game(&g);
	mlx_terminate(g.mlx);
	free_game("FIN DEL JUEGO", &g);
	return (0);
}
