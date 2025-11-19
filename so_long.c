/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:38:11 by fsitter           #+#    #+#             */
/*   Updated: 2025/11/19 14:57:16 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	struct s_mapdata	mapdata;

	if (check_input(argc, argv[1]) == 0)
		return (1);
	if (fill_mapdata(&mapdata, argv[1]) == 0)
		return (1);

	int i = 0;
	while (mapdata.map[i])
	{
		ft_printf("%s\n", mapdata.map[i]);
		free(mapdata.map[i]);
		i++;
	}
	free(mapdata.map);
	ft_printf("\n");
	ft_printf("Player count: %i\n", mapdata.player_c);
	ft_printf("Exit count: %i\n", mapdata.exit_c);
	ft_printf("Coin ount: %i\n", mapdata.coin_c);	
	ft_printf("x: %i\n", mapdata.map_width_x);
	ft_printf("y: %i\n", mapdata.map_height_y);
	ft_printf("Player position x: %i, y: %i\n", mapdata.playerposition_x, mapdata.playerposition_y);
	ft_printf("Exit position x: %i, y: %i\n", mapdata.exitposition_x, mapdata.exitposition_y);

	ft_printf("\n");
}

// += t_data data; // for window zeile 18

