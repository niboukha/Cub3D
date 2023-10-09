/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:24:04 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/04 12:13:43 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_put_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + ((y * img->line_length) + (x * (img->bits_per_pixel / 8)));
	*(unsigned int *)dst = color;
}


void	draw_rays(t_map *map, double angle)
{
	int	i;

	i = 0;
	while (i < map->coor.d)
	{
		my_mlx_put_pixel(&map->img,
			map->coor.px + cos(angle) * i,
			map->coor.py + sin(angle) * i, 0xff0000);
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
			if (i == 0 || i == 63 || j == 0 || j == 63)
				my_mlx_put_pixel(&map->img, (x * 64) + j, (y * 64) + i, 0x0);
			else
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

void	put_pixel(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1')
				fill_cub_pixels(map, j, i, 0xffffff);
			else
				fill_cub_pixels(map, j, i, 0x0000FF);
			if ((map->map[i][j] == 'N' || map->map[i][j] == 'E'
				|| map->map[i][j] == 'W' || map->map[i][j] == 'S')
				&& !map->coor.put)
			{
				if (map->map[i][j] == 'N')
					map->coor.angle = 3 * M_PI / 2;
				else if (map->map[i][j] == 'E')
					map->coor.angle = 2 * M_PI;
				else if (map->map[i][j] == 'S')
					map->coor.angle = M_PI / 2;
				else if (map->map[i][j] == 'W')
					map->coor.angle = M_PI;
				map->coor.put = 1;
				map->coor.py = i * 64 + 32;
				map->coor.px = j * 64 + 32;
			}
			j++;
		}
		i++;
	}
	fill_cub_player(map, map->coor.px , map->coor.py , 0x00FF00);
	get_dist_wall(map, 0x00FF00);
	player_collisions(map, map->coor.px, map->coor.py);
	mlx_put_image_to_window(map->mlx, map->mlx_win1, map->img.img, 0, 0);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->image.img, 0, 0);
}
