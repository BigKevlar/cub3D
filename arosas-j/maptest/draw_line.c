/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 20:21:05 by arosas-j          #+#    #+#             */
/*   Updated: 2024/08/27 20:48:15 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void put_pixel(mlx_image_t	*img, uint32_t x, uint32_t y, uint32_t color) {
    if (x < 0 || y < 0 || x > img->width || y > img->height)
      return;
    mlx_put_pixel(img, x, y, color);
}

static void  get_vector(t_game *game)
{
  double  dx;
  double  dy;
  
  game->x2 = cos(game->angle);
  dx = game->x2;
  game->y2 = sin(game->angle);
  dy = game->y2;
  while (game->x2 + game->x < S_W && game->x2 + game->x > 0 && game->y2 + game->y < S_H && game->y2 + game->y > 0)
  {
    put_pixel(game->img->ray, game->x2 + game->x, game->y2 + game->y, 0xFF0000FF);
    game->x2 += dx;
    game->y2 += dy;
  }
  game->x2 += game->x;
  game->y2 += game->y;
}

void  draw_line(t_game *game)
{
  mlx_delete_image(game->mlx, game->img->ray);
  game->img->ray = mlx_new_image(game->mlx, S_W, S_H);
  get_vector(game);
  printf("%f, %f\n", game->x2, game->y2);
  mlx_image_to_window(game->mlx, game->img->ray, 0, 0);
}