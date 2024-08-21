/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 12:45:50 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/21 17:52:18 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/inc/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <math.h>

# define MAP_WIDTH 24
# define MAP_HEIGHT 24
# define WIN_WIDTH 640
# define WIN_HEIGHT 480

void    draw_line(mlx_image_t *image, double x1, double y1, double x2, double y2);

#endif