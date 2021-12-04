/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 02:28:10 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/04 04:57:55 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "soo_loong.h"

void	ft_init_img(t_map *map)
{
	char	*path;
	int		width;
	int		height;
	t_img	*img;

	img = malloc(sizeof(t_img));
	map->add_img = img;
	path = "./img_final/sol.xpm";
	map->add_img->ground = mlx_xpm_file_to_image(map->mlx, path, &width, &height);
	path = "./img_final/wall_up.xpm";
	map->add_img->wall_up = mlx_xpm_file_to_image(map->mlx, path, &width, &height);
	path = "./img_final/wall_down.xpm";
	map->add_img->wall_down = mlx_xpm_file_to_image(map->mlx, path, &width, &height);
	path = "./img_final/wall_left.XPM";
	map->add_img->wall_left = mlx_xpm_file_to_image(map->mlx, path, &width, &height);
	path = "./img_final/wall_right.XPM";
	map->add_img->wall_right = mlx_xpm_file_to_image(map->mlx, path, &width, &height);
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
				mlx_put_image_to_window(map.mlx, map.mlx_win, map.add_img->ground, lig * IMG_H, col * IMG_W);
			col++;
		}
		lig++;
	}
}

void	ft_put_wall_up(t_map map)
{
	int	lig;
	int col;

	lig = 0;
	col = 0;
	ft_put_map(map);
	while (lig < 1)
	{
		col = 0;
		while (col < map.ncol)
		{
				mlx_put_image_to_window(map.mlx, map.mlx_win, map.add_img->wall_up, col * IMG_H, lig * IMG_W);
			col++;
		}
		lig++;
	}
}

void	ft_put_wall_down(t_map map)
{
	int	lig;
	int col;

	lig = map.nlig - 1;
	col = 0;
	ft_put_wall_up(map);
	while (lig < map.nlig)
	{
		col = 0;
		while (col < map.ncol)
		{
				mlx_put_image_to_window(map.mlx, map.mlx_win, map.add_img->wall_down, col * IMG_H, lig * IMG_W);
			col++;
		}
		lig++;
	}
}

void	ft_put_wall_right(t_map map)
{
	int	lig;
	int col;

	lig = 0;
	col = map.ncol -1;
	ft_put_wall_down(map);
	while (lig < map.nlig)
	{
		col = map.ncol -1;
		while (col < map.ncol)
		{
				mlx_put_image_to_window(map.mlx, map.mlx_win, map.add_img->wall_right, col * IMG_H, lig * IMG_W);
			col++;
		}
		lig++;
	}
}

void	ft_put_wall_left(t_map map)
{
	int	lig;
	int col;

	lig = 0;
	col = 0;
	ft_put_wall_down(map);
	ft_put_wall_right(map);
	while (lig < map.nlig)
	{
		col = 0;
		while (col < 1)
		{
				mlx_put_image_to_window(map.mlx, map.mlx_win, map.add_img->wall_left, col * IMG_H, lig * IMG_W);
			col++;
		}
		lig++;
	}
}
