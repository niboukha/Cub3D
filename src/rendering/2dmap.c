/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2dmap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:14:57 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/01 11:15:14 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void	draw_rays(t_map *map, double angle)
// {
// 	int	i;

// 	i = 0;
// 	while (i < map->coor.d)
// 	{
// 		my_mlx_put_pixel(&map->img,
// 			map->coor.px + roundf(cos(angle) * i),
// 			map->coor.py + roundf(sin(angle) * i), 0xff0000);
// 		i++;
// 	}
// }

// void	fill_cub_pixels(t_map *map, int x, int y, int color)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < 64)
// 	{
// 		j = 0;
// 		while (j < 64)
// 		{
// 			my_mlx_put_pixel(&map->img, (x * 64) + j, (y * 64) + i, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	fill_cub_player(t_map *map, int x, int y, int color)
// {
// 	int	i;
// 	int	j;

// 	i = y - 2;
// 	while (i <= y + 2 && i >= 0)
// 	{
// 		j = x - 2;
// 		while (j <= x + 2 && j >= 0)
// 		{
// 			my_mlx_put_pixel(&map->img, j, i, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }