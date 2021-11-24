#include "soo_loong.h"

int	ft_check_fd(int fd)
{
	char	*str;
	

	str = get_next_line(fd);
	while (str)
	{
		if (str != NULL)
			write(1, str, ft_strlen(str));
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (1);
}

int main(int ac, char **av)
{
	int		fd;

	if (ac == 1)
		write (1, "missing map\n", 12);
	else if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (ft_check_fd(fd) == - 1)
			write(1, "map error\n", 10);
	}
	else if (ac > 2)
		write (1, "too much arg\n", 13);
	return (0);
}
