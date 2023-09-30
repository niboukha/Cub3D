/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_ver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:20:17 by niboukha          #+#    #+#             */
/*   Updated: 2023/09/25 20:50:23 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	inter_ver_wall(t_map *map, double angle)
{
	if ((angle >= 0 && angle <= (M_PI / 2)) || (angle >= (3 * M_PI / 2) && angle <= (2 * M_PI)))
	{
		map->wall.gv_x = 64;
		map->wall.v_x = (map->coor.px / 64) * 64 + 64;
	}
	else
	{
		map->wall.gv_x = -64;
		map->wall.v_x = (map->coor.px / 64) * 64 - 1;
	}
	map->wall.gv_y = map->wall.gv_x * tan(angle);
	map->wall.v_y = map->coor.py + (map->wall.v_x - map->coor.px) * tan(angle);
	coor_of_ver_wall(map, map->wall.v_x, map->wall.v_y);
}

void	coor_of_ver_wall(t_map *map,double x,double y)
{
	map->coor.d_v = sqrt(pow(map->coor.x * 64, 2) + pow(map->coor.y * 64, 2));
	while ((int)x < map->coor.x * 64 && (int)y < map->coor.y * 64
		&& (int)x >= 0 && (int)y >= 0
		&& !check_if_wall(map, x, y))
	{
		x += map->wall.gv_x;
		y += map->wall.gv_y;
	}
	if ((int)x < map->coor.x * 64 && (int)y < map->coor.y * 64
		&& (int)x >= 0 && (int)y >= 0
		&& check_if_wall(map, x, y))
		map->coor.d_v = distance_wall(map, x, y);
}