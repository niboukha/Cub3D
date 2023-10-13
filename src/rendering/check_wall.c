/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:15:15 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/13 20:22:56 by niboukha         ###   ########.fr       */
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
	return (0);
}

int	check_wall_coor_1(t_map *map, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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

int	check_wall_coor_2(t_map *map, int x, int y)
{
	int	i;
	int	j;

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

int	check_if_wall(t_map *map, int x, int y)
{
	check_wall(map, x, y);
	check_wall_coor(map, x, y);
	check_wall_coor_1(map, x, y);
	if (check_wall_coor_2(map, x, y))
		return (check_wall_coor_2(map, x, y));
	return (0);
}
