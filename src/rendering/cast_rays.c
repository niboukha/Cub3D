/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 09:52:32 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/08 18:51:51 by niboukha         ###   ########.fr       */
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

unsigned int	get_color(t_map *map, int x, int y)
{
	return (*(unsigned int *)(map->textures.addr + y * map->textures.line_length
		+ x * (map->textures.bits_per_pixel / 8)));
}

unsigned int	get_color_(t_map *map, int x, int y)
{
	return (*(unsigned int *)(map->sprit.addr + y * map->sprit.line_length
		+ x * (map->sprit.bits_per_pixel / 8)));
}

void	draw_ciel(t_map *map, int x, int y)
{
	int	color;

	color = convert_color(map->data->c_c->c->r, map->data->c_c->c->g,
			map->data->c_c->c->b);
	my_mlx_put_pixel(&map->image, x, y, color);
}

void	draw_floor(t_map *map, int x, int y)
{
	int	color;

	color = convert_color(map->data->c_c->f->r, map->data->c_c->f->g,
			map->data->c_c->f->b);
	my_mlx_put_pixel(&map->image, x, y, color);
}

int i = 0;

void	draw_walls(t_map *map, double angle)
{
	int	j;
	int	start;

	map->wall.wall_height = ceil(64 * W_WIN / (fabs(2 * tan(M_PI / 6)
					* (map->coor.d * cos(angle - map->coor.angle)))));
	start = (H_WIN / 2) - (map->wall.wall_height / 2);
	if (start < 0)
		start = 0;
	j = 0;
	while (j < H_WIN)
	{
		if (j <= (H_WIN / 2) - (map->wall.wall_height / 2))
			draw_ciel(map, map->wall.x, map->wall.y + j);
		if (start < (H_WIN / 2) + (map->wall.wall_height / 2))
		{
			if (map->coor.flag_a == 1)
			{
				map->sprt.t_y = (start - (H_WIN / 2) + (map->wall.wall_height / 2))
					* map->sprit.h_img / map->wall.wall_height;
				my_mlx_put_pixel(&map->image, map->wall.x, map->wall.y + start,
					get_color_(map, map->sprt.t_x, map->sprt.t_y));
			}
			else
			{
				map->txt.y = (start - (H_WIN / 2) + (map->wall.wall_height / 2))
					* map->textures.h_img / map->wall.wall_height;
				my_mlx_put_pixel(&map->image, map->wall.x, map->wall.y + start,
					get_color(map, map->txt.x, map->txt.y));
			}
			start++;
		}
		if (j >= (H_WIN / 2) + (map->wall.wall_height / 2))
			draw_floor(map, map->wall.x, map->wall.y + j);
		j++;
	}
	// j = (H_WIN / 2) - (map->wall.wall_height / 2);
	// if (j < 0)
	// 	j = 0;
	// map->wall.y = 0;
	// while (j < H_WIN && j < (H_WIN / 2) + (map->wall.wall_height / 2))
	// {
	// 	if (map->coor.flag_a)
	// 	{
	// 		map->sprt.t_y = (j - (H_WIN / 2) + (map->wall.wall_height / 2))
	// 			* map->sprit.h_img / map->wall.wall_height;
	// 		my_mlx_put_pixel(&map->image, map->wall.x, map->wall.y + j,
	// 			get_color_(map, map->sprt.t_x, map->sprt.t_y));
	// 	}
	// 	j++;
	// }
}
