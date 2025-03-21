/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_element.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboucha <haboucha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:54:13 by haboucha          #+#    #+#             */
/*   Updated: 2025/03/18 18:02:50 by haboucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	unused_element(char **map, int height)
{
	int	i;
	int	j;
	int	width;

	width = ft_strlen(map[0]) - 1;
	i = 0;
	j = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P'
				&& map[i][j] != 'E' && map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	find_element(int count_p, int count_e, int count_c)
{
	if (count_p > 1 || count_p == 0)
	{
		write(2, "Un player s'il vous plait\n", 27);
		return (0);
	}
	if (count_e > 1 || count_e == 0)
	{
		write(2, "Un exit s'il vous plait\n", 25);
		return (0);
	}
	if (count_c < 1)
	{
		write(2, "au moin un colllectibles!!\n", 28);
		return (0);
	}
	return (1);
}

int	check_element(char **map, int height)
{
	int	count_p;
	int	count_e;
	int	count_c;
	int	i;
	int	j;

	count_p = ((count_e = (count_c = 0), 0), 0);
	if (!map || height == 0)
		return (0);
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < ft_strlen(map[0]) - 1)
		{
			if (map[i][j] == 'P')
				count_p++;
			if (map[i][j] == 'E')
				count_e++;
			if (map[i][j] == 'C')
				count_c++;
		}
	}
	return (find_element(count_p, count_e, count_c));
}
