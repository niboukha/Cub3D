/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:37:21 by niboukha          #+#    #+#             */
/*   Updated: 2023/09/16 15:14:37 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_put_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + ((y * img->line_length) + (x * (img->bits_per_pixel / 8)));
	*(unsigned int *)dst = color;
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
			my_mlx_put_pixel(&map->img, (x * 64) + j, (y * 64) + i, color);
			j++;
		}
		i++;
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

void	put_a_ray(t_map *map, int x, int y, int color)
{
	int	i;

	i = 0;
	while (!find_wall(map, x + roundf(cos(map->coor.angle) * i),
		y + roundf(sin(map->coor.angle) * i)))
	{
		my_mlx_put_pixel(&map->img,
			x + roundf(cos(map->coor.angle) * i),
			y + roundf(sin(map->coor.angle) * i), color);
		i++;
	}
	map->coor.d = i;
}

int	check_wall(t_map *map, int x, int y)
{
	double	angle;

	angle = 0;
	while (angle <= 2 * M_PI)
	{
		if (find_wall(map, x + roundf(cos(angle) * 15),
			y + roundf(sin(angle) * 15)) == 1)
			return (1);
		my_mlx_put_pixel(&map->img, x + roundf(cos(angle) * 15),
			y + roundf(sin(angle) * 15), 0xFF0000);
		angle += 0.1;
	}
	return (0);
}

void	fill_cub_player(t_map *map, int x, int y, int color)
{
	int	i;
	int	j;

	i = y - 2;
	while (i <= y + 2)
	{
		j = x - 2;
		while (j <= x + 2)
		{
			my_mlx_put_pixel(&map->img, j, i, color);
			j++;
		}
		i++;
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
			else
				fill_cub_pixels(map, j, i, 0x0000FF);
			if (map->map[i][j] == 'N' && !map->coor.put)
			{
				map->coor.put = 1;
				map->coor.py = i * 64 + 32;
				map->coor.px = j * 64 + 32;
			}
			j++;
		}
		i++;
	}
	fill_cub_player(map, map->coor.px , map->coor.py , 0x00FF00);
	put_a_ray(map, map->coor.px , map->coor.py , 0x00FF00);
	check_wall(map, map->coor.px, map->coor.py);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img.img, 0, 0);
}
