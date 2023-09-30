/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:01:54 by niboukha          #+#    #+#             */
/*   Updated: 2023/09/25 20:50:16 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_if_wall(t_map *map, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[y / 64][x / 64] == '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	player_collisions(t_map *map, int x, int y)
{
	double	angle;

	angle = 0;
	while (angle <= 2 * M_PI)
	{
		if (check_if_wall(map, x + roundf(cos(angle) * 15),
			y + roundf(sin(angle) * 15)) == 1)
			return (1);
		// my_mlx_put_pixel(&map->img, x + roundf(cos(angle) * 15),
		// 	y + roundf(sin(angle) * 15), 0xFF0000);
		angle += 0.1;
	}
	return (0);
}

void	get_dist_wall(t_map *map, int color)
{
	double	angle;

	angle = map->coor.angle - (30 * M_PI / 180);
	while (map->wall.x < (int)W_WIN)
	{
		if (angle < 0)
			angle += 2 * M_PI;
		if (angle >= 2 * M_PI)
			angle -= 2 * M_PI;
		inter_hori_wall(map, angle);
		inter_ver_wall(map, angle);
		if (map->coor.d_h < map->coor.d_v)
		{
			map->coor.d = map->coor.d_h;
			color = 0xff00f0;
		}
		else
		{
			map->coor.d = map->coor.d_v;
			color = 0xff0000;
		}
		draw_rays(map, angle);
		draw_walls(map, color, angle);
		map->wall.x++;
		angle += ((60.0 * M_PI) / (W_WIN * 180));
	}
	map->wall.x = 0;
	map->wall.y = 0;
}