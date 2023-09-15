/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:37:21 by niboukha          #+#    #+#             */
/*   Updated: 2023/09/14 20:18:13 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_put_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + ((y * img->line_length) + (x * (img->bits_per_pixel / 8)));
	*(unsigned int *)dst = color;
}

void	fill_cub_pixels(t_map *map, int j, int i, int color)
{
	int	k;
	int	e;

	k = 0;
	while (k < 64)
	{
		e = 0;
		while (e < 64)
		{
			my_mlx_put_pixel(&map->img, (j * 64) + e, (i * 64) + k, color);
			e++;
		}
		k++;
	}
}

int	find_wall(t_map *map, int x, int y)
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

void	put_a_ray(t_map *map, int j, int i, int color)
{
	int	f;

	f = 0;
	while (!find_wall(map, (j * 64) + 30 + roundf(cos(map->coor.angle) * f),
		(i * 64) + 30 + roundf(sin(map->coor.angle) * f)))
	{
		my_mlx_put_pixel(&map->img,
			(j * 64) + 30 + roundf(cos(map->coor.angle) * f),
			(i * 64) + 30 + roundf(sin(map->coor.angle) * f), color);
		f++;
	}
}

void	fill_cub_player(t_map *map, int j, int i, int color)
{
	int	k;
	int	e;

	k = 28;
	while (k < 32)
	{
		e = 28;
		while (e < 32)
		{
			my_mlx_put_pixel(&map->img, (j * 64) + e, (i * 64) + k, color);
			e++;
		}
		k++;
	}
}

void	put_pixel(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1')
				fill_cub_pixels(map, j, i, 0x00000000);
			if (map->map[i][j] == '0')
				fill_cub_pixels(map, j, i, 0x0000FF);
			if (map->map[i][j] == 'N' && !map->coor.put)
			{
				map->coor.i = i;
				map->coor.j = j;
				fill_cub_pixels(map, j, i, 0x0000FF);
				fill_cub_player(map, j, i, 0x00FF00);
				put_a_ray(map, j, i, 0x00FF00);
			}
			j++;
		}
		i++;
	}
}
