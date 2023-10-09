/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:01:54 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/08 18:52:16 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_addr_hor(t_map *map, double angle)
{
	map->coor.d = map->coor.d_h;
	if (map->coor.flag_a == 1)
	{
		map->sprt.t_x = ((int)map->wall.h_x) % map->sprit.w_img;
		map->sprit.addr = mlx_get_data_addr(map->sprit.img_d[map->sprt.timer / 10],
			&map->sprit.bits_per_pixel,
			&map->sprit.line_length, &map->sprit.endian);
	}
	else
	{
		map->txt.x = ((int)map->wall.h_x) % map->textures.w_img;
		if (angle > 0 && angle < M_PI)
		{
			map->textures.addr = mlx_get_data_addr(map->textures.img_s,
					&map->textures.bits_per_pixel,
					&map->textures.line_length, &map->textures.endian);
		}
		else
		{
			map->textures.addr = mlx_get_data_addr(map->textures.img_n,
					&map->textures.bits_per_pixel,
					&map->textures.line_length, &map->textures.endian);
		}
	}
}

void	get_addr_ver(t_map *map, double angle)
{
	map->coor.d = map->coor.d_v;
	if (map->coor.flag_a == 1)
	{
		map->sprt.t_x = ((int)map->wall.v_y) % map->sprit.w_img;
		map->sprit.addr = mlx_get_data_addr(map->sprit.img_d[map->sprt.timer / 10],
			&map->sprit.bits_per_pixel, &map->sprit.line_length, &map->sprit.endian);
	}
	else
	{
		map->txt.x = ((int)map->wall.v_y) % map->textures.w_img;
		if ((angle > 0 && angle < (M_PI / 2)) || (angle > (3 * M_PI / 2)
				&& angle < (2 * M_PI)))
		{
			map->textures.addr = mlx_get_data_addr(map->textures.img_e,
					&map->textures.bits_per_pixel,
					&map->textures.line_length, &map->textures.endian);
		}
		else
		{
			map->textures.addr = mlx_get_data_addr(map->textures.img_w,
					&map->textures.bits_per_pixel,
					&map->textures.line_length, &map->textures.endian);
		}
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
		map->coor.flag_a = 0;
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
