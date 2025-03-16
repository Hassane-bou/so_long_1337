/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haboucha <haboucha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:12:41 by haboucha          #+#    #+#             */
/*   Updated: 2025/03/16 14:16:36 by haboucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef TAILLE_SIZE
#  define TAILLE_SIZE 64
# endif

# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"
# include "../printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game
{
	char	**map;
	void	*mlx;
	void	*win;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		map_width;
	int		map_height;
	void	*img_wall;
	void	*img_player;
	void	*img_collectibles;
	void	*img_exit;
	void	*img_floor;
	int		steps;
}			t_game;

typedef struct s_data
{
	int		player;
	int		coins_found;
	int		coins;
	int		exit;
	int		x;
	int		y;
}			t_data;

char		**read_map(char *filename, int *height);
char		**allocate(char **map, int i, int fd);
int			count_lines(int fd);
int			check_extention_file(char *filename);
void		check_parse(t_game *game, int height);
int			validate_map(char **map, int height);
int			is_rectangular(char **map, int height);
int			check_walls(char **map, int height);
int			unused_element(char **map, int height);
int			find_element(int count_p, int count_e, int count_c);
int			check_element(char **map, int height);
void		find_p(t_game *game);
void		check_position_player(char **map, int height);
int			check_map_solvable(t_data *data, t_game *game);
int			get_map_height(char **map);
void		load_image(t_game *game);
int			handle_keycode(int keycode, t_game *game);
void		move_player(t_game *game, int dx, int dy);
void		error_function(void);
void		free_map(char **map, int height);
void		free_map1(int **map, int height);
int			count_collectible(char **map);
void		render_map(t_game *game);
void		error_function(void);
int			main(int ac, char **av);

#endif
