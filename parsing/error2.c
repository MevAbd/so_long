#include "../soo_loong.h"

t_map	ft_wall(t_map map, int i, int j)
{
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
	i = 0;
	j = 0;
	while (i < map.nlig)
	{
		if (map.tab[i][j] != 1)
			map.map_error = 1;
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
