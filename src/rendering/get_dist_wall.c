/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:01:54 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/15 11:04:12 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_hor_door(t_map *map)
{
	if (check_if_wall(map, map->wall.h_x, map->wall.h_y) == 1
		|| !check_doors(map, map->wall.h_x, map->wall.h_y, 2))
		map->coor.flag_a = 0;
	if (map->coor.d <= 100)
	{	
		if (check_doors(map, map->wall.h_x, map->wall.h_y, 2) == 1)
		{
			if (map->map[(int)map->wall.h_y / 64 - 1]
				[(int)map->wall.h_x / 64] == 'R')
				map->map[(int)map->wall.h_y / 64 - 1]
				[(int)map->wall.h_x / 64] = '2';
			else if (map->map[(int)map->wall.h_y / 64]
				[(int)map->wall.h_x / 64] == 'R')
				map->map[(int)map->wall.h_y / 64]
				[(int)map->wall.h_x / 64] = '2';
			map->coor.flag_a = 0;
		}
	}
}

void	get_addr_hor(t_map *map, double angle)
{
	map->coor.d = map->coor.d_h;
	if (map->coor.flag_a == 1)
	{
		get_hor_door(map);
		map->dr.i = ((int)map->wall.h_x) % map->door.w_img;
		map->door.addr = mlx_get_data_addr(map->door.img,
				&map->door.bits_per_pixel,
				&map->door.line_length, &map->door.endian);
	}
	if (angle > 0 && angle < M_PI)
	{
		map->textures.h_img = map->textures.img_s.h;
		map->txt.x = ((int)map->wall.h_x) % map->textures.img_s.w;
		map->textures.addr = mlx_get_data_addr(map->textures.img_s.img,
				&map->textures.bits_per_pixel,
				&map->textures.line_length, &map->textures.endian);
	}
	else
	{
		map->textures.h_img = map->textures.img_n.h;
		map->txt.x = ((int)map->wall.h_x) % map->textures.img_n.w;
		map->textures.addr = mlx_get_data_addr(map->textures.img_n.img,
				&map->textures.bits_per_pixel,
				&map->textures.line_length, &map->textures.endian);
	}
}

void	get_ver_door(t_map *map)
{
	if (check_if_wall(map, map->wall.v_x, map->wall.v_y) == 1
		|| !check_doors(map, map->wall.v_x, map->wall.v_y, 1))
		map->coor.flag_a = 0;
	if (map->coor.d <= 100)
	{
		if (check_doors(map, map->wall.v_x, map->wall.v_y, 1) == 2)
		{
			if (map->map[(int)map->wall.v_y / 64]
				[(int)map->wall.v_x / 64 - 1] == 'R')
				map->map[(int)map->wall.v_y / 64]
				[(int)map->wall.v_x / 64 - 1] = '2';
			else if (map->map[(int)map->wall.v_y / 64]
				[(int)map->wall.v_x / 64] == 'R')
				map->map[(int)map->wall.v_y / 64]
				[(int)map->wall.v_x / 64] = '2';
			map->coor.flag_a = 0;
		}
	}
	map->dr.i = ((int)map->wall.v_y) % map->door.w_img;
}

void	get_addr_ver(t_map *map, double angle)
{
	map->coor.d = map->coor.d_v;
	if (map->coor.flag_a == 1)
	{
		get_ver_door(map);
		map->door.addr = mlx_get_data_addr(map->door.img,
				&map->door.bits_per_pixel,
				&map->door.line_length, &map->door.endian);
	}
	if ((angle > 0 && angle < (M_PI / 2)) || (angle > (3 * M_PI / 2)
			&& angle < (2 * M_PI)))
	{
		map->textures.h_img = map->textures.img_e.h;
		map->txt.x = ((int)map->wall.v_y) % map->textures.img_e.w;
		map->textures.addr = mlx_get_data_addr(map->textures.img_e.img,
				&map->textures.bits_per_pixel,
				&map->textures.line_length, &map->textures.endian);
	}
	else
	{
		map->textures.h_img = map->textures.img_w.h;
		map->txt.x = ((int)map->wall.v_y) % map->textures.img_w.w;
		map->textures.addr = mlx_get_data_addr(map->textures.img_w.img,
				&map->textures.bits_per_pixel,
				&map->textures.line_length, &map->textures.endian);
	}
}

void	get_dist_wall(t_map *map)
{
	double	angle;

	angle = map->coor.angle - (30 * M_PI / 180);
	map->coor.flag_a = 0;
	while (map->wall.x < (int)W_WIN)
	{
		if (angle < 0)
			angle += 2 * M_PI;
		if (angle >= 2 * M_PI)
			angle -= 2 * M_PI;
		map->coor.flag_a = 0;
		inter_ver_wall(map, angle);
		inter_hori_wall(map, angle);
		if (map->coor.d_h < map->coor.d_v)
			get_addr_hor(map, angle);
		else
			get_addr_ver(map, angle);
		draw_walls(map, angle);
		map->wall.x++;
		angle += ((60.0 * M_PI) / (W_WIN * 180));
	}
	map->wall.x = 0;
	map->wall.y = 0;
}
