/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 02:31:26 by malbrand          #+#    #+#             */
/*   Updated: 2021/11/26 08:19:40 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soo_loong.h"

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
		if (map.map_error == 1)
			write(1, "map error\n", 10);	
		else
			ft_print_tab(map);
		ft_free_tab(map);
	}
	else if (ac > 2)
		write (1, "too much arg\n", 13);
	return (0);
}
