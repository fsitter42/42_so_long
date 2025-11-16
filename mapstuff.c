#include "so_long.h"

// create a big struct
typedef struct s_point
{
	int x;
	int y;
}	t_point;

int	count_lines(char *mapfile)
{
	int		fd;
	int		line_count;
	char	*a;

	fd = open(mapfile, O_RDONLY);
	line_count = 0;
	while ((a = get_next_line(fd)))
	{
		line_count++;
		free(a);
	}
	close(fd);
	return (line_count);
}

char **make_map(char *mapfile)
{
	int		line_count;
	char	**map;
	int		row;
	int		fd;
	size_t	last;

	line_count = count_lines(mapfile);
	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		return (0);
	row = 0;
	fd = open(mapfile, O_RDONLY);
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

void	fill(char **area, t_point size, t_point vec, char to_fill)
{
	static int c_count = 0;
	static int e_count = 0;
	if (vec.y < 0 || vec.y >= size.y || vec.x < 0 || vec.x >= size.x || \
		area[vec.y][vec.x] != to_fill)
		return ;
	if (area[vec.x][vec.y] == 'C')
		c_count++;//coint got create this in the big struct
	if (area[vec.x][vec.y] == 'E')
		e_count++;//coint got
	area[vec.y][vec.x] = 'F';
	fill(area, size, (t_point){vec.x - 1, vec.y}, to_fill);
	fill(area, size, (t_point){vec.x + 1, vec.y}, to_fill);
	fill(area, size, (t_point){vec.x, vec.y - 1}, to_fill);
	fill(area, size, (t_point){vec.x, vec.y + 1}, to_fill);

		
}

int main()
{

	char **map;
	t_point coords;
	t_point map_size;

	coords.x = 0;//player x pos
	coords.y = 0;//player y pos
	map_size.x = 50;//width
	map_size.y = 70;//heigth
 	map = make_map("aaa.ber");
	//fill(map, map_size, coords, )
	int i = 0;

	while(map[i])
	{
		ft_printf("%s\n", map[i]);
		free(map[i]);
		i++;
	}
	free(map);
	
}
