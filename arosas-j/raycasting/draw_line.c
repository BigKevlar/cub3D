/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:50:33 by arosas-j          #+#    #+#             */
/*   Updated: 2024/08/20 14:47:27 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "MLX42/include/MLX42/MLX42.h"

void	draw_line(mlx_image_t *image, double x1, double y1, double x2, double y2)
{
	double	m;
	double	n;
	double	x;
	double	y;

	m = (x2 - x1) / (y2 - y1);
	n = y1 - m * x1;
	x = x1;
	while (x <= x2)
	{
		y = round(m * x + n);
		mlx_put_pixel(image, x, y, 0xFFFFFFFF);
		x++;
	}

}

int main(void)
{
	mlx_t	*mlx;
	mlx_image_t	*image;

	mlx = mlx_init(500, 500, "Draw line", false);
	image = mlx_new_image(mlx, 500, 500);
	draw_line(image, 0,0,200,200);
	mlx_loop(mlx);
	return (0);
}
