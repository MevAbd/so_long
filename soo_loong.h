/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soo_loong.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 07:37:14 by malbrand          #+#    #+#             */
/*   Updated: 2021/12/04 05:38:46 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOO_LOONG_H
# define SOO_LOONG_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
//# include "./mlx/mlx.h"

# define BUFFER_SIZE 6
# define IMG_W 32
# define IMG_H 32

typedef struct s_img
{
	void	*ground;
	void	*player_up;
	void	*player_left;
	void	*player_right;
	void	*player_down;
	void	*wall_up;
	void	*wall_down;
	void	*wall_left;
	void	*wall_right;
	void	*corner_h_l;
	void	*corner_h_r;
	void	*corner_d_l;
	void	*corner_d_r;
	void	*coll;
	void	*wall_inside;
	void	*exit;
}				t_img;

typedef struct s_map
{
	int		nlig;
	int		ncol;
	int		map_error;
	int		col;
	int		wall;
	int		coll;
	int		exit;
	int		player;
	int		**tab;
	void	*mlx;	
	void	*mlx_win;
	t_img	*add_img;
}					t_map;

int		ft_check(const char *str);
int		ft_read(int *ret, int fd, char **buff);
int		ft_strlen_bis(char *s);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, const char *s2);
char	*ft_fill_line(char **str, char *line);
char	*get_next_line(int fd);
void	ft_free_tab(t_map map);
void	ft_print_tab(t_map map);
void	ft_init_img(t_map *map);
void	ft_create_map(t_map *map);
void	ft_put_img(t_map map);
void	ft_write_error(t_map map);
t_map	ft_fill_tab(t_map map, int fd);
t_map	ft_error(int fd, char *av);
t_map	ft_check_wall(t_map map);
size_t	ft_strlen(const char *s);

#endif
