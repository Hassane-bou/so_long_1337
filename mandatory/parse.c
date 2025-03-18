/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboucha <haboucha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:30:17 by haboucha          #+#    #+#             */
/*   Updated: 2025/03/17 14:08:33 by haboucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(char **map, int height)
{
	if (!is_rectangular(map, height))
	{
		write(2, "Map Invalid!\n", 14);
		free_map(map, height);
		return (0);
	}
	if (!check_walls(map, height))
	{
		write(2, "Map Invalid!\n", 14);
		free_map(map, height);
		return (0);
	}
	if (!unused_element(map, height))
	{
		write(2, "Caractère invalide dans la carte\n", 34);
		free_map(map, height);
		return (0);
	}
	if (!check_element(map, height))
	{
		free_map(map, height);
		return (0);
	}
	return (1);
}

void	initialiser(t_game *game, t_data *data)
{
	data->x = game->player_x;
	data->y = game->player_y;
	data->player = 0;
	data->coins_found = 0;
	data->coins = 0;
	data->exit = 0;
}

void	check_parse(t_game *game, int height)
{
	t_data	data;

	if (!validate_map(game->map, height))
		exit(1);
	find_p(game);
	if (game->player_x == -1 || game->player_y == -1)
		check_position_player(game->map, height);
	game->map_width = ft_strlen(game->map[0]) - 1;
	initialiser(game, &data);
	if (!check_map_solvable(&data, game))
	{
		write(2, "impossible d'apprendre tous les collectibles\n", 46);
		free_map(game->map, height);
		exit(1);
	}
}
