/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:56:50 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/06 19:55:00 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../soo_loong.h"

void	ft_put_img(t_map map)
{
	int	lig;
	int	col;

	lig = 0;
	ft_put_corner(map);
	while (++lig < map.nlig - 1)
	{
		col = 0;
		while (++col < map.ncol - 1)
		{
			if (map.tab[lig][col] == 2)
				mlx_put_image_to_window(map.mlx, map.mlx_win,
					map.add_img->coll, col * IMG_H, lig * IMG_W);
			else if (map.tab[lig][col] == 1)
				mlx_put_image_to_window(map.mlx, map.mlx_win,
					map.add_img->wall_inside, col * IMG_H, lig * IMG_W);
			else if (map.tab[lig][col] == 3)
				mlx_put_image_to_window(map.mlx, map.mlx_win,
					map.add_img->exit, col * IMG_H, lig * IMG_W);
			else
				ft_put_bis(map, lig, col);
		}
	}
}

void	ft_put_map(t_map map)
{
	int		lig;
	int		col;

	lig = 0;
	col = 0;
	while (lig < map.nlig)
	{
		col = 0;
		while (col < map.ncol)
		{
			mlx_put_image_to_window(map.mlx, map.mlx_win, map.add_img->ground,
				col * IMG_H, lig * IMG_W);
			col++;
		}
		lig++;
	}
}

void	ft_put_wall_up(t_map map)
{
	int	lig;
	int	col;

	lig = 0;
	col = 0;
	ft_put_map(map);
	while (lig < 1)
	{
		col = 0;
		while (col < map.ncol)
		{
			mlx_put_image_to_window(map.mlx, map.mlx_win, map.add_img->wall_up,
				col * IMG_H, lig * IMG_W);
			col++;
		}
		lig++;
	}
}
