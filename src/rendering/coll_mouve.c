/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coll_mouve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:57:03 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/13 20:57:20 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	mvmt_coll_down(t_map *map)
{
	if (!map->coor.coll)
	{
		if (map->coor.angle > M_PI / 2 && map->coor.angle < 3 * M_PI / 2)
			mouve_player(map, map->coor.px - roundf(cos(map->coor.angle)
					* sin(map->coor.angle)), map->coor.py
				- roundf(sin(map->coor.angle) * SPEED));
		else
		{
			mouve_player(map, map->coor.px - roundf(cos(map->coor.angle)
					* cos(map->coor.angle)),
				map->coor.py - roundf(sin(map->coor.angle) * SPEED));
		}
		if (map->coor.angle > 0 && map->coor.angle < M_PI)
		{
			mouve_player(map, map->coor.px - roundf(cos(map->coor.angle)
					* SPEED), map->coor.py - roundf(sin(map->coor.angle)
					* sin(map->coor.angle)));
		}
		else
		{
			mouve_player(map, map->coor.px - roundf(cos(map->coor.angle)
					* SPEED), map->coor.py - roundf(sin(map->coor.angle)
					* cos(map->coor.angle)));
		}
	}
}

void	mvmt_coll_up(t_map *map)
{
	if (!map->coor.coll)
	{
		if (map->coor.angle > M_PI / 2 && map->coor.angle < 3 * M_PI / 2)
			mouve_player(map, map->coor.px + roundf(cos(map->coor.angle)
					* sin(map->coor.angle)), map->coor.py
				+ roundf(sin(map->coor.angle) * SPEED));
		else
		{
			mouve_player(map, map->coor.px + roundf(cos(map->coor.angle)
					* cos(map->coor.angle)), map->coor.py
				+ roundf(sin(map->coor.angle) * SPEED));
		}
		if (map->coor.angle > 0 && map->coor.angle < M_PI)
		{
			mouve_player(map, map->coor.px + roundf(cos(map->coor.angle)
					* SPEED), map->coor.py + roundf(sin(map->coor.angle)
					* sin(map->coor.angle)));
		}
		else
		{
			mouve_player(map, map->coor.px + roundf(cos(map->coor.angle)
					* SPEED), map->coor.py + roundf(sin(map->coor.angle)
					* cos(map->coor.angle)));
		}
	}
}
