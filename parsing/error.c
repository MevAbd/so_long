/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 05:37:55 by malbrand          #+#    #+#             */
/*   Updated: 2021/11/26 08:40:35 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../soo_loong.h"

t_map	ft_check_wall(t_map map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < map.ncol)
	{
		if (map.tab[i][j] != 1)
			map.map_error = 1;
		j++;
		if (j == (map.ncol) && i != (map.nlig - 1))
		{
			i = map.nlig - 1;
			j = 0;
		}
	}
	j = 0;
/*	while (j < map.ncol)
	{
		if (map.tab[map.nlig - 1][j] != 1)
			map.map_error = 1;
		j++;
	}*/
	while (i < map.nlig)
	{
		if (map.tab[i][j] != 1)
			map.map_error = 1;
		i++;
		printf("%d\n", map.ncol);
		printf("%d\n", map.nlig);
		if (i == (map.nlig) && j != (map.ncol - 1))
		{
			printf("icci\n");
			j = map.ncol - 1;
			i = 0;
		}
	}
/*	i = 0;
	while (i < map.nlig)
	{
		if (map.tab[i][map.ncol - 1] != 1)
			map.map_error = 1;
		i++;
	}*/
	return (map);
}

t_map	ft_check_map(char *str, t_map map)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == '1')
			map.wall += 1;
		else if (str[i] == 'C')
			map.coll += 1;
		else if (str[i] == 'E')
			map.exit += 1;
		else if (str[i] == 'P')
			map.player += 1;
		else if (str[i] != '1' && str[i] != 'C'
			&& str[i] != 'E' && str[i] != 'P' && str[i] != '0')
		{
			map.map_error = 1;
			return (map);
		}
		i++;
	}
	return (map);
}

t_map	ft_init_struct(t_map map)
{
	map.map_error = 0;
	map.nlig = 0;
	map.wall = 0;
	map.coll = 0;
	map.exit = 0;
	map.player = 0;
	return (map);
}

t_map	ft_rectangular(int fd)
{
	char	*str;
	t_map	map;

	str = get_next_line(fd);
	map = ft_init_struct(map);
	map.ncol = ft_strlen_bis(str);
	while (str)
	{
		if (str != NULL)
		{
			if (ft_strlen_bis(str) != map.ncol)
				map.map_error = 1;
			map.nlig += 1;
			map = ft_check_map(str, map);
		}
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (map);
}

t_map	ft_error(int fd, char *av)
{
	t_map	map;
	int		fd_bis;

	fd_bis = open(av, O_RDONLY);
	map = ft_rectangular(fd);
	if (map.map_error == 1 || map.exit == 0 || map.player == 0 || map.coll == 0)
		map.map_error = 1;
	else
	{
		map = ft_fill_tab(map, fd_bis);
		map = ft_check_wall(map);
	}
	return (map);
}
