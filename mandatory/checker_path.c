/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboucha <haboucha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:04:35 by haboucha          #+#    #+#             */
/*   Updated: 2025/03/15 16:21:57 by haboucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extention_file(char *filename)
{
	if (ft_strlen(filename) < 5 || filename[ft_strlen(filename) - 1] != 'r'
		|| filename[ft_strlen(filename) - 2] != 'e'
		|| filename[ft_strlen(filename) - 3] != 'b'
		|| filename[ft_strlen(filename) - 4] != '.')
		return (0);
	return (1);
}
