/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboucha <haboucha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:12:36 by haboucha          #+#    #+#             */
/*   Updated: 2025/03/16 15:02:25 by haboucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clean_map(t_game *game)
{
	free_map(game->map, game->map_height);
	exit(0);
}

void	put_mlx(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map_width * 64, game->map_height
			* 64, "So Long");
	load_image(game);
	mlx_key_hook(game->win, handle_keycode, game);
	mlx_hook(game->win, 17, 0, clean_map, game);
	render_map(game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_game	*game;
	int		height;

	if (ac > 1)
	{
		game = malloc(sizeof(t_game));
		height = 0;
		game->steps = 0;
		if (!check_extention_file(av[1]))
			return (write(1, "File Invalid\n", 14), 0);
		game->map = read_map(av[1], &height);
		if (!game->map)
			return (write(2, "Erreur\n", 7), 1);
		check_parse(game, height);
		game->map_height = get_map_height(game->map);
		put_mlx(game);
		free_map(game->map, game->map_height);
	}
	else
		return (write(2, "Erreur\n", 7), 1);
	return (0);
}
