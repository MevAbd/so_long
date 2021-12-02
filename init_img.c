#include "soo_loong.h"

void	ft_init_img(t_map *map)
{
	char	*path;
	int		width;
	int		height;
	t_img	*img;

	width = 66;
	height = 66;
	img = malloc(sizeof(t_img));
	map->add_img = img;
	path = "img_66/up.xpm";
	img->player_up = mlx_xpm_file_to_image(map->mlx, path, &width, &height);
	path = "img_66/left.xpm";
	img->player_left = mlx_xpm_file_to_image(map->mlx, path, &width, &height);
	path = "img_66/right.xpm";
	img->player_right = mlx_xpm_file_to_image(map->mlx, path, &width, &height);
	path = "img_66/down.xpm";
	img->player_down = mlx_xpm_file_to_image(map->mlx, path, &width, &height);
}

void	ft_put_obj(t_map *map, char *path)
{
	int		width;
	int		height;
	void	*obj;

	width = 66;
	height = 66;
	obj = mlx_xpm_file_to_image(map->mlx, path, &width, &height);
	mlx_put_image_to_window(map->mlx, map->mlx_win, obj, map->lig * IMG_W, map->col * IMG_H);
}

void	ft_create_map(t_map map)
{
	map->lig = 0;
	map->col = 0;
	while (map->lig < map.nlig)
	{
		if (map->tab[map->lig][map->col] == 1)
			ft_put_obj(map, "./map_66/wall.xpm");
		else if (map->tab[map->lig][map->col] == 2)
			ft_put_obj(map, "./map_66/collecte.xpm");
		else if (map->tab[map->lig][map->col] == 3)
			ft_put_obj(map, "./map_66/exit.xpm");
		//else if (map->tab[map->lig][map->col] == 4)
	//		ft_put_play(map);
		if (map->col < map.ncol)
			map->col++;
		else
		{
			map->lig++;
			map->col = 0;
		}
	}
}
