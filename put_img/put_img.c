/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 12:51:26 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/05 13:04:51 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../soo_loong.h"

void	ft_put_wall_down(t_map map)
{
	int	lig;
	int	col;

	lig = map.nlig - 1;
	col = 0;
	ft_put_wall_up(map);
	while (lig < map.nlig)
	{
		col = 0;
		while (col < map.ncol)
		{
			mlx_put_image_to_window(map.mlx, map.mlx_win,
				map.add_img->wall_down, col * IMG_H, lig * IMG_W);
			col++;
		}
		lig++;
	}
}

void	ft_put_wall_right(t_map map)
{
	int	lig;
	int	col;

	lig = 0;
	col = map.ncol -1;
	ft_put_wall_down(map);
	while (lig < map.nlig)
	{
		col = map.ncol -1;
		while (col < map.ncol)
		{
			mlx_put_image_to_window(map.mlx, map.mlx_win,
				map.add_img->wall_right, col * IMG_H, lig * IMG_W);
			col++;
		}
		lig++;
	}
}

void	ft_put_wall_left(t_map map)
{
	int	lig;
	int	col;

	lig = 0;
	col = 0;
	ft_put_wall_down(map);
	ft_put_wall_right(map);
	while (lig < map.nlig)
	{
		col = 0;
		while (col < 1)
		{
			mlx_put_image_to_window(map.mlx, map.mlx_win,
				map.add_img->wall_left, col * IMG_H, lig * IMG_W);
			col++;
		}
		lig++;
	}
}

void	ft_put_corner(t_map map)
{
	ft_put_wall_left(map);
	mlx_put_image_to_window(map.mlx, map.mlx_win,
		map.add_img->corner_h_l, 0 * IMG_H, 0 * IMG_W);
	mlx_put_image_to_window(map.mlx, map.mlx_win,
		map.add_img->corner_h_r, ((map.ncol - 1) * IMG_H), 0 * IMG_W);
	mlx_put_image_to_window(map.mlx, map.mlx_win,
		map.add_img->corner_d_l, 0 * IMG_H, ((map.nlig - 1) * IMG_W));
	mlx_put_image_to_window(map.mlx, map.mlx_win,
		map.add_img->corner_d_r, ((map.ncol - 1) * IMG_H),
		((map.nlig - 1) * IMG_W));
}

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
			else if (map.tab[lig][col] == 4)
				mlx_put_image_to_window(map.mlx, map.mlx_win,
					map.add_img->player_down, col * IMG_H, lig * IMG_W);
		}
	}
}
