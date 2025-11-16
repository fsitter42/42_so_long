#include "so_long.h"

int count_of(char **map, char what_to_find);

int count_of(char **map, char what_to_find)
{
	int c_count = 0;
	int i = 0;
	while(map[i])
	{
		int j = 0;
		while(map[i][j])
		{
			if (map[i][j] == what_to_find)
				c_count++;
			j++;
		}
		i++;
	}
	return (c_count);
}

