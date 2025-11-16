int	check_borders(char **s, int xmax, int ymax)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i][j])
	{
		if (s[i][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	while (s[i])
	{
		if (s[i][0] != '1' || s[i][xmax] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (s[ymax][j])
	{
		if (s[ymax][j] != '1')
			return (0);
		j++;
	}
}

// eventuell int check_borders(char **map, int xmax, int xmin)

int main()
{
	
}