#include "so_long.h"

int main()
{

	char **map;
	// t_point coords;
	// t_point map_size;

	// coords.x = 0;//player x pos
	// coords.y = 0;//player y pos
	// map_size.x = 50;//width
	// map_size.y = 70;//heigth
 	map = make_map("aaa.ber");
	//fill(map, map_size, coords, )
	int i = 0;

	ft_printf("%i\n", count_of(map, 'c'));

	ft_printf("%i\n", ft_strlen(map[0]) -1);

	int b = check_borders(map, (ft_strlen(map[0])) - 1, count_lines("aaa.ber") - 1);

	if (b == 1)
		ft_printf("Borders are closed\n");
	else
		ft_printf("Borders are open\n");

	while(map[i])
	{
		ft_printf("%s\n", map[i]);
		free(map[i]);
		i++;
	}
	free(map);
	
}