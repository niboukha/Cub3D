/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:19:36 by niboukha          #+#    #+#             */
/*   Updated: 2023/09/18 17:48:49 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>

# define A 97
# define S 115
# define W 119
# define D 100
# define ESC 53
# define LEFT 65361
# define RIGHT 65363
# define DOWN 65364
# define UP 65362

typedef struct t_coor
{
	int	x;
	int	y;
	int	py;
	int	px;
	int	new_i;
	int	new_j;
	int	put;
	int	d;
	double	angle;
}		t_coor;


typedef struct t_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct t_wall
{
	int	x;
	int	y;
}		t_wall;


typedef struct t_map
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_win1;
	char	**map;
	t_coor	coor;
	t_wall	wall;
	t_image	img;
	t_image	image;
}			t_map;

void	put_pixel(t_map *map);
void	fill_cub_player(t_map *map, int x, int y, int color);
void	fill_cub_pixels(t_map *map, int x, int y, int color);
void	my_mlx_put_pixel(t_image *img, int x, int y, int color);
int		key(int key_code, t_map *map);
void	put_a_ray(t_map *map, int x, int y, int color);
void	move_player(t_map *map, int x, int y);
int		find_wall(t_map *map, int x, int y);
int		check_wall(t_map *map, int x, int y);
void	draw_walls(t_map *map, int color);
void	fill_map3(t_map *map);
#endif
