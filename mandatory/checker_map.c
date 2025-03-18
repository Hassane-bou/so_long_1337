/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboucha <haboucha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:45:54 by haboucha          #+#    #+#             */
/*   Updated: 2025/03/16 15:57:45 by haboucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(char **map, int height)
{
	int	width;
	int	i;
	int	line_len;

	if (!map || !map[0] || height == 0)
		return (0);
	width = ft_strlen(map[0]);
	if (map[0][width - 1] == '\n')
		width--;
	i = 1;
	if (height > 128)
		return (0);
	while (i < height)
	{
		line_len = ft_strlen(map[i]);
		if (map[i][line_len - 1] == '\n')
			line_len--;
		if (line_len != width || ft_strlen(map[i]) > 129)
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(char **map, int height)
{
	int	width;
	int	i;

	if (!map || height == 0)
		return (0);
	width = ft_strlen(map[0]) - 1;
	i = -1;
	while (++i < width)
	{
		if (map[0][i] != '1')
			return (0);
	}
	i = -1;
	while (++i < width)
	{
		if (map[height - 1][i] != '1')
			return (0);
	}
	i = -1;
	while (++i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
	}
	return (1);
}
