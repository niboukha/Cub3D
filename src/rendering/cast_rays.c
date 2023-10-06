/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 09:52:32 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/05 18:46:53 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	fill_map3(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < W_WIN)
	{
		j = 0;
		while (j < H_WIN)
		{
			my_mlx_put_pixel(&map->image, i, j, 0x000000);
			j++;
		}
		i++;
	}
}

unsigned int	get_color(t_map *map, int vx, int y)
{
	return (*(unsigned int *)(map->text.addr + y * map->text.line_length + vx * (map->text.bits_per_pixel / 8)));
}

void	draw_walls(t_map *map, int vx, double angle)
{
	int	j;
	int	x;
	int vy;

	x = fabs(2 * tan(M_PI / 6) * (map->coor.d * cos(angle - map->coor.angle)));
	map->wall.wall_height = ceil(64 * W_WIN / x);
	j = (H_WIN / 2) - (map->wall.wall_height / 2);
	if (j < 0)
		j = 0;
	while (j < H_WIN && j < ((H_WIN / 2) + (map->wall.wall_height / 2)))
	{
		vy = (j - (H_WIN / 2) + (map->wall.wall_height / 2)) * 64.0 / map->wall.wall_height;
		my_mlx_put_pixel(&map->image, map->wall.x,
			map->wall.y + j, get_color(map, vx, vy));
		j++;
	}
}
