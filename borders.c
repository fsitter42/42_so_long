#include "so_long.h"

int	check_borders(char **map, int xmax, int ymax);
int	check_form(char **map);
int	check_signs(char **map);
void find_sign(char **map, char to_find, int *x, int *y);

int	check_borders(char **map, int xmax, int ymax)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][j])
	{
		if (map[i][j++] != '1')
			return (0);
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][xmax] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (map[ymax][j])
	{
		if (map[ymax][j++] != '1')
			return (0);
	}
	return (1);
}

int	check_form(char **map)
{
	int	i;
	int	firstline_len;

	firstline_len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != firstline_len)
			return (0);
		i++;
	}
	return (1);
}

int	check_signs(char **map)
{
	int		i;
	int		j;
	char	*valid_signs;

	valid_signs = "pce01";
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(ft_strchr(valid_signs, map[i][j])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void find_sign(char **map, char to_find, int *x, int *y)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == to_find)
			{
				*x = i;
				*y = j;
				return;
			}
			j++;
		}
		i++;
	}
}
