/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:24:04 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/05 18:45:49 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_put_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + ((y * img->line_length) + (x * (img->bits_per_pixel / 8)));
	*(unsigned int *)dst = color;
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
	get_dist_wall(map, 0x00FF00);
	player_collisions(map, map->coor.px, map->coor.py);
	fill_minimap(map);
	fill_cub_p(map, map->coor.m_x, map->coor.m_y, 0xff0000);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->image.img, 0, 0);
}
