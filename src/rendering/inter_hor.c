/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_hor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:59:16 by niboukha          #+#    #+#             */
/*   Updated: 2023/09/25 20:50:20 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	inter_hori_wall(t_map *map, double angle)
{
	if (angle >= 0 && angle <= M_PI)
	{
		map->wall.gh_y = 64;
		map->wall.h_y = (map->coor.py / 64) * 64 + 64;
	}
	else
	{
		map->wall.gh_y = -64;
		map->wall.h_y = (map->coor.py / 64) * 64 - 1;
	}
	map->wall.gh_x = map->wall.gh_y / tan(angle);
	map->wall.h_x = map->coor.px + (map->wall.h_y - map->coor.py) / tan(angle);
	coor_of_hor_wall(map, map->wall.h_x, map->wall.h_y);
}

void	coor_of_hor_wall(t_map *map, double x, double y)
{
	map->coor.d_h = sqrt(pow(map->coor.x * 64, 2) + pow(map->coor.y * 64, 2));
	while ((int)x < map->coor.x * 64 && (int)y < map->coor.y * 64
		&& (int)x >= 0 && (int)y >= 0
		&& !check_if_wall(map, x, y))
	{
		x += map->wall.gh_x;
		y += map->wall.gh_y;
	}
	if ((int)x <= map->coor.x * 64 && (int)y <= map->coor.y * 64
		&& (int)x >= 0 && (int)y >= 0
		&& check_if_wall(map, x, y))
		map->coor.d_h = distance_wall(map, x, y);
}
