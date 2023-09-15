/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:51:37 by niboukha          #+#    #+#             */
/*   Updated: 2023/09/14 20:20:13 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_map *map, int x, int y)
{
	if (map->map[y][x] == '0' || map->map[y][x] == 'N')
	{
		fill_cub_pixels(map, map->coor.j, map->coor.i, 0x0000FF);
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img.img, 0, 0);
		fill_cub_player(map, x, y, 0x00FF00);
		put_a_ray(map, x, y, 0x00FF00);
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img.img, 0, 0);
		map->coor.i = y;
		map->coor.j = x;
	}
}

void	rotate_player(t_map *map)
{
	fill_cub_player(map, map->coor.j, map->coor.i, 0x00FF00);
	put_a_ray(map, map->coor.j, map->coor.i, 0x00FF00);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img.img, 0, 0);
}

int	key(int key_code, t_map *map)
{
	map->coor.put = 1;
	put_pixel(map);
	if (key_code == A)
		move_player(map, map->coor.j - 1, map->coor.i);
	if (key_code == D)
		move_player(map, map->coor.j + 1, map->coor.i);
	if (key_code == S)
		move_player(map, map->coor.j, map->coor.i + 1);
	if (key_code == W)
		move_player(map, map->coor.j, map->coor.i - 1);
	if (key_code == RIGHT)
	{
		map->coor.angle += 0.1;
		if (map->coor.angle >= 2 * M_PI)
			map->coor.angle -= 2 * M_PI;
		rotate_player(map);
	}
	if (key_code == LEFT)
	{
		map->coor.angle -= 0.1;
		if (map->coor.angle >= 2 * M_PI)
			map->coor.angle -= 2 * M_PI;
		rotate_player(map);
	}
	map->coor.put = 0;
	return (0);
}
