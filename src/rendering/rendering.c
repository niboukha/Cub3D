/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:19:31 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/05 14:42:51 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rendering(t_map	*map)
{
	init_map(map);
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, W_WIN, H_WIN,
					"cub3d");
	map->image.img = mlx_new_image(map->mlx, W_WIN, H_WIN);
	map->image.addr = mlx_get_data_addr(map->image.img, &map->image.bits_per_pixel,
					&map->image.line_length, &map->image.endian);
	put_pixel(map);
	mlx_hook(map->mlx_win, 2, 1L<<0, key, map);
	mlx_mouse_hook(map->mlx_win, mouse_key, map);
	mlx_hook(map->mlx_win, 17, 1L<<0, close_win, map);
	mlx_loop(map->mlx);
}
