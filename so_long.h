/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:06:29 by fsitter           #+#    #+#             */
/*   Updated: 2025/11/16 16:08:26 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "libft/libft.h"


// mapstuff.c
int	count_lines(char *mapfile);
char **make_map(char *mapfile);

// count_stuff.c
int count_of(char **s, char c);

// borders.c
int	check_borders(char **s, int xmax, int ymax);
int check_form(char **s);



// typedef struct s_point
// {
// 	int x;
// } t_point

# endif