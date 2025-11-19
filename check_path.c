/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 12:18:54 by fsitter           #+#    #+#             */
/*   Updated: 2025/11/19 16:13:09 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_path(struct s_mapdata *data, char *mapfile);
int	fill_mapdata(struct s_mapdata *data, char *mapfile);
int	fill_count(struct s_mapdata *data, char **cpy_map, int x, int y);

int	check_path(struct s_mapdata *data, char *mapfile)
{
	char	**map_copy;

	map_copy = make_map(mapfile, data);
	if (fill_count(data, map_copy, data->playerposition_x,
			data->playerposition_y) == 0)
	{
		map_copy = free_map(map_copy);
		ft_printf("Error: Invalid path!\n");
		return (0);
	}
	map_copy = free_map(map_copy);
	return (1);
}

int	fill_mapdata(struct s_mapdata *data, char *mapfile)
{
	data->map = make_map(mapfile, data);
	if (!data->map)
		return (0);
	if (check_map_all(data) == 0)
		return (0);
	if (count_all(data) == 0)
		return (0);
	find_all(data);
	return (1);
}

int	fill_count(struct s_mapdata *data, char **cpy_map, int x, int y)
{
	static int	coins;
	static int	exit;

	if ((y < 0) || (x < 0) || (y > data->map_height_y)
		|| (x > data->map_width_x) || (cpy_map[x][y] == '1')
		|| (cpy_map[x][y] == '9'))
		return (0);
	if (cpy_map[x][y] == 'c')
		coins++;
	if (cpy_map[x][y] == 'e')
		exit++;
	cpy_map[x][y] = '9';
	fill_count(data, cpy_map, x, y - 1);
	fill_count(data, cpy_map, x, y + 1);
	fill_count(data, cpy_map, x + 1, y);
	fill_count(data, cpy_map, x - 1, y);
	return (data->coin_c == coins && data->exit_c == exit);
}
