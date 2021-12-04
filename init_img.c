/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 02:28:10 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/04 05:39:26 by malbrand         ###   ########.fr       */
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
	path = "./img_final/angle.XPM";
	map->add_img->corner_h_l = mlx_xpm_file_to_image(map->mlx, path, &width, &height);
	path = "./img_final/w_d_left.XPM";
	map->add_img->corner_d_l = mlx_xpm_file_to_image(map->mlx, path, &width, &height);
	path = "./img_final/w_d_right.XPM";
	map->add_img->corner_d_r = mlx_xpm_file_to_image(map->mlx, path, &width, &height);
	path = "./img_final/w_h_right.XPM";
	map->add_img->corner_h_r = mlx_xpm_file_to_image(map->mlx, path, &width, &height);
	path = "./img_final/blood.xpm";
	map->add_img->coll = mlx_xpm_file_to_image(map->mlx, path, &width, &height);
	path = "./img_final/wall_inside.xpm";
	map->add_img->wall_inside = mlx_xpm_file_to_image(map->mlx, path, &width, &height);
	path = "./img_final/exit.xpm";
	map->add_img->exit = mlx_xpm_file_to_image(map->mlx, path, &width, &height);
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
			mlx_put_image_to_window(map.mlx, map.mlx_win, map.add_img->ground, col * IMG_H, lig * IMG_W);
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

void	ft_put_corner(t_map map)
{
	ft_put_wall_left(map);
	mlx_put_image_to_window(map.mlx, map.mlx_win, map.add_img->corner_h_l, 0 * IMG_H, 0 * IMG_W);
	mlx_put_image_to_window(map.mlx, map.mlx_win, map.add_img->corner_h_r, ((map.ncol - 1) * IMG_H), 0 * IMG_W);
	mlx_put_image_to_window(map.mlx, map.mlx_win, map.add_img->corner_d_l, 0 * IMG_H, ((map.nlig - 1 )* IMG_W));
	mlx_put_image_to_window(map.mlx, map.mlx_win, map.add_img->corner_d_r, ((map.ncol - 1) * IMG_H), ((map.nlig - 1) * IMG_W));
}

void	ft_put_img(t_map map)
{
	int	lig;
	int	col;

	lig = 1; 
	col = 1;
	ft_put_corner(map);
	while (lig < map.nlig - 1)
	{
		col = 1;
		while (col < map.ncol - 1)
		{
			if (map.tab[lig][col] == 2)
				mlx_put_image_to_window(map.mlx, map.mlx_win, map.add_img->coll, col * IMG_H, lig * IMG_W);
			else if (map.tab[lig][col] == 1)
				mlx_put_image_to_window(map.mlx, map.mlx_win, map.add_img->wall_inside, col * IMG_H, lig * IMG_W);
			else if (map.tab[lig][col] == 3)
				mlx_put_image_to_window(map.mlx, map.mlx_win, map.add_img->exit, col * IMG_H, lig * IMG_W);
			col++;
		}
		lig++;
	}
}


