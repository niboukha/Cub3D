/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:19:31 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/08 18:16:28 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_image(t_map *map)
{
	map->sprit.img_d[0] = mlx_xpm_file_to_image(map->mlx,
			"/nfs/homes/niboukha/Desktop/cub/textures/anmt/dr1.xpm", &map->sprit.w_img, &map->sprit.h_img);
	map->sprit.img_d[1] = mlx_xpm_file_to_image(map->mlx,
			"/nfs/homes/niboukha/Desktop/cub/textures/anmt/dr3.xpm", &map->sprit.w_img, &map->sprit.h_img);
	map->sprit.img_d[2] = mlx_xpm_file_to_image(map->mlx,
			"/nfs/homes/niboukha/Desktop/cub/textures/anmt/dr5.xpm", &map->sprit.w_img, &map->sprit.h_img);
	map->sprit.img_d[3] = mlx_xpm_file_to_image(map->mlx,
			"/nfs/homes/niboukha/Desktop/cub/textures/anmt/dr7.xpm", &map->sprit.w_img, &map->sprit.h_img);
	map->sprit.img_d[4] = mlx_xpm_file_to_image(map->mlx,
			"/nfs/homes/niboukha/Desktop/cub/textures/anmt/dr9.xpm", &map->sprit.w_img, &map->sprit.h_img);
	map->sprit.img_d[5] = mlx_xpm_file_to_image(map->mlx,
			"/nfs/homes/niboukha/Desktop/cub/textures/anmt/dr10.xpm", &map->sprit.w_img, &map->sprit.h_img);
	map->sprit.img_d[6] = mlx_xpm_file_to_image(map->mlx,
			"/nfs/homes/niboukha/Desktop/cub/textures/anmt/dr12.xpm", &map->sprit.w_img, &map->sprit.h_img);
	map->sprit.img_d[7] = mlx_xpm_file_to_image(map->mlx,
			"/nfs/homes/niboukha/Desktop/cub/textures/anmt/dr14.xpm", &map->sprit.w_img, &map->sprit.h_img);
	map->sprit.img_d[8] = mlx_xpm_file_to_image(map->mlx,
			"/nfs/homes/niboukha/Desktop/cub/textures/anmt/dr16.xpm", &map->sprit.w_img, &map->sprit.h_img);
	map->sprit.img_d[9] = mlx_xpm_file_to_image(map->mlx,
			"/nfs/homes/niboukha/Desktop/cub/textures/anmt/dr18.xpm", &map->sprit.w_img, &map->sprit.h_img);
	// map->sprit.img_d[10] = mlx_xpm_file_to_image(map->mlx,
	// 		"/nfs/homes/niboukha/Desktop/cub/textures/AnyConv.com__d1.xpm", &map->sprit.w_img, &map->sprit.h_img);
}

void	init_mlx(t_map *map)
{
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, W_WIN, H_WIN,
			"cub3d");
	map->image.img = mlx_new_image(map->mlx, W_WIN, H_WIN);
	map->image.addr = mlx_get_data_addr(map->image.img,
			&map->image.bits_per_pixel, &map->image.line_length,
			&map->image.endian);
	map->textures.img_w = mlx_xpm_file_to_image(map->mlx,
			"/nfs/homes/niboukha/Desktop/cub/textures/we.xpm", &map->textures.w_img, &map->textures.h_img);
	map->textures.img_e = mlx_xpm_file_to_image(map->mlx,
			"/nfs/homes/niboukha/Desktop/cub/textures/skull.xpm",
			&map->textures.w_img, &map->textures.h_img);
	map->textures.img_s = mlx_xpm_file_to_image(map->mlx,
			"/nfs/homes/niboukha/Desktop/cub/textures/so.xpm",
			&map->textures.w_img, &map->textures.h_img);
	map->textures.img_n = mlx_xpm_file_to_image(map->mlx,
			"/nfs/homes/niboukha/Desktop/cub/textures/no.xpm",
			&map->textures.w_img, &map->textures.h_img);
	init_image(map);
}

void	rendering(t_map	*map)
{
	init_map(map);
	init_mlx(map);
	put_pixel(map);
	mlx_hook(map->mlx_win, 2, 1L << 0, key, map);
	mlx_mouse_hook(map->mlx_win, mouse_key, map);
	mlx_loop_hook(map->mlx, animation, map);
	mlx_hook(map->mlx_win, 17, 1L << 0, close_win, map);
	mlx_loop(map->mlx);
}
