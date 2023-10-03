/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 03:34:30 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/03 11:19:45 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_pos(char **map, t_map	*ma)
{
	int		i;
	int		j;

	i = 0;
	ma->coor.y = 0;
	ma->coor.x = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			j++;
			if (j > ma->coor.x)
				ma->coor.x = j;
		}
		i++;
	}
	ma->coor.y = i;
}

int	parsing(t_data data, t_map *map, int fd)
{
	read_file(&data, fd);
	split_file(&data);
	if (check_Deriction(&data))
	{
		ft_putstr_fd("Error : Deriction not valid\n", 2);
		// sould free data->deriction
		return (1);
	}
	if (check_colors(&data))
	{
		ft_putstr_fd("Error : Colors not valid\n", 2);
		// sould free data->clr
		return (1);
	}
	check_map(&data);
	map->map = ft_split(data.files->map, '\n');
	get_pos(map->map, map);
	return (0);
}
