/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:39:22 by jmartos-          #+#    #+#             */
/*   Updated: 2024/08/24 14:17:50 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static char	*get_ext(char *file)
{
	char	*ext;

	ext = ft_strrchr(file, '.');
	return (ext);
}

void	parse_ext(char *av)
{
	char	*ext;

	ext = get_ext(av);
	if (ext == NULL || ft_strncmp(ext, ".cub", 4) != 0)
		free_error("ERROR! WRONG FILE EXTENSION...", NULL);
}
