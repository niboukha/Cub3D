/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:37:21 by niboukha          #+#    #+#             */
/*   Updated: 2023/09/25 15:28:11 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_rays(t_map *map, double angle)
{
	int	i;

	i = 0;
	while (i < map->coor.d)
	{
		my_mlx_put_pixel(&map->img,
			map->coor.px + roundf(cos(angle) * i),
			map->coor.py + roundf(sin(angle) * i), 0x00ff00);
		i++;
	}
}

void	fill_cub_pixels(t_map *map, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			// if (i == 0 || i == 63 || j == 0 || j == 63)
			// 	my_mlx_put_pixel(&map->img, (x * 64) + j, (y * 64) + i, 0xffffff);
			// else
				my_mlx_put_pixel(&map->img, (x * 64) + j, (y * 64) + i, color);
			j++;
		}
		i++;
	}
}


void	fill_cub_player(t_map *map, int x, int y, int color)
{
	int	i;
	int	j;

	i = y - 2;
	while (i <= y + 2 && i >= 0)
	{
		j = x - 2;
		while (j <= x + 2 && j >= 0)
		{
			my_mlx_put_pixel(&map->img, j, i, color);
			j++;
		}
		i++;
	}
}
