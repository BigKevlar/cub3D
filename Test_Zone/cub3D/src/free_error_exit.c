/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:50:53 by jmartos-          #+#    #+#             */
/*   Updated: 2024/09/09 17:47:37 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

/**/
void	continue_free(t_game *g)
{
	free (g->t_tex00);
	free (g->t_tex01);
	free (g->t_tex02);
	free (g->t_tex03);
	free (g->t_tex04);
	free (g->t_tex05);
	free (g->t_tex06);
	free (g->t_tex07);
	free (g->torch_tex);
	free (g->t_image00);
	free (g->t_image01);
	free (g->t_image02);
	free (g->t_image03);
	free (g->t_image04);
	free (g->t_image05);
	free (g->t_image06);
	free (g->t_image07);
	free (g->torch_img);
	exit (1);
}

/**/
void	free_error(char *msg, t_game *g)
{
	ft_printf("%s\n", msg);
	if (g == NULL)
		exit (1);
	if (g != NULL)
	{
		ft_strd_free(g->file);
		ft_strd_free(g->map);
		free (g->texture_no);
		free (g->texture_so);
		free (g->texture_we);
		free (g->texture_ea);
		free (g->color_c);
		free (g->color_f);
		continue_free(g);
	}
}

/**/
static void	delete_textures(t_game *g)
{
	mlx_delete_texture(g->t_tex00);
	mlx_delete_texture(g->t_tex01);
	mlx_delete_texture(g->t_tex02);
	mlx_delete_texture(g->t_tex03);
	mlx_delete_texture(g->t_tex04);
	mlx_delete_texture(g->t_tex05);
	mlx_delete_texture(g->t_tex06);
	mlx_delete_texture(g->t_tex07);
	mlx_delete_texture(g->tex->n);
	mlx_delete_texture(g->tex->s);
	mlx_delete_texture(g->tex->e);
	mlx_delete_texture(g->tex->w);
	mlx_delete_texture(g->tex->door);
}

/**/
void	win_game(char *msg, t_game *g)
{
	ft_printf("%s\n", msg);
	ft_strd_free(g->file);
	free(g->texture_no);
	free(g->texture_so);
	free(g->texture_we);
	free(g->texture_ea);
	free(g->color_c);
	free(g->color_f);
	ft_strd_free(g->map);
	delete_textures(g);
	free(g->tex);
	free(g->img);
	free(g->ray);
	free(g->ply);
	mlx_terminate(g->mlx);
}
