/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapstuff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:40:27 by fsitter           #+#    #+#             */
/*   Updated: 2025/11/18 17:06:13 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		count_lines(char *mapfile);
char	**make_map(char *mapfile);

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

char	**make_map(char *mapfile)
{
	int		line_count;
	char	**map;
	int		row;
	int		fd;
	size_t	last;

	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error: filediscriptor\n", 2), NULL);
	line_count = count_lines(mapfile);
	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		return (0);
	row = 0;
	while (row < line_count)
	{
		map[row] = get_next_line(fd);
		last = ft_strlen(map[row]);
		if (map[row][last - 1] == '\n')
			map[row][last - 1] = '\0';
		row++;
	}
	map[line_count] = NULL;
	close(fd);
	return (map);
}


// make_map > nicht mapfile passen sondern struct dann spare ich line
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
