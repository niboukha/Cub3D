/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collisions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:38:52 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/13 20:59:10 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_direction_player(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'N')
		map->coor.angle = 3 * M_PI / 2;
	else if (map->map[i][j] == 'E')
		map->coor.angle = 2 * M_PI;
	else if (map->map[i][j] == 'S')
		map->coor.angle = M_PI / 2;
	else if (map->map[i][j] == 'W')
		map->coor.angle = M_PI;
}

void	get_coor_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if ((map->map[i][j] == 'N' || map->map[i][j] == 'E'
				|| map->map[i][j] == 'W' || map->map[i][j] == 'S')
				&& !map->coor.put)
			{
				check_direction_player(map, i, j);
				map->coor.put = 1;
				map->coor.py = i * 64 + 32;
				map->coor.px = j * 64 + 32;
			}
			j++;
		}
		i++;
	}
}

int	player_collisions(t_map *map, int x, int y)
{
	double	angle;

	angle = 0;
	while (angle <= 2 * M_PI)
	{
		if (check_if_wall(map, x + roundf(cos(angle) * 15),
				y + roundf(sin(angle) * 15)) == 1
			|| check_if_wall(map, x + roundf(cos(angle) * 15),
				y + roundf(sin(angle) * 15)) == 2)
		{
			return (1);
		}
		angle += 0.1;
	}
	return (0);
}
