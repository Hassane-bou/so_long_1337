/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboucha <haboucha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:21:20 by haboucha          #+#    #+#             */
/*   Updated: 2025/03/18 11:57:58 by haboucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(int fd)
{
	int		count;
	char	*line;

	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**allocate(char **map, int i, int fd)
{
	map[i] = get_next_line(fd);
	if (!map[i])
	{
		while (i > 0)
			free(map[--i]);
		return (free(map), close(fd), exit(100), NULL);
	}
	return (map);
}

char	**read_map(char *filename, int *height)
{
	int		fd;
	char	**map;
	int		i;

	map = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	*height = count_lines(fd);
	if (*height == 0)
		return (close(fd), NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * (*height + 1));
	if (!map)
		return (close(fd), NULL);
	i = 0;
	while (i < *height)
	{
		allocate(map, i, fd);
		i++;
	}
	map[i] = NULL;
	return (close(fd), map);
}
