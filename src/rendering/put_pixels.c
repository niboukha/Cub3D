/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:24:04 by niboukha          #+#    #+#             */
/*   Updated: 2023/09/25 20:50:37 by niboukha         ###   ########.fr       */
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
	while (i < 10)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1')
			{
				printf("%d -- %d\n", i, j);
				fill_cub_pixels(map, j, i, 0x00000000);
				// fill_cub_pxl(map, j, i, 0x00000000);
			}
			else
			{
				fill_cub_pixels(map, j, i, 0x0000FF);
				// fill_cub_pxl(map, j, i, 0x0000FF);
			}
			if (map->map[i][j] == 'N' && !map->coor.put)
			{
				map->coor.put = 1;
				map->coor.py = i * 64 + 32;
				map->coor.px = j * 64 + 32;
				map->coor.py1 = i * 10 + 5;
				map->coor.px1 = j * 10 + 5;
			}
			j++;
		}
		i++;
	}
	fill_cub_player(map, map->coor.px , map->coor.py , 0x00FF00);
	// fill_cub_p(map, map->coor.px1 , map->coor.py1 , 0x00FF00);
	get_dist_wall(map, 0x00FF00);
	player_collisions(map, map->coor.px, map->coor.py);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img.img, 0, 0);
	mlx_put_image_to_window(map->mlx, map->mlx_win1, map->image.img, 0, 0);
	// mlx_put_image_to_window(map->mlx, map->mlx_win2, map->img_m.img, 0, 0);
}