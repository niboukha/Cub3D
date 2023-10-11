/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:51:37 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/10 18:49:46 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	mouve_player(t_map *map, int x, int y)
{
	if (!player_collisions(map, x, y))
	{
		map->coor.coll = 1;
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
	map->coor.coll = 0;
	if (key_code == ESC)
		exit(0);
	if (key_code == A)
		mouve_player(map,
			map->coor.px + roundf(sin(map->coor.angle) * SPEED),
			map->coor.py - roundf(cos(map->coor.angle) * SPEED));
	if (key_code == D)
		mouve_player(map,
			map->coor.px - roundf(sin(map->coor.angle) * SPEED),
			map->coor.py + roundf(cos(map->coor.angle) * SPEED));
	if (key_code == S || key_code == DOWN)
	{
		mouve_player(map,
			map->coor.px - roundf(cos(map->coor.angle) * SPEED),
			map->coor.py - roundf(sin(map->coor.angle) * SPEED));
		if (!map->coor.coll)
		{
			if (map->coor.angle > M_PI / 2 && map->coor.angle < 3 * M_PI / 2)
				mouve_player(map,
					map->coor.px - roundf(cos(map->coor.angle) * sin(map->coor.angle)),
					map->coor.py - roundf(sin(map->coor.angle) * SPEED));
			else
			{
				mouve_player(map,
					map->coor.px - roundf(cos(map->coor.angle) * cos(map->coor.angle)),
					map->coor.py - roundf(sin(map->coor.angle) * SPEED));
			}

			if (map->coor.angle > 0 && map->coor.angle < M_PI)
			{
				mouve_player(map,
					map->coor.px - roundf(cos(map->coor.angle) * SPEED),
					map->coor.py - roundf(sin(map->coor.angle) * sin(map->coor.angle)));
			}
			else
			{
				mouve_player(map,
					map->coor.px - roundf(cos(map->coor.angle) * SPEED),
					map->coor.py - roundf(sin(map->coor.angle) * cos(map->coor.angle)));
			}
		}
	}
	if (key_code == W || key_code == UP)
	{
		mouve_player(map,
			map->coor.px + roundf(cos(map->coor.angle) * SPEED),
			map->coor.py + roundf(sin(map->coor.angle) * SPEED));
		if (!map->coor.coll)
		{
			if (map->coor.angle > M_PI / 2 && map->coor.angle < 3 * M_PI / 2)
				mouve_player(map,
					map->coor.px + roundf(cos(map->coor.angle) * sin(map->coor.angle)),
					map->coor.py + roundf(sin(map->coor.angle) * SPEED));
			else
			{
				mouve_player(map,
					map->coor.px + roundf(cos(map->coor.angle) * cos(map->coor.angle)),
					map->coor.py + roundf(sin(map->coor.angle) * SPEED));
			}

			if (map->coor.angle > 0 && map->coor.angle < M_PI)
			{
				mouve_player(map,
					map->coor.px + roundf(cos(map->coor.angle) * SPEED),
					map->coor.py + roundf(sin(map->coor.angle) * cos(map->coor.angle)));
			}
			else
			{
				mouve_player(map,
					map->coor.px + roundf(cos(map->coor.angle) * SPEED),
					map->coor.py + roundf(sin(map->coor.angle) * sin(map->coor.angle)));
			}
		}
	}
}

int	key(int key_code, t_map *map)
{
	mouvement_player_key(map, key_code);
	rotation_player_key(map, key_code);
	animation_gun(map, key_code);
	fill_map3(map);
	put_pixel(map);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->sprit.img_d[0].img,
		W_WIN / 2, H_WIN - map->sprit.img_d[0].h);
	return (0);
}

int	mouse_key(int key_code, int x, int y, t_map *map)
{
	if (key_code == 5)
		mouve_player(map,
			map->coor.px - roundf(cos(map->coor.angle) * SPEED),
			map->coor.py - roundf(sin(map->coor.angle) * SPEED));
	if (key_code == 4)
		mouve_player(map,
			map->coor.px + roundf(cos(map->coor.angle) * SPEED),
			map->coor.py + roundf(sin(map->coor.angle) * SPEED));
	if (key_code == 2)
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
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->sprit.img_d[0].img,
		W_WIN / 2, H_WIN - map->sprit.img_d[0].h);
	return (0);
}
