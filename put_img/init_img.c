/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 02:28:10 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/05 12:51:42 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../soo_loong.h"

void	ft_init_img_bis(t_map *map)
{
	char	*path;
	int		width;
	int		height;

	width = 0;
	height = 0;
	path = "./img_final/w_d_right.XPM";
	map->add_img->corner_d_r = mlx_xpm_file_to_image(map->mlx, path,
			&width, &height);
	path = "./img_final/w_h_right.XPM";
	map->add_img->corner_h_r = mlx_xpm_file_to_image(map->mlx, path,
			&width, &height);
	path = "./img_final/blood.xpm";
	map->add_img->coll = mlx_xpm_file_to_image(map->mlx, path,
			&width, &height);
	path = "./img_final/wall_inside.xpm";
	map->add_img->wall_inside = mlx_xpm_file_to_image(map->mlx, path,
			&width, &height);
	path = "./img_final/exit.xpm";
	map->add_img->exit = mlx_xpm_file_to_image(map->mlx, path,
			&width, &height);
	path = "./img_final/down.xpm";
	map->add_img->player_down = mlx_xpm_file_to_image(map->mlx, path,
			&width, &height);
	path = "./img_final/ennemie.xpm";
	map->add_img->enemy = mlx_xpm_file_to_image(map->mlx, path,
			&width, &height);
}

void	ft_init_img_ter(t_map *map)
{
	char	*path;
	int		width;
	int		height;

	width = 0;
	height = 0;
	path = "./img_final/angle.XPM";
	map->add_img->corner_h_l = mlx_xpm_file_to_image(map->mlx, path,
			&width, &height);
	path = "./img_final/w_d_left.XPM";
	map->add_img->corner_d_l = mlx_xpm_file_to_image(map->mlx, path,
			&width, &height);
	path = "./img_final/left.xpm";
	map->add_img->player_left = mlx_xpm_file_to_image(map->mlx, path,
			&width, &height);
	path = "./img_final/right.xpm";
	map->add_img->player_right = mlx_xpm_file_to_image(map->mlx, path,
			&width, &height);
	path = "./img_final/up.xpm";
	map->add_img->player_up = mlx_xpm_file_to_image(map->mlx, path,
			&width, &height);
	path = "./img_final/wall_right.XPM";
	map->add_img->wall_right = mlx_xpm_file_to_image(map->mlx, path,
			&width, &height);
}

void	ft_init_img(t_map *map)
{
	char	*path;
	int		width;
	int		height;
	t_img	*img;

	img = malloc(sizeof(t_img));
	map->add_img = img;
	width = 0;
	height = 0;
	path = "./img_final/sol.xpm";
	map->add_img->ground = mlx_xpm_file_to_image(map->mlx, path,
			&width, &height);
	path = "./img_final/wall_up.xpm";
	map->add_img->wall_up = mlx_xpm_file_to_image(map->mlx, path,
			&width, &height);
	path = "./img_final/wall_down.xpm";
	map->add_img->wall_down = mlx_xpm_file_to_image(map->mlx, path,
			&width, &height);
	path = "./img_final/wall_left.XPM";
	map->add_img->wall_left = mlx_xpm_file_to_image(map->mlx, path,
			&width, &height);
	ft_init_img_bis(map);
	ft_init_img_ter(map);
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
