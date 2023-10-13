/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_hor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:59:16 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/13 11:31:32 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	inter_hori_wall(t_map *map, double angle)
{
	map->coor.up = 0;
	map->coor.down = 0;
	if (angle > 0 && angle < M_PI)
	{
		map->coor.down = 1;
		map->wall.gh_y = 64;
		map->wall.h_y = (map->coor.py / 64) * 64 + 64;
	}
	else
	{
		map->coor.up = 1;
		map->wall.gh_y = -64;
		map->wall.h_y = (map->coor.py / 64) * 64;
	}
	map->wall.gh_x = map->wall.gh_y / tan(angle);
	map->wall.h_x = map->coor.px + (map->wall.h_y - map->coor.py) / tan(angle);
	coor_of_hor_wall(map, map->wall.h_x, map->wall.h_y);
}

void	coor_of_hor_wall(t_map *map, double x, double y)
{
	while ((int)x < map->coor.x * 64 && (int)y < map->coor.y * 64
		&& x >= 0.0 && y >= 0.0
		&& !check_if_wall(map, x, y))
	{
		x += map->wall.gh_x;
		y += map->wall.gh_y;
	}
	if (check_if_wall(map, x, y) == 2)
		map->coor.flag_a = 1;
	map->wall.h_x = x;
	map->wall.h_y = y;
	map->coor.up = 0;
	map->coor.down = 0;
	map->coor.d_h = distance_wall(map, x, y);
}
