/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:06:29 by fsitter           #+#    #+#             */
/*   Updated: 2025/11/19 16:03:16 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"

// struct to safe mapdata
struct		s_mapdata
{
	char	**map;
	int		player_c;
	int		exit_c;
	int		coin_c;
	int		map_width_x;
	int		map_height_y;
	int		playerposition_x;
	int		playerposition_y;
	int		exitposition_x;
	int		exitposition_y;
};

// struct to safe player position
typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

// mapstuff.c
int			count_lines(char *mapfile);
char		**make_map(char *mapfile, struct s_mapdata *data);
int			count_of(char **map, char what_to_find);
char		**free_map(char **map);

// check_and_find.c
int			check_borders(char **map, int xmax, int ymax);
int			check_form(char **map);
int			check_signs(char **map);
void		find_sign(char **map, char to_find, int *x, int *y);

// input_and_all.c
int			check_input(int argc, char *argv);
int			check_map_all(struct s_mapdata *data);
int			count_all(struct s_mapdata *data);
void		find_all(struct s_mapdata *data);

// check_path.c
int			check_path(struct s_mapdata *data, char *mapfile);
int			fill_mapdata(struct s_mapdata *data, char *mapfile);
int			fill_count(struct s_mapdata *data, char **cpy_map, int x, int y);

#endif