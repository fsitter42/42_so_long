/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:06:29 by fsitter           #+#    #+#             */
/*   Updated: 2025/11/18 16:57:28 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"

// mapstuff.c
int			count_lines(char *mapfile);
char		**make_map(char *mapfile);

// count_stuff.c
int			count_of(char **map, char what_to_find);

// borders.c
int			check_borders(char **map, int xmax, int ymax);
int			check_form(char **map);
int			check_signs(char **map);
void		find_sign(char **map, char to_find, int *x, int *y);

// comandline_input.c
int			check_input(int argc, char *argv);
int			check_fd(char *argv);

// struct to safe mapdata
struct		s_mapdata
{
	char	**map;
	int		player_c;
	int		exit_c;
	int		coin_c;
	int		map_width;
	int		map_height;
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

#endif