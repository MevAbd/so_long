/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:03:08 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/06 20:05:17 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../soo_loong.h"

void	ft_exit_bis(t_map *map)
{
	if (map->add_img->ground)
		mlx_destroy_image(map->mlx, map->add_img->ground);
	if (map->add_img->player_up)
		mlx_destroy_image(map->mlx, map->add_img->player_up);
	if (map->add_img->player_down)
		mlx_destroy_image(map->mlx, map->add_img->player_down);
	if (map->add_img->player_left)
		mlx_destroy_image(map->mlx, map->add_img->player_left);
	if (map->add_img->player_right)
		mlx_destroy_image(map->mlx, map->add_img->player_right);
	if (map->add_img->wall_up)
		mlx_destroy_image(map->mlx, map->add_img->wall_up);
	if (map->add_img->wall_down)
		mlx_destroy_image(map->mlx, map->add_img->wall_down);
	if (map->add_img->wall_left)
		mlx_destroy_image(map->mlx, map->add_img->wall_left);
	if (map->add_img->wall_right)
		mlx_destroy_image(map->mlx, map->add_img->wall_right);
	if (map->add_img->corner_h_l)
		mlx_destroy_image(map->mlx, map->add_img->corner_h_l);
	if (map->add_img->corner_h_r)
		mlx_destroy_image(map->mlx, map->add_img->corner_h_r);
	if (map->add_img->corner_d_l)
		mlx_destroy_image(map->mlx, map->add_img->corner_d_l);
}

int	ft_exit(t_map *map)
{
	ft_free_tab(map);
	ft_exit_bis(map);
	if (map->add_img->corner_d_r)
		mlx_destroy_image(map->mlx, map->add_img->corner_d_r);
	if (map->add_img->coll)
		mlx_destroy_image(map->mlx, map->add_img->coll);
	if (map->add_img->wall_inside)
		mlx_destroy_image(map->mlx, map->add_img->wall_inside);
	if (map->add_img->exit)
		mlx_destroy_image(map->mlx, map->add_img->exit);
	if (map->add_img->enemys)
		mlx_destroy_image(map->mlx, map->add_img->enemys);
	if (map->mlx)
	{
		mlx_destroy_window(map->mlx, map->mlx_win);
		mlx_destroy_display(map->mlx);
	}
	if (map->add_img)
		free(map->add_img);
	if (map->mlx)
		free(map->mlx);
	exit(0);
	return (0);
}
