/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:18:06 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/13 20:18:22 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_doors(t_map *map, int x, int y, int c)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->coor.y)
	{
		j = 0;
		while (x / 64 < (int)ft_strlen(map->map[i])
			&& j < (int)ft_strlen(map->map[i]))
		{
			if (map->map[i][x / 64] == 'R'
				&& j == x / 64 && c == 2)
				return (1);
			if (map->map[i][j] == 'R' && i == y / 64 && c == 1)
				return (2);
			j++;
		}
		i++;
	}
	return (0);
}
