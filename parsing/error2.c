/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:41:58 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/05 13:39:41 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../soo_loong.h"

t_map	ft_wall(t_map map, int i, int j)
{
	while (j < map.ncol)
	{
		if (map.tab[i][j] != 1)
			map.map_error = 6;
		j++;
		if (j == (map.ncol) && i != (map.nlig - 1))
		{
			i = map.nlig - 1;
			j = 0;
		}
	}
	i = 0;
	j = 0;
	while (i < map.nlig)
	{
		if (map.tab[i][j] != 1)
			map.map_error = 6;
		i++;
		if (i == (map.nlig) && j != (map.ncol - 1))
		{
			j = map.ncol - 1;
			i = 0;
		}
	}
	return (map);
}

t_map	ft_check_wall(t_map map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map = ft_wall(map, i, j);
	return (map);
}

void	ft_write_error(t_map map)
{
	if (map.map_error == 1)
		write(1, "Error\nInformation not recognized in the map\n", 44);
	else if (map.map_error == 2)
		write(1, "Error\nMissing exit\n", 19);
	else if (map.map_error == 3)
		write(1, "Error\nMissing player\n", 21);
	else if (map.map_error == 4)
		write(1, "Error\nToo much players\n", 23);
	else if (map.map_error == 5)
		write(1, "Error\nMissing collectible\n", 26);
	else if (map.map_error == 6)
		write(1, "Error\nMissing of wall at the outlines\n", 38);
}
