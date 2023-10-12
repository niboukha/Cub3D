/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:15:15 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/11 17:50:43 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_wall(t_map *map, int x, int y)
{
	int	i;
	int	j;

	i = x / 64;
	j = y / 64;
	if (i >= 0 && j >= 0 && j < map->coor.y
		&& i < (int)ft_strlen(map->map[j])
		&& map->map[j][i] == '1')
		return (1);
	else if (i >= 0 && j >= 0 && j < map->coor.y
		&& i < (int)ft_strlen(map->map[j])
		&& map->map[j][i] == 'R')
		return (2);
	return (0);
}

int	check_wall_coor(t_map *map, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (map->coor.left == 1)
		i = (x - 1) / 64;
	else if (map->coor.right == 1)
		i = (x + 1) / 64;
	j = y / 64;
	if (i >= 0 && j >= 0 && j < map->coor.y
		&& i < (int)ft_strlen(map->map[j])
		&& map->map[j][i] == '1')
		return (1);
	else if (i >= 0 && j >= 0 && j < map->coor.y
		&& i < (int)ft_strlen(map->map[j])
		&& map->map[j][i] == 'R')
		return (2);
	if (map->coor.up == 1)
		j = (y - 1) / 64;
	else if (map->coor.down == 1)
		j = (y + 1) / 64;
	i = x / 64;
	if (i >= 0 && j >= 0 && j < map->coor.y
		&& i < (int)ft_strlen(map->map[j])
		&& map->map[j][i] == '1')
		return (1);
	else if (i >= 0 && j >= 0 && j < map->coor.y
		&& i < (int)ft_strlen(map->map[j])
		&& map->map[j][i] == 'R')
		return (2);
	return (0);
}

int	check_if_wall(t_map *map, int x, int y)
{
	int	i;
	int	j;

	check_wall(map, x, y);
	check_wall_coor(map, x, y);
	i = 0;
	j = 0;
	if (map->coor.up == 1)
		j = (y - 1) / 64;
	else if (map->coor.down == 1)
		j = (y + 1) / 64;
	else
		j = y / 64;
	if (map->coor.left == 1)
		i = (x - 1) / 64;
	else if (map->coor.right == 1)
		i = (x + 1) / 64;
	else
		i = x / 64;
	if (i >= 0 && j >= 0 && j < map->coor.y
		&& i < (int)ft_strlen(map->map[j])
		&& map->map[j][i] == '1')
		return (1);
	else if (i >= 0 && j >= 0 && j < map->coor.y
		&& i < (int)ft_strlen(map->map[j])
		&& map->map[j][i] == 'R')
		return (2);
	return (0);
}

int	check_door(t_map *map, int x, int y, int c)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->coor.y)
	{
		j = 0;
		while (x / 64 < (int)ft_strlen(map->map[i]) && j < (int)ft_strlen(map->map[i]))
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
