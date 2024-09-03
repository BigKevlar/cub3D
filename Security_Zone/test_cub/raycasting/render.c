/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:16:23 by arosas-j          #+#    #+#             */
/*   Updated: 2024/09/03 16:24:59 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	get_size(t_ray *ray)
{
	int	size;

	size = ((S_H * TILE_SIZE) / ray->distance);
	return (size);
}

/*static uint32_t get_color(t_game *g)
{
	if (g->ray->side == NORTH)
		return (0xFFFFFFFF);
	if (g->ray->side == SOUTH)
		return (0xFF0000FF);
	if (g->ray->side == EAST)
		return (0x0000FFFF);
	if (g->ray->side == WEST)
		return (0x00FF00FF);
	return (0);
}*/

#include <stdint.h>

// Function to apply shadow effect based on distance
static uint32_t apply_shadow(uint32_t color, float intensity)
{
    uint8_t r = (color >> 24) & 0xFF;
    uint8_t g = (color >> 16) & 0xFF;
    uint8_t b = (color >> 8) & 0xFF;
    uint8_t a = color & 0xFF;

    r = (uint8_t)(r * intensity);
    g = (uint8_t)(g * intensity);
    b = (uint8_t)(b * intensity);

    return (r << 24) | (g << 16) | (b << 8) | a;
}

static uint32_t get_color(t_game *g)
{
    uint32_t color;

    if (g->ray->side == NORTH)
        color = 0xFFFFFFFF;
    else if (g->ray->side == SOUTH)
        color = 0xFF0000FF;
    else if (g->ray->side == EAST)
        color = 0x0000FFFF;
    else if (g->ray->side == WEST)
        color = 0x00FF00FF;
    else
        color = 0;

    // Calculate shadow intensity based on distance
    float intensity = 1.0f / (1.0f + g->ray->distance * 0.005f); // Adjust the factor as needed

    // Apply shadow effect
    return apply_shadow(color, intensity);
}

void ft_clear_window(t_game *g)
{
	mlx_delete_image(g->mlx, g->img->window);
	g->img->window = mlx_new_image(g->mlx, S_W, S_H);
	mlx_image_to_window(g->mlx, g->img->window, 0, 0);
}

void render(t_game *g, int i)
{
	int	start;
	int	size;
	uint32_t color;

	size = 0;
	size = get_size(g->ray);
	if (size > S_H)
		size = S_H;
	start = (S_H / 2) - (size / 2);
	color = get_color(g);
	while (size > 0)
	{
		if (start >= 0 && start < S_H && i >= 0 && i < S_W)
			mlx_put_pixel(g->img->window, i, start, color);
		size--;
		start++;
	}
}

void	get_v_surface(t_game *g)
{
	if (sign(cos(g->ray->angle)) == 1)
	{
		g->ray->side = WEST;
	}
	else
		g->ray->side = EAST;
}

void get_h_surface(t_game *g)
{
	if (sign(sin(g->ray->angle)) == 1)
	{
		g->ray->side = SOUTH;
	}
	else
		g->ray->side = NORTH;
}