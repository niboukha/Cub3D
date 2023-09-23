/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 09:52:32 by niboukha          #+#    #+#             */
/*   Updated: 2023/09/23 17:47:27 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
			my_mlx_put_pixel(&map->image, i,
			j, 0x000000);
			j++;
		}
		i++;
	}
}

void	draw_walls(t_map *map, int color)
{
	int	j;
	double	wall_height;

	wall_height = roundf(30000 / map->coor.d);
	j = (H_WIN / 2) - (wall_height / 2);
	if (j < 0)
		j = 0;
	while (j < H_WIN && j < ((H_WIN / 2) + (wall_height / 2)))
	{
		my_mlx_put_pixel(&map->image, map->wall.x,
			map->wall.y + j, color);
		j++;
	}
}
