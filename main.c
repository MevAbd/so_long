/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 02:31:26 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/06 21:34:35 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soo_loong.h"

void	ft_test(t_map *map)
{
	mlx_hook(map->mlx_win, 17, 1L << 2, ft_exit, map);
	mlx_key_hook(map->mlx_win, ft_key, map);
}

void	ft_env(t_map map)
{
	ft_free_tab(&map);
	exit(0);
}

int	main(int ac, char **av)
{
	int		fd;
	t_map	map;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			exit(0);
		map = ft_error(fd, av[1]);
		if (map.map_error == 0)
		{
			map.mlx = mlx_init();
			if (!map.mlx)
				ft_env(map);
			ft_init_img(&map);
			map.mlx_win = mlx_new_window(map.mlx, (map.ncol * IMG_W),
					(map.nlig * IMG_H), "so_long");
			ft_put_img(map);
			ft_test(&map);
			mlx_loop(map.mlx);
		}
	}
	else
		write (1, "Error\nNot the right number of arguments\n", 40);
	return (0);
}
