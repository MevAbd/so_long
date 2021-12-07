/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 05:38:33 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/07 12:32:46 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../soo_loong.h"

t_map	ft_fill_bis(t_map map, char c, int lig, int col)
{
	if (c == '0')
		map.tab[lig][col] = 0;
	else if (c == '1')
		map.tab[lig][col] = 1;
	else if (c == 'C')
		map.tab[lig][col] = 2;
	else if (c == 'E')
		map.tab[lig][col] = 3;
	else if (c == 'L')
		map.tab[lig][col] = 5;
	else if (c == 'P')
	{
		map.tab[lig][col] = 4;
		map.p_lig = lig;
		map.p_col = col;
	}
	return (map);
}

t_map	ft_malloc(t_map map)
{
	map.tab = (int **)malloc(map.nlig * sizeof(int *));
	if (!map.tab)
		ft_exit(&map);
	return (map);
}

t_map	ft_malloc_bis(t_map map, int *lig)
{
	map.tab[++(*lig)] = (int *)malloc((map.ncol + 1) * sizeof (int));
	if (!map.tab[(*lig)])
		ft_exit(&map);
	return (map);
}

t_map	ft_fill_tab(t_map map, int fd)
{
	int		lig;
	int		col;
	char	*str;
	int		i;

	lig = -1;
	map = ft_malloc(map);
	str = get_next_line(fd);
	while (str)
	{
		if (str != NULL)
		{
			map = ft_malloc_bis(map, &lig);
			col = -1;
			i = -1;
			while (++i < map.ncol)
				map = ft_fill_bis(map, str[i], lig, ++col);
		}
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (map);
}

void	ft_free_tab(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->nlig)
	{
		free(map->tab[i]);
		i++;
	}
	free(map->tab);
}
