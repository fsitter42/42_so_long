/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:18:54 by fsitter           #+#    #+#             */
/*   Updated: 2025/11/19 12:55:53 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int check_path(struct s_mapdata mapdata);
int	fill_mapdata(struct s_mapdata *data, char *mapfile);

// int check_path(struct s_mapdata mapdata)
// {
//     // char **map_copy;
//     return (1);

// }

int	fill_mapdata(struct s_mapdata *data, char *mapfile)
{
	// data->map_height = count_lines(mapfile);
	data->map = make_map(mapfile, data);
	if (!data->map)
		return (0);
	return (1);
}