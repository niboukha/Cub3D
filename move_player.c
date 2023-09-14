/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:51:37 by niboukha          #+#    #+#             */
/*   Updated: 2023/09/14 16:57:51 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(t_map *map, int x, int y)
{
	if (map->map[y][x] == '0' || map->map[y][x] == 'N')
	{
		fill_cub_pixels(map, map->coor.i, map->coor.j, 0x0000FF);
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img.img, 0, 0);
		fill_cub_player(map, x, y, 0x00FF00);
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img.img, 0, 0);
		map->coor.i = x;
		map->coor.j = y;
	}
}

void	rotate_player(t_map *map)
{
	fill_cub_pixels(map, map->coor.i, map->coor.j, 0x0000FF);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img.img, 0, 0);
	fill_cub_player(map, map->coor.i, map->coor.j, 0x00FF00);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img.img, 0, 0);
}

int	key(int key_code, t_map *map)
{
	map->coor.put = 1;
	put_pixel(map);
	map->coor.new_i = map->coor.i;
	map->coor.new_j = map->coor.j;
	if (key_code == A)
		move_player(map, map->coor.new_i - 1, map->coor.new_j);
	if (key_code == D)
		move_player(map, map->coor.new_i + 1, map->coor.new_j);
	if (key_code == S)
		move_player(map, map->coor.new_i, map->coor.new_j + 1);
	if (key_code == W)
		move_player(map, map->coor.new_i, map->coor.new_j - 1);
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
