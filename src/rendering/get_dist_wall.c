/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:01:54 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/05 18:45:19 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_if_wall(t_map *map, int x, int y)
{
	int	i;
	int	j;

	if (map->coor.left == 1)
		i = (x - 1) / 64;
	else if (map->coor.right == 1)
		i = (x + 1) / 64;
	j = y / 64;
	if (i >= 0 && j >= 0 && j < map->coor.y
		&& i < (int)ft_strlen(map->map[j])
		&& map->map[j][i] == '1')
		return (1);

	if (map->coor.up == 1)
		j = (y - 1) / 64;
	else if (map->coor.down == 1)
		j = (y + 1) / 64;
	i = x / 64;
	if (i >= 0 && j >= 0 && j < map->coor.y
		&& i < (int)ft_strlen(map->map[j])
		&& map->map[j][i] == '1')
			return (1);

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
	return (0);
}

void	get_dist_wall(t_map *map, int color)
{
	double	angle;

	(void)color;
	angle = map->coor.angle - (30 * M_PI / 180);
	while (map->wall.x < (int)W_WIN)
	{
		if (angle < 0)
			angle += 2 * M_PI;
		if (angle >= 2 * M_PI)
			angle -= 2 * M_PI;
		inter_hori_wall(map, angle);
		inter_ver_wall(map, angle);
		int vx;
		if (map->coor.d_h < map->coor.d_v)
		{
			map->coor.d = map->coor.d_h;
			vx = ((int )map->wall.h_x) % 64;
		}
		else
		{
			map->coor.d = map->coor.d_v;
			vx = (int )map->wall.v_y % 64;
		}
		draw_walls(map, vx, angle);
		map->wall.x++;
		angle += ((60.0 * M_PI) / (W_WIN * 180));
	}
	map->wall.x = 0;
	map->wall.y = 0;
}
