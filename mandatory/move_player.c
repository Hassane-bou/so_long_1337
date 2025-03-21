/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboucha <haboucha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:41:54 by haboucha          #+#    #+#             */
/*   Updated: 2025/03/19 18:00:50 by haboucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player1(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == 'C')
	{
		game->map[new_y][new_x] = '0';
		game->collectibles--;
	}
	if (game->map[new_y][new_x] == 'E' && game->collectibles == 0)
	{
		ft_printf("Vous avez gagné ! 🏆\n");
		clean_exit(game, 0);
	}
	else if (game->map[new_y][new_x] != 'E')
	{
		game->map[game->player_y][game->player_x] = '0';
		game->map[new_y][new_x] = 'P';
		game->player_x = new_x;
		game->player_y = new_y;
		game->steps++;
		ft_printf("position de player: %d\n", game->steps);
	}
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	if (!game || !game->map)
		error_function();
	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (new_x < 0 || new_x >= game->map_width || new_y < 0
		|| new_y >= game->map_height || game->map[new_y][new_x] == '1')
		return ;
	move_player1(game, new_x, new_y);
	render_map(game);
}

void	clean_exit(t_game *game, int exit_code)
{
	if (game->mlx)
	{
		if (game->img_wall)
			mlx_destroy_image(game->mlx, game->img_wall);
		if (game->img_player)
			mlx_destroy_image(game->mlx, game->img_player);
		if (game->img_floor)
			mlx_destroy_image(game->mlx, game->img_floor);
		if (game->img_exit)
			mlx_destroy_image(game->mlx, game->img_exit);
		if (game->img_collectibles)
			mlx_destroy_image(game->mlx, game->img_collectibles);
	}
	if (game && game->map)
		free_map(game->map, game->map_height);
	if (game && game->win && game->mlx)
		mlx_destroy_window(game->mlx, game->win);
	exit(exit_code);
}

int	handle_keycode(int keycode, t_game *game)
{
	if (keycode == 53)
		clean_exit(game, 0);
	else if (keycode == 13)
		move_player(game, 0, -1);
	else if (keycode == 1)
		move_player(game, 0, 1);
	else if (keycode == 0)
		move_player(game, -1, 0);
	else if (keycode == 2)
		move_player(game, 1, 0);
	return (0);
}
