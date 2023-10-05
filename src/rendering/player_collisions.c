/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collisions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:38:52 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/05 10:40:44 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	player_collisions(t_map *map, int x, int y)
{
	double	angle;

	angle = 0;
	while (angle <= 2 * M_PI)
	{
		if (check_if_wall(map, x + roundf(cos(angle) * 5),
			y + roundf(sin(angle) * 5)) == 1)
			return (1);
		angle += 0.1;
	}
	return (0);
}
