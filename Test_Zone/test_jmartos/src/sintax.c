/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sintax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:49:35 by jmartos           #+#    #+#             */
/*   Updated: 2024/08/18 21:55:09 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// OK
static char	*get_ext(char *map)
{
	char	*ext;

	ext = ft_strrchr(map, '.');
	return (ext);
}

// OK
void	parse_ext(char *av, t_game *game)
{
	char	*ext;

	ext = get_ext(av);
	if (ext == NULL || ft_strncmp(ext, ".cub", 4) != 0)
		free_error("ERROR CON EXTENSION", game);
}
