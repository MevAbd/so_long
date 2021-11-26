/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 02:31:26 by malbrand          #+#    #+#             */
/*   Updated: 2021/11/26 04:49:20 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soo_loong.h"

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
/*
t_map	ft_fill_tab(t_map map)
{
	int		lig;
	int		col;
	char	*str;
	int		i;

	lig = 0;
	i = 0;
	map->tab = (int **)malloc(sizeof((int *) * map.nlig));
	if (map->tab == NULL)
		return (NULL);
	str = get_next_line(fd);
	while (lig < map.nlig)
	{
		if (str != NULL)
		{
			map->tab[lig] = (int *)malloc(sizeof (int * map.ncoll + 1));
			if (map->tab[lig] == NULL)
				return (NULL);
			col = 0;
			while (str[i] != '\n')
			{
				if (str[i] == '0')
					tab[lig][col] = 0;
				else if (str[i] == '1')
					tab[lig][col] = 1;
				else if (str[i] == 'C')
					tab[lig][col] = 2;
				else if (str[i] == 'E')
					tab[lig][col] = 3;
				else if (str[i] == 'P')
					tab[lig][col] = 4;
				col++;
			}
			tab[lig][col] = '\0';
		}
		lig++;
		free(str);	
		str = get_next_line(fd);
	}
	free(str);
	return (map);
}
*/
t_map	ft_error(int fd)
{
	t_map	map;

	map = ft_rectangular(fd);
	if (map.map_error == 1 || map.exit == 0 || map.player == 0 || map.coll == 0)
		map.map_error = 1;
//	else 
//		map = ft_fill_tab(map);
	return (map);
}
/*
void	ft_print_tab(t_map map)
{
	int	lig;
	int	col;

	lig = 0;
	while (lig < map.nlig)
	{
		col = 0;
		while (col < map.ncol)
		{
			printf("%d", map->tab[lig][col]);
			col++;
		}
		lig++;
	}
}
*/
int	main(int ac, char **av)
{
	int		fd;
	t_map	map;

	if (ac == 1)
		write (1, "missing map\n", 12);
	else if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		map = ft_error(fd);
		if (map.map_error == 1)
			write(1, "map error\n", 10);
		
//		else
//			ft_print_tab(map);
	}
	else if (ac > 2)
		write (1, "too much arg\n", 13);
	return (0);
}
