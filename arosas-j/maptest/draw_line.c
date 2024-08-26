/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 20:21:05 by arosas-j          #+#    #+#             */
/*   Updated: 2024/08/25 21:48:01 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
/*
static void	plot_line (int x0, int y0, int x1, int y1, t_game *game)
{
  int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1; 
  int err = dx + dy, e2;
 
  for (;;){
    mlx_put_pixel (game->img->ray, x0,y0, 0xFFFFFFFF);
    if (x0 == x1 && y0 == y1) break;
    e2 = 2 * err;
    if (e2 >= dy) { err += dy; x0 += sx; }
    if (e2 <= dx) { err += dx; y0 += sy; }
  }
}
*/

static void plot_line(int x0, int y0, int x1, int y1, t_game *game)
{
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;

    while (1) {
        // Asegurarse de que las coordenadas estén dentro de los límites de la pantalla
        if (x0 >= 0 && x0 < S_W && y0 >= 0 && y0 < S_H) {
            mlx_put_pixel(game->img->ray, x0, y0, 0xFFFFFFFF);
        }
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
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
    game->x2 += dx;
    game->y2 += dy;
  }
  game->x2 += game->x;
  game->y2 += game->y;
}

void  draw_line(t_game *game)
{
  mlx_delete_image(game->mlx, game->img->ray);
  get_vector(game);
  printf("%f, %f\n", game->x2, game->y2);
  game->img->ray = mlx_new_image(game->mlx, S_W, S_H);
  plot_line(game->x2, game->y2, game->x, game->y, game);
  mlx_image_to_window(game->mlx, game->img->ray, 0, 0);
}