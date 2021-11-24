int	main(int ac, char **av)
{
	int		fd;
	char	*str;

	if (ac == 1)
		write (1, "missing map\n", 12);
	else if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		str = get_next_line(fd);
		write(1, str, ft_strlen(str));
		free(str);
	}
	else if (ac > 2)
		write (1, "too much arg\n", 13);
	return (0);
}
