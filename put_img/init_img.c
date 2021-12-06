/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 02:28:10 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/06 19:55:32 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../soo_loong.h"

void	ft_init_img_bis(t_map *map, int height, int width)
{
	char	*path;

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
	map->add_img->enemys = mlx_xpm_file_to_image(map->mlx, path,
			&width, &height);
}

void	ft_init_image(t_map *map, int width, int height)
{
	char	*path;

	path = "./img_final/wall_down.xpm";
	map->add_img->wall_down = mlx_xpm_file_to_image(map->mlx, path,
			&width, &height);
}

void	ft_init_img_ter(t_map *map, int width, int height)
{
	char	*path;

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
	path = "./img_final/wall_left.XPM";
	map->add_img->wall_left = mlx_xpm_file_to_image(map->mlx, path,
			&width, &height);
	ft_init_image(map, width, height);
}

int	ft_init_img(t_map *map)
{
	char	*path;
	int		width;
	int		height;
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
	{
		ft_exit(map);
		return (0);
	}
	map->add_img = img;
	width = 0;
	height = 0;
	path = "./img_final/sol.xpm";
	map->add_img->ground = mlx_xpm_file_to_image(map->mlx, path,
			&width, &height);
	path = "./img_final/wall_up.xpm";
	map->add_img->wall_up = mlx_xpm_file_to_image(map->mlx, path,
			&width, &height);
	ft_init_img_bis(map, height, width);
	ft_init_img_ter(map, height, width);
	return (1);
}
