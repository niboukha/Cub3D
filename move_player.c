/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:51:37 by niboukha          #+#    #+#             */
/*   Updated: 2023/09/13 18:20:12 by niboukha         ###   ########.fr       */
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

int	key(int key_code, t_map *map)
{
	map->coor.new_i = map->coor.i;
	map->coor.new_j = map->coor.j;
	if (key_code == A || key_code == 65361)
		move_player(map, map->coor.new_i - 1, map->coor.new_j);
	if (key_code == D || key_code == 65363)
		move_player(map, map->coor.new_i + 1, map->coor.new_j);
	if (key_code == S || key_code == 65364)
		move_player(map, map->coor.new_i, map->coor.new_j + 1);
	if (key_code == W || key_code == 65362)
		move_player(map, map->coor.new_i, map->coor.new_j - 1);
	return (0);
}
