/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosas-j <arosas-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:42:27 by arosas-j          #+#    #+#             */
/*   Updated: 2024/08/27 15:06:07 by arosas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	init_struct(t_game *game)
{
	game->img = NULL;
	game->mlx = NULL;
	game->text = NULL;
	game->map = NULL;
	game->x = 500;
	game->y = 500;
	game->angle = 0;
	game->move_w = 0;
	game->move_a = false;
	game->move_d = false;
	game->rotate = 0;
}

/*static char	*ft_strdup(const char *s1)
{
	char	*new_array;
	int		len;

	len = ft_strlen(s1) + 1;
	new_array = malloc(len);
	if (!new_array)
		return (NULL);
	ft_strlcpy(new_array, s1, len);
	new_array[len - 1] = '\0';
	return (new_array);
}*/

/*static void	init_map(t_game *game)
{
	game->map = calloc(10, sizeof(char *));
	game->map[0] = ft_strdup("1111111111111111111111111");
	game->map[1] = ft_strdup("1000000000000000000100001");
	game->map[2] = ft_strdup("1001000000000P00000000001");
	game->map[3] = ft_strdup("1001000000000000001000001");
	game->map[4] = ft_strdup("1001000000000000001000001");
	game->map[5] = ft_strdup("1001000000100000001000001");
	game->map[6] = ft_strdup("1001000000000000001000001");
	game->map[7] = ft_strdup("1001000000001000001000001");
	game->map[8] = ft_strdup("1111111111111111111111111");
	game->map[9] = NULL;
}*/

int	main(void)
{
	t_game game;
	
	init_struct(&game);
	game.mlx = mlx_init(S_W, S_H, "Map", false);
	get_textures(&game);
	get_images(&game);
	game_to_window(&game);
	mlx_key_hook(game.mlx, &ft_key_hook, &game);
	mlx_loop_hook(game.mlx, &ft_game_hook, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	free(game.img);
	return (0);
}
