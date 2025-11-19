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
		return (ft_putstr_fd("Error: malloc error\n", 2), NULL);
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
