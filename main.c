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
		else if (str[i] != '1' && str[i] != 'C' && str[i] != 'E' && str[i] != 'P' && str[i] != '0')
		{
			map.map_error = 1;
			return (map);
		}
		i++;
	}
	return (map);
}

t_map	ft_rectangular(int fd)
{
	char	*str;
	t_map	map;

	str = get_next_line(fd);
	map.ncol = ft_strlen_bis(str);
	map.map_error = 0;
	map.nlig = 0;
	map.wall = 0;
	map.coll = 0;
	map.exit = 0;
	map.player = 0;
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

int main(int ac, char **av)
{
	int		fd;
	t_map	map;

	if (ac == 1)
		write (1, "missing map\n", 12);
	else if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		map = ft_rectangular(fd);
		if (map.map_error == 1 || map.exit == 0 || map.player == 0 || map.coll == 0)
		{
			write(1, "map error\n", 10);
			return (0);
		}
		printf("ligne = %d colonnes = %d\n", map.nlig, map.ncol);
	}
	else if (ac > 2)
		write (1, "too much arg\n", 13);
	return (0);
}
