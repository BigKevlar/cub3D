/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:25:57 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/21 17:50:03 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
