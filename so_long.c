/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:38:11 by fsitter           #+#    #+#             */
/*   Updated: 2025/11/19 12:54:17 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	struct s_mapdata	mapdata;

	if (check_input(argc, argv[1]) == 0)
		return (1);
	fill_mapdata(&mapdata, argv[1]);

		
	int i = 0;
	while (mapdata.map[i])
	{
		ft_printf("%s\n", mapdata.map[i]);
		free(mapdata.map[i]);
		i++;
	}
	free(mapdata.map);
	ft_printf("\n");
	ft_printf("x: %i\n", mapdata.map_width_x);
	ft_printf("y: %i\n", mapdata.map_height_y);
	ft_printf("\n");
}

// += t_data data; // for window zeile 18

