/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:01:54 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/10 14:52:31 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_addr_hor(t_map *map, double angle)
{
	map->coor.d = map->coor.d_h;
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

void	get_addr_ver(t_map *map, double angle)
{
	map->coor.d = map->coor.d_v;
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
	while (map->wall.x < (int)W_WIN)
	{
		if (angle < 0)
			angle += 2 * M_PI;
		if (angle >= 2 * M_PI)
			angle -= 2 * M_PI;
		inter_hori_wall(map, angle);
		inter_ver_wall(map, angle);
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
