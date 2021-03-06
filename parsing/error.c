/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 05:37:55 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/06 20:40:07 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../soo_loong.h"

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
		else if (str[i] == 'L')
			map.enemy += 1;
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

t_map	ft_init_struct(t_map *map)
{
	map->map_error = 0;
	map->nlig = 0;
	map->wall = 0;
	map->coll = 0;
	map->exit = 0;
	map->enemy = 0;
	map->player = 0;
	map->moove = 0;
	return (*map);
}

t_map	ft_rectangular(int fd)
{
	char	*str;
	t_map	map;

	str = get_next_line(fd);
	map = ft_init_struct(&map);
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

void	ft_ber(char *av)
{
	int		i;

	i = 0;
	while (av[i] != '\0')
		i++;
	if (av[i - 1] != 'r' || av[i - 2] != 'e' || av[i - 3] != 'b')
	{
		write(1, "Error\nIs not a .ber\n", 20);
		exit(0);
	}
}

t_map	ft_error(int fd, char *av)
{
	t_map	map;
	int		fd_bis;

	ft_ber(av);
	fd_bis = open(av, O_RDONLY);
	map = ft_rectangular(fd);
	if (map.exit == 0)
		map.map_error = 2;
	else if (map.player == 0)
		map.map_error = 3;
	else if (map.player > 1)
		map.map_error = 4;
	else if (map.coll == 0)
		map.map_error = 5;
	else
	{
		map = ft_fill_tab(map, fd_bis);
		map = ft_check_wall(map);
	}
	if (map.map_error != 0)
		ft_write_error(map);
	return (map);
}
