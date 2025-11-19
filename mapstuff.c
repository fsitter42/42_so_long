/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapstuff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:40:27 by fsitter           #+#    #+#             */
/*   Updated: 2025/11/19 16:13:54 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		count_lines(char *mapfile);
char	**make_map(char *mapfile, struct s_mapdata *data);
int		count_of(char **map, char what_to_find);
char	**free_map(char **map);

int	count_lines(char *mapfile)
{
	int		fd;
	int		line_count;
	char	*a;

	a = NULL;
	fd = open(mapfile, O_RDONLY);
	line_count = 0;
	while (1)
	{
		a = get_next_line(fd);
		if (a == NULL)
			break ;
		line_count++;
		free(a);
	}
	a = NULL;
	close(fd);
	return (line_count);
}

char	**make_map(char *mapfile, struct s_mapdata *data)
{
	char	**map;
	int		row;
	int		fd;

	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error: filediscriptor\n", 2), NULL);
	data->map_height_y = count_lines(mapfile);
	map = malloc(sizeof(char *) * (data->map_height_y + 1));
	if (!map)
		return (ft_putstr_fd("Error: malloc error\n", 2), NULL);
	row = 0;
	while (row < data->map_height_y)
	{
		map[row] = get_next_line(fd);
		data->map_width_x = (int)ft_strlen(map[row]);
		if (map[row][data->map_width_x - 1] == '\n')
			map[row][data->map_width_x - 1] = '\0';
		row++;
	}
	map[data->map_height_y] = NULL;
	close(fd);
	return (map);
}

int	count_of(char **map, char what_to_find)
{
	int	c_count;
	int	i;
	int	j;

	c_count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == what_to_find)
				c_count++;
			j++;
		}
		i++;
	}
	return (c_count);
}

char	**free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}

// make_map > nicht mapfile passen sondern struct dann spare ich lines
// und muss es nicht nochmal ausführen
// int line_count und char **map  und size_t last weil ich alles damit passe
// line_count - 1 = mapdata.map_width
// map = mapdata.map
// last - 1 = mapdata.map_height

// void	fill(char **area, t_point size, t_point vec, char to_fill)
// {
// 	static int c_count = 0;
// 	static int e_count = 0;
// 	if (vec.y < 0 || vec.y >= size.y || vec.x < 0 || vec.x >= size.x || \
// 		area[vec.y][vec.x] != to_fill)
// 		return ;
// 	if (area[vec.x][vec.y] == 'C')
// 		c_count++;//coint got create this in the big struct
// 	if (area[vec.x][vec.y] == 'E')
// 		e_count++;//coint got
// 	area[vec.y][vec.x] = 'F';
// 	fill(area, size, (t_point){vec.x - 1, vec.y}, to_fill);
// 	fill(area, size, (t_point){vec.x + 1, vec.y}, to_fill);
// 	fill(area, size, (t_point){vec.x, vec.y - 1}, to_fill);
// 	fill(area, size, (t_point){vec.x, vec.y + 1}, to_fill);

// }

// int	main(void)
// {
// 	ft_printf("%i\n", count_lines("aaa.ber"));
// }
