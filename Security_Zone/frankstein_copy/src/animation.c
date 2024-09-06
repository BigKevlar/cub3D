/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:30:16 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/06 11:11:01 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void load_torch_textures(t_game *g)
{
    int torch_x = ((3 * S_W) / 4) - (400 / 2);
    int torch_y = S_H - 400 - 20;
    
    // Reservar memoria para las texturas
    g->t_texture00 = mlx_load_png("tex/torch_frames/frame00.png");
    g->t_texture01 = mlx_load_png("tex/torch_frames/frame01.png");
    g->t_texture02 = mlx_load_png("tex/torch_frames/frame02.png");
    g->t_texture03 = mlx_load_png("tex/torch_frames/frame03.png");
    g->t_texture04 = mlx_load_png("tex/torch_frames/frame04.png");
    g->t_texture05 = mlx_load_png("tex/torch_frames/frame05.png");
    g->t_texture06 = mlx_load_png("tex/torch_frames/frame06.png");
    g->t_texture07 = mlx_load_png("tex/torch_frames/frame07.png");

    // Verificar si alguna textura no se cargó correctamente
    if (!(g->t_texture00 && g->t_texture01 && g->t_texture02 &&
        g->t_texture03 && g->t_texture04 && g->t_texture05 &&
        g->t_texture06 && g->t_texture07))
    {
        free_error("ERROR al convertir PNG en texturas!\n", g);
    }

    g->torch_image = mlx_new_image(g->mlx, g->t_texture00->width, g->t_texture00->height);
    mlx_image_to_window(g->mlx, g->torch_image, torch_x, torch_y);
    g->torch_image->instances->z = 2;
/*
    // Convertir texturas en imágenes
    g->t_image00 = mlx_texture_to_image(g->mlx, g->t_texture00);
    g->t_image01 = mlx_texture_to_image(g->mlx, g->t_texture01);
    g->t_image02 = mlx_texture_to_image(g->mlx, g->t_texture02);
    g->t_image03 = mlx_texture_to_image(g->mlx, g->t_texture03);
    g->t_image04 = mlx_texture_to_image(g->mlx, g->t_texture04);
    g->t_image05 = mlx_texture_to_image(g->mlx, g->t_texture05);
    g->t_image06 = mlx_texture_to_image(g->mlx, g->t_texture06);
    g->t_image07 = mlx_texture_to_image(g->mlx, g->t_texture07);

    // Verificar si alguna imagen no se convirtió correctamente
    if (!(g->t_image00 && g->t_image01 && g->t_image02 &&
        g->t_image03 && g->t_image04 && g->t_image05 &&
        g->t_image06 && g->t_image07))
    {
        free_error("ERROR al convertir texturas en imagenes!\n", g);
    }
*/
}


void draw_torch(t_game *g)
{
    if (g->actual_torch_frame == 0)
        g->torch_texture = g->t_texture00;
    else if (g->actual_torch_frame == 1)
        g->torch_texture = g->t_texture01;
    else if (g->actual_torch_frame == 2)
        g->torch_texture = g->t_texture02;
    else if (g->actual_torch_frame == 3)
        g->torch_texture = g->t_texture03;
    else if (g->actual_torch_frame == 4)
        g->torch_texture = g->t_texture04;
    else if (g->actual_torch_frame == 5)
        g->torch_texture = g->t_texture05;
    else if (g->actual_torch_frame == 6)
        g->torch_texture = g->t_texture06;
    else if (g->actual_torch_frame == 7)
        g->torch_texture = g->t_texture07;

    mlx_draw_texture(g->torch_image, g->torch_texture, 0, 0);

    g->torch_frame_counter++;
    if (g->torch_frame_counter >= g->torch_animation_speed)
    {
        g->actual_torch_frame = (g->actual_torch_frame + 1) % 8;
        g->torch_frame_counter = 0;
    }
}
