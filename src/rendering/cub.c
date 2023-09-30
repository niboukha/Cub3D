/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:19:31 by niboukha          #+#    #+#             */
/*   Updated: 2023/09/30 12:41:25 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_map(t_map *map)
{
	// map->map = malloc (sizeof(char *) * 10);
	// map->map[0] = "11111111111";
	// map->map[1] = "10010001001";
	// map->map[2] = "10000000001";
	// map->map[3] = "100N0001001";
	// map->map[4] = "10000000001";
	// map->map[5] = "10001000001";
	// map->map[6] = "10001000001";
	// map->map[7] = "10001000001";
	// map->map[8] = "10001000001";
	// map->map[9] = "11111111111";
	map->coor.x = strlen(map->map[0]);
	map->coor.y = 10;
	map->coor.angle = 0;
}


int	exit_prog(void)
{
	return (0);
}

void	init_mlx(t_map	*map)
{
	//////////////////2D////////////////////////////////////////

	init_map(map);

	//////////////////2D////////////////////////////////////////

	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, map->coor.x * 64, map->coor.y * 64,
					"cub2d");
	map->img.img = mlx_new_image(map->mlx, map->coor.x * 64, map->coor.y * 64);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bits_per_pixel,
					&map->img.line_length, &map->img.endian);

	////////////////3D//////////////////////////////////////////

	map->mlx_win1 = mlx_new_window(map->mlx, W_WIN, H_WIN,
					"cub3d");
	map->image.img = mlx_new_image(map->mlx, W_WIN, H_WIN);
	map->image.addr = mlx_get_data_addr(map->image.img, &map->image.bits_per_pixel,
					&map->image.line_length, &map->image.endian);

	/////////////minimap/////////////////////////////////////////////////////

	map->mlx_win2 = mlx_new_window(map->mlx, 110, 100, "minimap");
	map->img_m.img = mlx_new_image(map->mlx, 110, 100);
	map->img_m.addr = mlx_get_data_addr(map->img_m.img, &map->img_m.bits_per_pixel,
					&map->img_m.line_length, &map->img_m.endian);

	put_pixel(map);
	mlx_hook(map->mlx_win, 2, 1L<<0, key, &map);
	mlx_hook(map->mlx_win1, 2, 1L<<0, key, &map);
	mlx_hook(map->mlx_win2, 2, 1L<<0, key, &map);
	mlx_hook(map->mlx_win, 17, 1L<<0, exit_prog, &map);
	mlx_hook(map->mlx_win1, 17, 1L<<0, exit_prog, &map);
	mlx_hook(map->mlx_win2, 17, 1L<<0, exit_prog, &map);
	mlx_loop(map->mlx);
}
