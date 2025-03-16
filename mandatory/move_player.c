/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboucha <haboucha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:41:54 by haboucha          #+#    #+#             */
/*   Updated: 2025/03/16 15:13:03 by haboucha         ###   ########.fr       */
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
		exit(0);
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
	game->collectibles = count_collectible(game->map);
	move_player1(game, new_x, new_y);
	render_map(game);
}

int	handle_keycode(int keycode, t_game *game)
{
	if (keycode == 53)
		exit(0);
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
