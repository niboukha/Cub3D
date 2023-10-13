/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:42:25 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/13 20:10:17 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	animation(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->image.img, 0, 0);
	pthread_mutex_lock(&map->mut);
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->sprit.img_d[map->index].img,
		W_WIN / 2, H_WIN - map->sprit.img_d[map->index].h);
	pthread_mutex_unlock(&map->mut);
	return (0);
}
