/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:51:37 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/07 12:36:34 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	mouve_player(t_map *map, int x, int y)
{
	if (!player_collisions(map, x, y))
	{
		map->coor.py = y;
		map->coor.px = x;
	}
}

void	rotation_player_key(t_map *map, int key_code)
{
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
}

void	mouvement_player_key(t_map *map, int key_code)
{
	if (key_code == ESC)
		exit(0);
	if (key_code == A)
		mouve_player(map,
			map->coor.px + roundf(sin(map->coor.angle) * 7),
			map->coor.py - roundf(cos(map->coor.angle) * 7));
	if (key_code == D)
		mouve_player(map,
			map->coor.px - roundf(sin(map->coor.angle) * 7),
			map->coor.py + roundf(cos(map->coor.angle) * 7));
	if (key_code == S || key_code == DOWN)
		mouve_player(map,
			map->coor.px - roundf(cos(map->coor.angle) * 7),
			map->coor.py - roundf(sin(map->coor.angle) * 7));
	if (key_code == W || key_code == UP)
		mouve_player(map,
			map->coor.px + roundf(cos(map->coor.angle) * 7),
			map->coor.py + roundf(sin(map->coor.angle) * 7));
}

int	key(int key_code, t_map *map)
{
	mouvement_player_key(map, key_code);
	rotation_player_key(map, key_code);
	fill_map3(map);
	put_pixel(map);
	return (0);
}

int	mouse_key(int key_code, int x, int y, t_map *map)
{
	if (key_code == 5)
		mouve_player(map,
			map->coor.px - roundf(cos(map->coor.angle) * 7),
			map->coor.py - roundf(sin(map->coor.angle) * 7));
	if (key_code == 4)
		mouve_player(map,
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
