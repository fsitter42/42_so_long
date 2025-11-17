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

	int borders = check_borders(map, ((ft_strlen(map[0])) - 1), count_lines("aaa.ber") - 1);

	if (borders == 1)
		ft_printf("Borders are closed\n");
	else
		ft_printf("ERROR: Borders are open\n");

	int form = check_form(map);

	if (form == 1)
		ft_printf("Map is rectangular\n");
	else
		ft_printf("ERROR: Map is not rectangular\n");

	int filling_valid = check_signs(map);

	if (filling_valid == 1)
		ft_printf("Map is filled correct\n");
	else
		ft_printf("ERROR: Map is not filled correct\n");


	int x = 0;
	int y = 0;

	char to_find = 'p';

	find_sign(map, to_find, &x, &y);

	ft_printf("The char %c, is at postion x: %i and y: %i\n", to_find, x, y);

	ft_printf("\n");
	while(map[i])
	{
		ft_printf("%s\n", map[i]);
		free(map[i]);
		i++;
	}
	free(map);
	ft_printf("hello\n");
	
}