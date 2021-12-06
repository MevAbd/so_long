/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moov.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 13:06:42 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/05 13:47:50 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../soo_loong.h"

void	ft_moove_left_b(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->add_img->player_left, map->p_col * IMG_H, map->p_lig * IMG_W);
	if (map->p_col - 1 > 0 && map->tab[map->p_lig][map->p_col - 1] == 3
		&& map->coll == 0)
	{
		map->moove++;
		write(1, "moove : ", 8);
		ft_putnbr(map->moove);
		write(1, "\n", 1);
		write(1, "!!!WIN!!!\n", 10);
		ft_exit(map);
	}
	else if (map->p_col - 1 > 0 && map->tab[map->p_lig][map->p_col - 1] == 5)
	{
		map->moove++;
		write(1, "moove : ", 8);
		ft_putnbr(map->moove);
		write(1, "\n", 1);
		write(1, "!!!YOU LOSE!!!\n", 15);
		ft_exit(map);
	}
}

void	ft_moove_left(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->add_img->ground, map->p_col * IMG_H, map->p_lig * IMG_W);
	if (map->p_col - 1 > 0 && map->tab[map->p_lig][map->p_col - 1] == 0)
	{
		map->tab[map->p_lig][map->p_col] = 0;
		map->p_col = map->p_col - 1;
		map->moove++;
		write(1, "moove : ", 8);
		ft_putnbr(map->moove);
		write(1, "\n", 1);
	}
	else if (map->p_col - 1 > 0 && map->tab[map->p_lig][map->p_col - 1] == 2)
	{
		map->tab[map->p_lig][map->p_col] = 0;
		map->p_col = map->p_col - 1;
		map->coll--;
		map->moove++;
		write(1, "moove : ", 8);
		ft_putnbr(map->moove);
		write(1, "\n", 1);
	}
	ft_moove_left_b(map);
}

void	ft_moove_right_b(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->add_img->player_right, map->p_col * IMG_H, map->p_lig * IMG_W);
	if (map->p_col + 1 < map->ncol - 1
		&& map->tab[map->p_lig][map->p_col + 1] == 3 && map->coll == 0)
	{
		map->moove++;
		write(1, "moove : ", 8);
		ft_putnbr(map->moove);
		write(1, "\n", 1);
		write(1, "!!!WIN!!!\n", 10);
		ft_exit(map);
	}
	else if (map->p_col + 1 < map->ncol - 1
		&& map->tab[map->p_lig][map->p_col + 1] == 5)
	{
		map->moove++;
		write(1, "moove : ", 8);
		ft_putnbr(map->moove);
		write(1, "\n", 1);
		write(1, "!!!YOU LOSE!!!\n", 15);
		ft_exit(map);
	}
}

void	ft_moove_right(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->add_img->ground, map->p_col * IMG_H, map->p_lig * IMG_W);
	if (map->p_col + 1 < map->ncol - 1
		&& map->tab[map->p_lig][map->p_col + 1] == 0)
	{
		map->tab[map->p_lig][map->p_col] = 0;
		map->p_col = map->p_col + 1;
		map->moove++;
		write(1, "moove : ", 8);
		ft_putnbr(map->moove);
		write(1, "\n", 1);
	}
	else if (map->p_col + 1 < map->ncol - 1
		&& map->tab[map->p_lig][map->p_col + 1] == 2)
	{
		map->tab[map->p_lig][map->p_col] = 0;
		map->p_col = map->p_col + 1;
		map->coll--;
		map->moove++;
		write(1, "moove : ", 8);
		ft_putnbr(map->moove);
		write(1, "\n", 1);
	}
	ft_moove_right_b(map);
}

int	ft_key(int key, t_map *map)
{
	if (key == 119 || key == 122)
		ft_moove_up(map);
	else if (key == 113 || key == 97)
		ft_moove_left(map);
	else if (key == 100)
		ft_moove_right(map);
	else if (key == 115)
		ft_moove_down(map);
	return (0);
}
