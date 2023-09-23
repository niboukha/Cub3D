/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:37:21 by niboukha          #+#    #+#             */
/*   Updated: 2023/09/23 17:34:11 by niboukha         ###   ########.fr       */
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
			if (i == 0 || i == 63 || j == 0 || j == 63)
				my_mlx_put_pixel(&map->img, (x * 64) + j, (y * 64) + i, 0xffffff);
			else
				my_mlx_put_pixel(&map->img, (x * 64) + j, (y * 64) + i, color);
			j++;
		}
		i++;
	}
}

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

void	put_a_ray(t_map *map, int x, int y, int color)
{
	double	angle;

	angle = map->coor.angle - (30 * M_PI / 180);
	while (angle < map->coor.angle + (30 * M_PI / 180))
	{
		inter_hori_wall(map, x, y, angle);
		inter_ver_wall(map, x, y, angle);
		if (map->coor.d_h < map->coor.d_v)
			map->coor.d = map->coor.d_h;
		else
			map->coor.d = map->coor.d_v;
		draw_walls(map, color);
		map->wall.x++;
		angle += ((60.0 / W_WIN) * (M_PI / 180));
	}
	map->coor.d = 0;
	map->coor.d_v = 0;
	map->coor.d_h = 0;
	map->wall.x = 0;
	map->wall.y = 0;
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
	player_collisions(map, map->coor.px, map->coor.py);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img.img, 0, 0);
	mlx_put_image_to_window(map->mlx, map->mlx_win1, map->image.img, 0, 0);
}
