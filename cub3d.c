/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:19:31 by niboukha          #+#    #+#             */
/*   Updated: 2023/09/11 15:32:53 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_map *map)
{
	map->map[0] = "111111111";
	map->map[1] = "100000001";
	map->map[2] = "100N00001";
	map->map[3] = "100000001";
	map->map[4] = "111111111";
	map->coor->x = 0;
	map->coor->y = 0;
}

int	main(int ac, char **av)
{
	t_map	*map;

	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, map->coor->x * 64, map->coor->y * 64,
					"cub3d");
	
	return (0);
}

