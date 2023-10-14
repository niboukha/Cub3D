/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:20:43 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/14 10:04:04 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	maping_in_map(char **map, int i, int j)
{
	if (i == 0 && map[i][j] != '1' && free_string(map))
	{
		ft_putstr_fd("Error : Map not closed\n", 2);
		exit(EXIT_FAILURE);
	}
	if (!map[i + 1] && (map[i][j] != '1' && map[i][j] != ' ')
		&& free_string(map))
	{
		ft_putstr_fd("Error : Map not closed\n", 2);
		exit(EXIT_FAILURE);
	}
	if ((!valid_char(map[i][j + 1]) || !valid_char(map[i][j - 1])
			|| !valid_char(map[i + 1][j]) || !valid_char(map[i
				- 1][j])) && free_string(map))
	{
		ft_putstr_fd("Error : Map not closed\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	handle_map_exist(t_data *data)
{
	if (!data->files->map)
	{
		ft_putstr_fd("Error : No map\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	check_map(t_data *data)
{
	char	**map;
	int		i;
	int		j;

	handle_map_exist(data);
	map = ft_split(data->files->map, '\n');
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'R')
				check_door(map, i, j);
			if (check_char(map[i][j]))
				maping_in_map(map, i, j);
			j++;
		}
		i++;
	}
	free_string(map);
}
