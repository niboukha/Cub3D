/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_hor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:59:16 by niboukha          #+#    #+#             */
/*   Updated: 2023/09/23 17:53:28 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	inter_hor_up(t_map *map, int x, int y, double angle)
{
	if (angle > (3 * M_PI / 2) && angle < 2 * M_PI)
		map->wall.gh_x = 64 / tan(2 * M_PI - angle);
	else if (angle > M_PI && angle < (3 * M_PI / 2))
		map->wall.gh_x = 64 / tan(M_PI - angle);
	map->wall.gh_y = -64;
	map->wall.h_y = roundf(y / 64) * 64 - 1;
	if (angle > (3 * M_PI / 2) && angle < 2 * M_PI)
		map->wall.h_x = x + roundf((y - map->wall.h_y) / tan(2 * M_PI - angle));
	else if (angle > M_PI && angle < (3 * M_PI / 2))
		map->wall.h_x = x + roundf((y - map->wall.h_y) / tan(M_PI - angle));
}

void	inter_hor_down(t_map *map, int x, int y, double angle)
{
	map->wall.gh_y = 64;
	map->wall.gh_x = 64 / tan(angle);
	map->wall.h_y = roundf(y / 64) * 64 + 64;
	map->wall.h_x = x + roundf((map->wall.h_y - y) / tan(angle));
}

double	distance_wall(t_map *map, int x, int y)
{
	return (sqrt(pow(map->coor.px - x, 2) + pow(map->coor.py - y, 2)));
}

void	coor_of_hor_wall(t_map *map, int x, int y, double angle)
{
	while (x < map->coor.x * 64 && y < map->coor.y * 64
		&& x > 0 && y > 0
		&& !check_if_wall(map, x, y))
	{
		//fill_cub_player(map, x, y, 0xff0000);
		x += map->wall.gh_x;
		y += map->wall.gh_y;
	}
	map->coor.d_h = distance_wall(map, x, y);
	if (x < map->coor.x * 64 && y < map->coor.y * 64
		&& x > 0 && y > 0)
		fill_cub_player(map, x, y, 0x00ff00);

	(void)angle;
	//draw_rays(map, angle);
}
