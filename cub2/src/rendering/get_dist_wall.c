/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dist_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:01:54 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/06 19:41:47 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_if_wall(t_map *map, double x, double y)
{
	int	i;
	int	j;

	i = x / 64;
	j = y / 64;

	if (i >= 0 && j >= 0 && j < map->coor.y
		&& i < (int)ft_strlen(map->map[j])
		&& map->map[j][i] == '1')
		return (1);

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

int	player_collisions(t_map *map, int x, int y)
{
	double	angle;

	angle = 0;
	while (angle <= 2 * M_PI)
	{
		if (check_if_wall(map, x + roundf(cos(angle) * 10),
			y + roundf(sin(angle) * 10)) == 1)
			return (1);
		my_mlx_put_pixel(&map->img, x + roundf(cos(angle) * 10),
			y + roundf(sin(angle) * 10), 0xff0000);
		angle += 0.1;
	}
	return (0);
}

void	get_dist_wall(t_map *map, int color)
{
	double	angle;

	angle = map->coor.angle - (30 * M_PI / 180);
	while (map->wall.x < (int)W_WIN)
	{
		if (angle < 0)
			angle += 2 * M_PI;
		if (angle >= 2 * M_PI)
			angle -= 2 * M_PI;
		inter_hori_wall(map, angle);
		inter_ver_wall(map, angle);
		if (map->coor.d_h < map->coor.d_v)
		{
			map->coor.d = map->coor.d_h;
			color = 0x00ff00;
		}
		else
		{
			map->coor.d = map->coor.d_v;
			color = 0xff00f0;
		}
		draw_rays(map, angle);
		draw_walls(map, color, angle);
		(void)color;
		map->wall.x++;
		angle += ((60.0 * M_PI) / (W_WIN * 180));
	}
	map->wall.x = 0;
	map->wall.y = 0;
}
