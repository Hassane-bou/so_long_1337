/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboucha <haboucha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 12:29:34 by haboucha          #+#    #+#             */
/*   Updated: 2025/03/16 14:59:37 by haboucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	**allocate_cpy(int **cpymap, int i, int width)
{
	cpymap[i] = malloc(width * sizeof(int));
	if (!cpymap[i])
	{
		while (i > 0)
		{
			free(cpymap[i - 1]);
			i--;
		}
		return (write(2, "Erreur\n", 8), free(cpymap), NULL);
	}
	return (cpymap);
}

static char	**copy_map(char **map)
{
	int		height;
	char	**map_cpy;
	int		i;

	height = get_map_height(map);
	i = 0;
	map_cpy = malloc((height + 1) * sizeof(char *));
	if (!map_cpy)
		error_function();
	while (i < height)
	{
		map_cpy[i] = ft_strdup(map[i]);
		if (!map_cpy[i])
		{
			while (--i >= 0)
				free(map_cpy[i]);
			free(map_cpy);
			error_function();
		}
		i++;
	}
	map_cpy[height] = NULL;
	return (map_cpy);
}

static int	flood_fill_map(char **map, int x, int y, t_data *map_d)
{
	int	m_width;
	int	m_height;

	m_width = ft_strlen(map[0]);
	m_height = get_map_height(map);
	if (x < 0 || y < 0 || x >= m_width || y >= m_height)
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'v' || map[y][x] == 'E')
	{
		if (map[y][x] == 'E')
			map_d->exit = 1;
		return (0);
	}
	if (map[y][x] == 'C')
		map_d->coins_found++;
	map[y][x] = 'v';
	flood_fill_map(map, x + 1, y, map_d);
	flood_fill_map(map, x - 1, y, map_d);
	flood_fill_map(map, x, y + 1, map_d);
	flood_fill_map(map, x, y - 1, map_d);
	return (map_d->coins_found == map_d->coins && map_d->exit);
}

int	check_map_solvable(t_data *map_d, t_game *game)
{
	char	**map_copy;
	int		result;
	int		height;

	result = 0;
	height = get_map_height(game->map);
	map_d->coins = count_collectible(game->map);
	map_d->coins_found = 0;
	map_d->exit = 0;
	map_d->x = game->player_x;
	map_d->y = game->player_y;
	map_copy = copy_map(game->map);
	if (!map_copy)
		return (result);
	result = flood_fill_map(map_copy, map_d->x, map_d->y, map_d);
	free_map(map_copy, height);
	return (result);
}
