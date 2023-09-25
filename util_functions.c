/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:26:19 by niboukha          #+#    #+#             */
/*   Updated: 2023/09/25 15:26:46 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	distance_wall(t_map *map, double x, double y)
{
	return (sqrt(pow(map->coor.px - x, 2) + pow(map->coor.py - y, 2)));
}
