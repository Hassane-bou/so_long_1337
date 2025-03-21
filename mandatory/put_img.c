/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboucha <haboucha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 16:19:48 by haboucha          #+#    #+#             */
/*   Updated: 2025/03/19 18:05:54 by haboucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_image(t_game *game)
{
	int	img_width;
	int	img_height;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "img/wall.xpm",
			&img_width, &img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "img/player.xpm",
			&img_width, &img_height);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "img/bag.xpm",
			&img_width, &img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "img/Exit.xpm",
			&img_width, &img_height);
	game->img_collectibles = mlx_xpm_file_to_image(game->mlx, "img/gold.xpm",
			&img_width, &img_height);
	if (!game->img_wall || !game->img_player || !game->img_collectibles
		|| !game->img_floor || !game->img_exit)
	{
		error_function();
		clean_exit(game, 1);
	}
}

void	put_img(t_game *game, int y, int x)
{
	if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x
			* TAILLE_SIZE, y * TAILLE_SIZE);
	else if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x
			* TAILLE_SIZE, y * TAILLE_SIZE);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x
			* TAILLE_SIZE, y * TAILLE_SIZE);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, x
			* TAILLE_SIZE, y * TAILLE_SIZE);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img_collectibles, x
			* TAILLE_SIZE, y * TAILLE_SIZE);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	if (!game || !game->map)
		clean_exit(game, 1);
	if (!game->img_exit || !game->img_collectibles || !game->img_floor
		|| !game->img_player || !game->img_wall)
		clean_exit(game, 1);
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			put_img(game, y, x);
			x++;
		}
		y++;
	}
}
