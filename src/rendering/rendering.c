/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:19:31 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/15 10:58:37 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_image_sprt(t_map *map)
{
	map->sprit.img_d[0].img = mlx_xpm_file_to_image(map->mlx,
			"/Users/niboukha/Desktop/cub3d/textures/gun/frame1.xpm",
			&map->sprit.img_d[0].w, &map->sprit.img_d[0].h);
	map->sprit.img_d[1].img = mlx_xpm_file_to_image(map->mlx,
			"/Users/niboukha/Desktop/cub3d/textures/gun/frame2.xpm",
			&map->sprit.img_d[1].w, &map->sprit.img_d[1].h);
	map->sprit.img_d[2].img = mlx_xpm_file_to_image(map->mlx,
			"/Users/niboukha/Desktop/cub3d/textures/gun/frame3.xpm",
			&map->sprit.img_d[2].w, &map->sprit.img_d[2].h);
	map->sprit.img_d[3].img = mlx_xpm_file_to_image(map->mlx,
			"/Users/niboukha/Desktop/cub3d/textures/gun/frame4.xpm",
			&map->sprit.img_d[3].w, &map->sprit.img_d[3].h);
	map->sprit.img_d[4].img = mlx_xpm_file_to_image(map->mlx,
			"/Users/niboukha/Desktop/cub3d/textures/gun/frame5.xpm",
			&map->sprit.img_d[4].w, &map->sprit.img_d[4].h);
	if (!map->sprit.img_d[0].img || !map->sprit.img_d[1].img
		|| !map->sprit.img_d[2].img || !map->sprit.img_d[3].img
		|| !map->sprit.img_d[4].img)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	init_image_door(t_map *map)
{
	map->door.img = mlx_xpm_file_to_image(map->mlx,
			"/Users/niboukha/Desktop/cub3d/textures/dr.xpm",
			&map->door.w_img, &map->door.h_img);
	if (!map->door.img)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	get_texture(t_map *map)
{
	map->textures.img_w.img = mlx_xpm_file_to_image(map->mlx,
			map->data->files->texture._we,
			&map->textures.img_w.w, &map->textures.img_w.h);
	map->textures.img_e.img = mlx_xpm_file_to_image(map->mlx,
			map->data->files->texture._ea,
			&map->textures.img_e.w, &map->textures.img_e.h);
	map->textures.img_s.img = mlx_xpm_file_to_image(map->mlx,
			map->data->files->texture._so,
			&map->textures.img_s.w, &map->textures.img_s.h);
	map->textures.img_n.img = mlx_xpm_file_to_image(map->mlx,
			map->data->files->texture._no,
			&map->textures.img_n.w, &map->textures.img_n.h);
	if (!map->textures.img_w.img || !map->textures.img_e.img
		|| !map->textures.img_s.img || !map->textures.img_n.img)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
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
	get_texture(map);
	init_image_sprt(map);
	init_image_door(map);
}

void	rendering(t_map	*map)
{
	pthread_mutex_init(&map->mut, NULL);
	init_map(map);
	init_mlx(map);
	put_pixel(map);
	mlx_hook(map->mlx_win, ON_KEYDOWN, 0, key, map);
	mlx_mouse_hook(map->mlx_win, mouse_key, map);
	mlx_loop_hook(map->mlx, animation, map);
	mlx_hook(map->mlx_win, ON_DESTROY, 0, close_win, map);
	mlx_loop(map->mlx);
}
