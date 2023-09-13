/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:19:31 by niboukha          #+#    #+#             */
/*   Updated: 2023/09/13 16:45:41 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_map *map)
{
	map->map = malloc (sizeof(char *) * 7);
	map->map[0] = "11111111111";
	map->map[1] = "10010001001";
	map->map[2] = "10000000001";
	map->map[3] = "100N0001001";
	map->map[4] = "10000000001";
	map->map[5] = "10001000001";
	map->map[6] = "11111111111";
	map->coor.x = strlen(map->map[0]);
	map->coor.y = 7;
	map->coor.new_i = 0;
	map->coor.new_j = 0;
}


int	exit_prog(void)
{
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;

	(void)ac;
	(void)av;
	init_map(&map);
	map.mlx = mlx_init();
	map.mlx_win = mlx_new_window(map.mlx, map.coor.x * 64, map.coor.y * 64,
					"cub3d");
	map.img.img = mlx_new_image(map.mlx, map.coor.x * 64, map.coor.y * 64);
	map.img.addr = mlx_get_data_addr(map.img.img, &map.img.bits_per_pixel,
					&map.img.line_length, &map.img.endian);
	put_pixel(&map);
	mlx_put_image_to_window(map.mlx, map.mlx_win, map.img.img, 0, 0);
	mlx_hook(map.mlx_win, 2, 1L<<0, key, &map);
	mlx_hook(map.mlx_win, 17, 1L<<0, exit_prog, &map);
	mlx_loop(map.mlx);
	return (0);
}
