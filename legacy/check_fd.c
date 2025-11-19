
int	check_fd(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: filediscriptor!\n");
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
