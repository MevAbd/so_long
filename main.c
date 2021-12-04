/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 02:31:26 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/04 05:38:14 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soo_loong.h"

int	main(int ac, char **av)
{
	int		fd;
	t_map	map;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		map = ft_error(fd, av[1]);
		printf("lig == %d col == %d\n", map.nlig, map.ncol);	
		if (map.map_error == 0)
		{
			map.mlx = mlx_init();
			ft_init_img(&map);
			map.mlx_win = mlx_new_window(map.mlx, (map.ncol * IMG_W), (map.nlig * IMG_H), "so_long");
			ft_put_corner(map);
			mlx_loop(map.mlx);
		}
	}
	else
		write (1, "Error\nNot the right number of arguments\n", 40);
	return (0);
}
