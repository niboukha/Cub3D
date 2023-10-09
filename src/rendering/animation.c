/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:42:25 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/08 18:18:16 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	animation(t_map *map)
{
	map->sprt.timer++;
	if (map->sprt.timer >= 100)
		map->sprt.timer = 0;
	put_pixel(map);
	return (0);
}
