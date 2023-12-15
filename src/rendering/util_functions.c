/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:26:19 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/15 11:08:08 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_map(t_map *map)
{
	map->coor.px = 0;
	map->coor.py = 0;
	map->wall.x = 0;
	map->wall.y = 0;
	map->coor.put = 0;
	map->index = 0;
	map->coor.flag_a = 0;
	map->dr.i = 0;
	map->dr.j = 0;
}

int	close_win(void)
{
	exit(0);
}

double	distance_wall(t_map *map, double x, double y)
{
	return (sqrt(pow(map->coor.px - x, 2) + pow(map->coor.py - y, 2)));
}

unsigned int	convert_color(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}
