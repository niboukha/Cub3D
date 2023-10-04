/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:36:04 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/04 14:43:37 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


void	fill_minimap(t_map *map)
{
	int	i;
	int	j;
	int	e;
	int	f;

	i = 0;
	e = map->coor.py - 75;
	if (e < 0)
		e = 0;
	while (i < 150 && e < map->coor.py + 75)
	{
		j = 0;
		f = map->coor.px - 100;
		if (f < 0)
			f = 0;
		while (j < 200 && f < map->coor.px + 100)
		{
			if (map->map[e / 64][f / 64] == '1')
				my_mlx_put_pixel(&map->image, j, i, 0xf0f0f0);
			else if (map->map[e / 64][f / 64] == '0')
				my_mlx_put_pixel(&map->image, j, i, 0x0000ff);
			else
				my_mlx_put_pixel(&map->image, j, i, 0x0000);
			if (map->map[e / 64][f / 64] == 'N' || map->map[e / 64][f / 64] == 'E'
				|| map->map[e / 64][f / 64] == 'W' || map->map[e / 64][f / 64] == 'S')
			{
				my_mlx_put_pixel(&map->image, j, i, 0x0000ff);
				map->coor.m_x = 100;
				map->coor.m_y = 75;
			}
			f++;
			j++;
		}
		e++;
		i++;
	}
}

void	fill_cub_p(t_map *map, int x, int y, int color)
{
	int	i;
	int	j;

	i = y - 2;
	while (i <= y + 2 && i >= 0)
	{
		j = x - 2;
		while (j <= x + 2 && j >= 0)
		{
			my_mlx_put_pixel(&map->image, j, i, color);
			j++;
		}
		i++;
	}
}

