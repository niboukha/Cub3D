/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:50:24 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/15 11:02:32 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	mouse_(t_map *map, int key_code)
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
	if (key_code == 3)
	{
		if (map->coor.d > 100)
			map_(map);
	}
}

void	map_(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->coor.y)
	{
		j = 0;
		while (j < (int)ft_strlen(map->map[i]))
		{
			if (map->map[i][j] == '2')
				map->map[i][j] = 'R';
			j++;
		}
		i++;
	}
}

int	mouse_key(int key_code, int x, int y, t_map *map)
{
	mouse_(map, key_code);
	(void)x;
	(void)y;
	fill_map3(map);
	put_pixel(map);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->sprit.img_d[0].img,
		W_WIN / 2, H_WIN - map->sprit.img_d[0].h);
	return (0);
}
