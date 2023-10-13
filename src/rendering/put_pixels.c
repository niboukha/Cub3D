/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:24:04 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/13 20:59:45 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_put_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < W_WIN && y >= 0 && y < H_WIN)
	{
		dst = img->addr + ((y * img->line_length)
				+ (x * (img->bits_per_pixel / 8)));
		*(unsigned int *)dst = color;
	}
}

void	put_pixel(t_map *map)
{
	get_coor_player(map);
	get_dist_wall(map);
	player_collisions(map, map->coor.px, map->coor.py);
	fill_minimap(map);
	fill_cub_p(map, map->coor.m_x, map->coor.m_y, 0xff0000);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->image.img, 0, 0);
}
