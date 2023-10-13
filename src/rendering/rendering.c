/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xshel <xshel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:19:31 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/13 15:35:19 by xshel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_mlx(t_map *map)
{
	int	w_img;
	int	h_img;

	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, W_WIN, H_WIN,
			"cub3d");
	map->image.img = mlx_new_image(map->mlx, W_WIN, H_WIN);
	map->image.addr = mlx_get_data_addr(map->image.img,
			&map->image.bits_per_pixel, &map->image.line_length,
			&map->image.endian);
	map->textures.img_w = mlx_xpm_file_to_image(map->mlx,
			"/home/xshel/Desktop/my_cub/textures/west1.xpm", &w_img, &h_img);
	map->textures.img_e = mlx_xpm_file_to_image(map->mlx,
			"/home/xshel/Desktop/my_cub/textures/east1.xpm",
			&w_img, &h_img);
	map->textures.img_s = mlx_xpm_file_to_image(map->mlx,
			"/home/xshel/Desktop/my_cub/textures/south1.xpm",
			&w_img, &h_img);
	map->textures.img_n = mlx_xpm_file_to_image(map->mlx,
			"/home/xshel/Desktop/my_cub/textures/north1.xpm",
			&w_img, &h_img);
}

void	rendering(t_map	*map)
{
	init_map(map);
	init_mlx(map);
	put_pixel(map);
	mlx_hook(map->mlx_win, 2, 1L << 0, key, map);
	mlx_mouse_hook(map->mlx_win, mouse_key, map);
	mlx_hook(map->mlx_win, 17, 1L << 0, close_win, map);
	mlx_loop(map->mlx);
}
