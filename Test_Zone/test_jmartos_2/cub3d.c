/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:07:53 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/21 17:51:44 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(void)
{
    //double pos_X = 22; // Vector de posicion inicial X del jugador
    //double pos_Y = 12; // Vector de posicion inicial Y del jugador
    /**/
    //double dir_X = -1; // Vector de direccion inicial X del jugador
    //double dir_Y = 0; // Vector de direccion inicial X del jugador
    /**/
    //double plane_X = 0; // Versión 2D raycaster del plano X de la camara
    //double plane_Y = 0.66; // Versión 2D raycaster del plano Y de la camara
    /**/
    //double time = 0; // Tiempo del fotograma actual
    //double old_time = 0; // Tiempo del fotograma anterior
    /**/
    mlx_t	*mlx;
	mlx_image_t	*image;

    // 1º CREAMOS UNA PANTALLA CON UNA RESOLUCION DETERMINADA
	mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "cub3D", false);
	image = mlx_new_image(mlx, MAP_WIDTH, MAP_HEIGHT);
	draw_line(image, 200,200,250,300);
	mlx_image_to_window(mlx, image, 0, 0);
	// 2º CREAMOS EL BUCLE DEL JUEGO
    mlx_loop(mlx);
    
	return (0);
}