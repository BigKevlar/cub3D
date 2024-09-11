/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:00:22 by arosas-j          #+#    #+#             */
/*   Updated: 2024/08/23 17:14:09 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	while (i < (int)(count * size))
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

static void	free_textures(t_textures *textures)
{
	mlx_delete_texture(textures->blank);
	mlx_delete_texture(textures->wall);
	mlx_delete_texture(textures->p_right);
	free(textures);
}

void	get_textures(t_game *game)
{
	game->text = ft_calloc(1, sizeof(t_textures));
	game->text->blank = mlx_load_png("./textures/blank.png");
	game->text->wall = mlx_load_png("./textures/wall.png");
	game->text->p_right = mlx_load_png("./textures/p_right.png");
}

void	get_images(t_game *game)
{
	game->img = ft_calloc(1, sizeof(t_images));
	game->img->blank = mlx_texture_to_image(game->mlx, game->text->blank);
	game->img->wall = mlx_texture_to_image(game->mlx, game->text->wall);
	game->img->p_right = mlx_texture_to_image(game->mlx, game->text->p_right);
	free_textures(game->text);
}