/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_ver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:20:17 by niboukha          #+#    #+#             */
/*   Updated: 2023/09/23 17:54:03 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	coor_of_ver_wall(t_map *map, int x, int y, double angle)
{
	while (x < map->coor.x * 64 && y < map->coor.y * 64
		&& x > 0 && y > 0
		&& !check_if_wall(map, x, y))
	{
		// fill_cub_player(map, x, y, 0xff0000);
		x += map->wall.gv_x;
		y += map->wall.gv_y;
	}
	map->coor.d_v = distance_wall(map, x, y);
	if (x < map->coor.x * 64 && y < map->coor.y * 64
		&& x > 0 && y > 0)
		fill_cub_player(map, x, y, 0xff0000);
	(void)angle;
	//draw_rays(map, angle);
}

void	inter_ver_left(t_map *map, int x, int y, double angle)
{
	map->wall.gv_y = 64 * tan(2 * M_PI - angle);
	map->wall.gv_x = -64;
	map->wall.v_x = roundf(x / 64) * 64 - 1;
	map->wall.v_y = y + (x - map->wall.v_x) * tan(2 * M_PI - angle);
}

void	inter_ver_right(t_map *map, int x, int y, double angle)
{
	map->wall.gv_y = 64 * tan(angle);
	map->wall.gv_x = 64;
	map->wall.v_x = roundf(x / 64) * 64 + 64;
	map->wall.v_y = y + (map->wall.v_x - x) * tan(angle);
}
