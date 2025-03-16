/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_allocate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboucha <haboucha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:03:40 by haboucha          #+#    #+#             */
/*   Updated: 2025/03/16 13:55:57 by haboucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_function(void)
{
	write(2, "Erreur\n", 8);
	return ;
}

void	free_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

void	free_map1(int **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	check_position_player(char **map, int height)
{
	write(2, "Player not found!\n", 18);
	free_map(map, height);
	exit(0);
}
