/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 02:31:26 by malbrand          #+#    #+#             */
/*   Updated: 2021/11/26 23:50:33 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soo_loong.h"

void	ft_map(t_map *map)
{
	ft_create_map(map);
}

int	main(int ac, char **av)
{
	int		fd;
	t_map	map;

	if (ac == 1)
		write (1, "missing map\n", 12);
	else if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		map = ft_error(fd, av[1]);
		if (map.map_error == 0)
		{
			map.mlx = mlx_init();
			ft_init_img(&map);
			map.mlx_win = mlx_new_window(map.mlx, map.nlig * IMG_W, map.ncol * IMG_H, "so_long");
			ft_map(&map);
		}
	}
	else if (ac > 2)
		write (1, "too much arg\n", 13);
	return (0);
}
