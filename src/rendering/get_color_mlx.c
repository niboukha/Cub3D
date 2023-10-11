/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:47:09 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/10 16:23:51 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

unsigned int	get_color(t_map *map, int x, int y)
{
	char	*dst;

	dst = map->textures.addr + y * map->textures.line_length
		+ x * (map->textures.bits_per_pixel / 8);
	return (*(unsigned int *)(dst));
	return (0);
}

unsigned int	get_color_(t_map *map, int x, int y)
{
	// if (x >= 0 && x < map->sprit.w_img && y >= 0 && y < map->sprit.h_img)
	// {
		return (*(unsigned int *)(map->sprit.addr + y * map->sprit.line_length
			+ x * (map->sprit.bits_per_pixel / 8)));
	// }
	return (0);
}
