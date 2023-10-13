/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:47:09 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/13 20:25:07 by niboukha         ###   ########.fr       */
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
	return (*(unsigned int *)(map->door.addr + y * map->door.line_length
		+ x * (map->door.bits_per_pixel / 8)));
	return (0);
}
