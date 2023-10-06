/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:51:37 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/05 17:16:00 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_player(t_map *map, int x, int y)
{
	if (!player_collisions(map, x, y))
	{
		map->coor.py = y;
		map->coor.px = x;
	}
}

int	key(int key_code, t_map *map)
{
	if (key_code == ESC)
		exit(0);
	if (key_code == A)
		move_player(map,
		map->coor.px + roundf(sin(map->coor.angle) * 7),
		map->coor.py - roundf(cos(map->coor.angle) * 7));
	if (key_code == D)
		move_player(map,
			map->coor.px - roundf(sin(map->coor.angle) * 7),
			map->coor.py + roundf(cos(map->coor.angle) * 7));
	if (key_code == S || key_code == DOWN)
		move_player(map,
			map->coor.px - roundf(cos(map->coor.angle) * 7),
			map->coor.py - roundf(sin(map->coor.angle) * 7));
	if (key_code == W || key_code == UP)
		move_player(map,
			map->coor.px + roundf(cos(map->coor.angle) * 7),
			map->coor.py + roundf(sin(map->coor.angle) * 7));
	if (key_code == RIGHT)
	{
		map->coor.angle += 0.05;
		if (map->coor.angle >= 2 * M_PI)
			map->coor.angle -= 2 * M_PI;
	}
	if (key_code == LEFT)
	{
		map->coor.angle -= 0.05;
		if (map->coor.angle < 0)
			map->coor.angle += 2 * M_PI;
	}
	fill_map3(map);
	put_pixel(map);
	return (0);
}

int	mouse_key(int key_code, int x, int y, t_map *map)
{
	if (key_code == 5)
		move_player(map,
			map->coor.px - roundf(cos(map->coor.angle) * 7),
			map->coor.py - roundf(sin(map->coor.angle) * 7));
	if (key_code == 4)
		move_player(map,
			map->coor.px + roundf(cos(map->coor.angle) * 7),
			map->coor.py + roundf(sin(map->coor.angle) * 7));
	if (key_code == 3)
	{
		map->coor.angle += 0.05;
		if (map->coor.angle >= 2 * M_PI)
			map->coor.angle -= 2 * M_PI;
	}
	if (key_code == 1)
	{
		map->coor.angle -= 0.05;
		if (map->coor.angle < 0)
			map->coor.angle += 2 * M_PI;
	}
	(void)x;
	(void)y;
	fill_map3(map);
	put_pixel(map);
	return (0);
}
