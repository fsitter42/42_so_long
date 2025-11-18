/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:38:11 by fsitter           #+#    #+#             */
/*   Updated: 2025/11/18 17:02:07 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	struct s_mapdata	mapdata;

	if (check_input(argc, argv[1]) == 0)
		return (1);
	mapdata.map = make_map(argv[1]);
	if (!mapdata.map)
		return (1);
}

// += t_data data; // for window zeile 18

	// mapdata.map = make_map(argv[1], fd);
	// int i = 0;
	// while (mapdata.map[i])
	// {
	// 	ft_printf("%s\n", mapdata.map[i]);
	// 	free(mapdata.map[i]);
	// 	i++;
	// }
	// free(mapdata.map);
	// ft_printf("hello\n");