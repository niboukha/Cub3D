/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 03:34:30 by m-boukel          #+#    #+#             */
/*   Updated: 2023/09/30 13:59:44 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_pos(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{	
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
			{
				data->pos->x = i;
				data->pos->y = j;
				data->pos->dir = map[i][j];
				return ;
			}
			j++;
		}
		i++;
	}
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
	get_pos(&data, map->map);
	return (0);
}