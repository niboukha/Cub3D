/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:59:39 by niboukha          #+#    #+#             */
/*   Updated: 2023/09/22 18:32:23 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rays(t_map *map, double angle)
{
	int	i;

	i = 0;
	while (map->coor.px < map->coor.x * 64 && map->coor.py < map->coor.y * 64
	&& !check_if_wall(map, map->coor.px + roundf(cos(angle) * i),
		map->coor.py + roundf(sin(angle) * i)))
	{
		my_mlx_put_pixel(&map->img,
			map->coor.px + roundf(cos(angle) * i),
			map->coor.py + roundf(sin(angle) * i), 0x00ff00);
		i++;
	}
}

void	inter_hori_wall(t_map *map, int x, int y, double angle)
{
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle >= 0 && angle <= M_PI)
		inter_hor_down(map, x, y, angle);
	else if (angle > M_PI && angle <= 2 * M_PI)
		inter_hor_up(map, x, y, angle);
	coor_of_hor_wall(map, map->wall.h_x, map->wall.h_y, angle);
}

void	inter_ver_wall(t_map *map, int x, int y, double angle)
{
	if (angle < 0)
		angle += 2 * M_PI;
	if (angle <= (M_PI / 2) || angle >= (3 * M_PI / 2))
		inter_ver_right(map, x, y, angle);
	else
		inter_ver_left(map, x, y, angle);
	coor_of_ver_wall(map, map->wall.v_x, map->wall.v_y, angle);
}
