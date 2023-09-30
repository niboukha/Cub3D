/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:36:04 by niboukha          #+#    #+#             */
/*   Updated: 2023/09/25 20:50:28 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	fill_cub_pxl(t_map *map, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			// if (i == 0 || i == 63 || j == 0 || j == 63)
			// 	my_mlx_put_pixel(&map->img, (x * 10) + j, (y * 10) + i, 0xffffff);
			// else
				printf("%d %d\n", x , y );
				my_mlx_put_pixel(&map->img_m, (x * 10) + j, (y * 10) + i, color);
			j++;
		}
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
			my_mlx_put_pixel(&map->img_m, j, i, color);
			j++;
		}
		i++;
	}
}
