/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:35:05 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/18 21:11:56 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(void)
{
	void	*mlx_connection;

	mlx_connection = mlx_init(W_MAP, H_MAP, "cub3D", false);
	//CODIGO
	mlx_loop(mlx_connection);
	return (0);
}
