#include "./../soo_loong.h"

int	ft_exit(t_map *map)
{
	mlx_destroy_window(map->mlx, map->mlx_win);
	return (0);
}

void	ft_moov_d(t_map *map)
{
	if (map->p_lig + 1 < map->nlig - 1
		&& map->tab[map->p_lig + 1][map->p_col] == 2)
	{
		map->tab[map->p_lig][map->p_col] = 0;
		map->p_lig = map->p_lig + 1;
		map->coll--;
		map->moove++;
		write(1, "moove : ", 8);
		ft_putnbr(map->moove);
		write(1, "\n", 1);
	}
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->add_img->player_down, map->p_col * IMG_H, map->p_lig * IMG_W);
	if (map->p_lig + 1 < map->nlig - 1
		&& map->tab[map->p_lig + 1][map->p_col] == 3 && map->coll == 0)
	{
		map->moove++;
		write(1, "moove : ", 8);
		ft_putnbr(map->moove);
		write(1, "\n", 1);
		write(1, "!!!WIN!!!\n", 10);
		ft_exit(map);
	}
}

void	ft_moove_down(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->add_img->ground, map->p_col * IMG_H, map->p_lig * IMG_W);
	if (map->p_lig + 1 < map->nlig - 1
		&& map->tab[map->p_lig + 1][map->p_col] == 0)
	{
		map->tab[map->p_lig][map->p_col] = 0;
		map->p_lig = map->p_lig + 1;
		map->moove++;
		write(1, "moove : ", 8);
		ft_putnbr(map->moove);
		write(1, "\n", 1);
	}
	ft_moov_d(map);
}

void	ft_moove_up_b(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->add_img->player_up, map->p_col * IMG_H, map->p_lig * IMG_W);
	if (map->p_lig - 1 > 0 && map->tab[map->p_lig - 1][map->p_col] == 3
		&& map->coll == 0)
	{
		map->moove++;
		write(1, "moove : ", 8);
		ft_putnbr(map->moove);
		write(1, "\n", 1);
		write(1, "!!!WIN!!!\n", 10);
		ft_exit(map);
	}
}

void	ft_moove_up(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->add_img->ground, map->p_col * IMG_H, map->p_lig * IMG_W);
	if (map->p_lig - 1 > 0 && map->tab[map->p_lig - 1][map->p_col] == 0)
	{
		map->tab[map->p_lig][map->p_col] = 0;
		map->p_lig = map->p_lig - 1;
		map->moove++;
		write(1, "moove : ", 8);
		ft_putnbr(map->moove);
		write(1, "\n", 1);
	}
	else if (map->p_lig - 1 > 0 && map->tab[map->p_lig - 1][map->p_col] == 2)
	{
		map->tab[map->p_lig][map->p_col] = 0;
		map->p_lig = map->p_lig - 1;
		map->coll--;
		map->moove++;
		write(1, "moove : ", 8);
		ft_putnbr(map->moove);
		write(1, "\n", 1);
	}
	ft_moove_up_b(map);
}
