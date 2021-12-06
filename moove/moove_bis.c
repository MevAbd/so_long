/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:34:43 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/06 20:03:41 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../soo_loong.h"

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
	else if (map->p_lig + 1 < map->nlig - 1
		&& map->tab[map->p_lig + 1][map->p_col] == 3 && map->coll == 0)
	{
		map->moove++;
		write(1, "moove : ", 8);
		ft_putnbr(map->moove);
		write(1, "\n", 1);
		write(1, "!!!WIN!!!\n", 10);
		ft_exit(map);
	}
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->add_img->player_down, map->p_col * IMG_H, map->p_lig * IMG_W);
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
	else if (map->p_lig + 1 < map->nlig - 1
		&& map->tab[map->p_lig + 1][map->p_col] == 5)
	{
		map->moove++;
		write(1, "moove : ", 8);
		ft_putnbr(map->moove);
		write(1, "\n", 1);
		write(1, "!!!YOU LOSE!!!\n", 15);
		ft_exit(map);
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
	else if (map->p_lig - 1 > 0 && map->tab[map->p_lig - 1][map->p_col] == 5)
	{
		map->moove++;
		write(1, "moove : ", 8);
		ft_putnbr(map->moove);
		write(1, "\n", 1);
		write(1, "!!!YOU LOSE!!!\n", 15);
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
