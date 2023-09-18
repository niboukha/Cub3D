/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 09:52:32 by niboukha          #+#    #+#             */
/*   Updated: 2023/09/18 17:53:17 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_map3(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < 500)
	{
		j = 0;
		while (j < 300)
		{
			my_mlx_put_pixel(&map->image, map->wall.x,
			map->wall.y, 0);
			j++;
		}
		i++;
	}
}

void	draw_walls(t_map *map, int color)
{
	int	j;
	double	wall_height;

	wall_height = roundf(64.0 / map->coor.d * 250 / roundf(tan(30 * M_PI / 180)));
	j = 150 - (wall_height / 2);
	while (j < 150 + (wall_height / 2))
	{
		my_mlx_put_pixel(&map->image, map->wall.x,
			map->wall.y + j, color);
		j++;
	}
}
