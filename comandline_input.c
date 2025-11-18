/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comandline_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsitter <fsitter@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:17:34 by fsitter           #+#    #+#             */
/*   Updated: 2025/11/18 16:27:23 by fsitter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_input(int argc, char *argv);
int	check_fd(char *argv);

int	check_input(int argc, char *argv)
{
	char	*file_ex;

	ft_printf("%s\n", argv);
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
