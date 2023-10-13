/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:36:04 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/07 20:53:21 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_pixel_minimap(t_map *map, int i, int j)
{
	if (map->map[map->mini.e / 64][map->mini.f / 64] == '1')
		my_mlx_put_pixel(&map->image, j, i, 0xf0f0f0);
	else if (map->map[map->mini.e / 64][map->mini.f / 64] == '0')
		my_mlx_put_pixel(&map->image, j, i, 0x0000ff);
	else if (map->map[map->mini.e / 64][map->mini.f / 64] == 'R')
		my_mlx_put_pixel(&map->image, j, i, 0x008000);
	else
		my_mlx_put_pixel(&map->image, j, i, 0x0000);
	if (map->map[map->mini.e / 64][map->mini.f / 64] == 'N'
		|| map->map[map->mini.e / 64][map->mini.f / 64] == 'E'
		|| map->map[map->mini.e / 64][map->mini.f / 64] == 'W'
		|| map->map[map->mini.e / 64][map->mini.f / 64] == 'S')
	{
		my_mlx_put_pixel(&map->image, j, i, 0x0000ff);
		map->coor.m_x = 100;
		map->coor.m_y = 75;
	}
}

void	fill_minimap(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->mini.e = map->coor.py - 75;
	while (i < 150 && (map->mini.e / 64) < map->coor.y
		&& map->mini.e < map->coor.py + 75)
	{
		j = 0;
		map->mini.f = map->coor.px - 100;
		while ((map->mini.f / 64) < (int)ft_strlen(map->map[map->mini.e / 64])
			&& j < 200 && map->mini.f < map->coor.px + 100)
		{
			put_pixel_minimap(map, i, j);
			map->mini.f++;
			j++;
		}
		map->mini.e++;
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
