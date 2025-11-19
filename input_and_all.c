/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_and_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:17:34 by fsitter           #+#    #+#             */
/*   Updated: 2025/11/19 16:15:32 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		check_input(int argc, char *argv);
int		check_map_all(struct s_mapdata *data);
int		count_all(struct s_mapdata *data);
void	find_all(struct s_mapdata *data);

int	check_input(int argc, char *argv)
{
	char	*file_ex;

	if (argc != 2)
	{
		ft_printf("Error: wrong number of argmuents!\n");
		return (0);
	}
	file_ex = ".ber";
	if (!(ft_strnstr(argv, file_ex, ft_strlen(argv))))
	{
		ft_printf("Error: wrong fileextension!\n");
		return (0);
	}
	if (ft_strlen(ft_strnstr(argv, file_ex, ft_strlen(argv))) != 4)
	{
		ft_printf("Error: wrong fileextension!\n");
		return (0);
	}
	return (1);
}

int	check_map_all(struct s_mapdata *data)
{
	if (check_form(data->map) == 0)
	{
		ft_printf("Error: Not rectangular!\n");
		return (0);
	}
	if (check_borders(data->map, data->map_width_x - 1, data->map_height_y
			- 1) == 0)
	{
		ft_printf("Error: Borders!\n");
		return (0);
	}
	if (check_signs(data->map) == 0)
	{
		ft_printf("Error: Contains non valid signs!\n");
		return (0);
	}
	return (1);
}

int	count_all(struct s_mapdata *data)
{
	data->player_c = count_of(data->map, 'p');
	if (data->player_c != 1)
	{
		ft_printf("Error: No Player!\n");
		return (0);
	}
	data->exit_c = count_of(data->map, 'e');
	if (data->exit_c != 1)
	{
		ft_printf("Error: No Exit!\n");
		return (0);
	}
	data->coin_c = count_of(data->map, 'c');
	if (data->coin_c < 1)
	{
		ft_printf("Error: No coin!\n");
		return (0);
	}
	return (1);
}

void	find_all(struct s_mapdata *data)
{
	find_sign(data->map, 'p', &data->playerposition_x, &data->playerposition_y);
	find_sign(data->map, 'e', &data->exitposition_x, &data->exitposition_y);
}
