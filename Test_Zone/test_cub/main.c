/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:21:33 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/02 15:59:58 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3D.h"

void	check_args(void)
{}

int	main(void)
{	
	t_game	g;

	//check_args();
	init_data(&g);
	run_game(&g);
	return (0);
}
