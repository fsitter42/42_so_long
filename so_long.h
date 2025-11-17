/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:06:29 by fsitter           #+#    #+#             */
/*   Updated: 2025/11/17 13:52:03 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "libft/libft.h"


// mapstuff.c
int	count_lines(char *mapfile);
char **make_map(char *mapfile);

// count_stuff.c
int count_of(char **map, char what_to_find);

// borders.c
int	check_borders(char **map, int xmax, int ymax);
int check_form(char **map);
int check_signs(char **map);
void find_sign(char **map, char to_find, int *x, int *y);



// typedef struct s_point
// {
// 	int x;
// } t_point

# endif