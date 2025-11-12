#include "get_next_line.h"
#include <stdio.h>

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
	row = 0;
	fd = open(mapfile, O_RDONLY);
	while (row < line_count)
	{
		map[row] = get_next_line(fd);
		last = ft_strlen(map[row]);
		map[row][last - 1] = '\0';
		row++;
	}
	map[line_count] = NULL;
	close(fd);
	return (map);
}

int main()
{

	char **map;
	map = make_map("aaa.ber");
	int i = 0;

	while(map[i])
	{
		printf("%s\n", map[i]);
		free(map[i]);
		i++;
	}
	free(map);
}
