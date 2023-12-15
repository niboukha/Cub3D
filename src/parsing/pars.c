/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 03:34:30 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/14 10:04:20 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_pos(char **map, t_map *ma)
{
	int	i;
	int	j;

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

void	check_player_pos(t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (data->files->map[i])
	{
		if (data->files->map[i] == 'N' || data->files->map[i] == 'S'
			|| data->files->map[i] == 'E' || data->files->map[i] == 'W')
			count++;
		i++;
	}
	if (count != 1)
	{
		ft_putstr_fd("Error : Player needed\n", 2);
		exit(0);
	}
}

int	parsing(t_data *data, t_map *map, int fd)
{
	read_file(data, fd);
	split_file(data);
	free_string(data->files->file);
	if (check_texture_path(data))
	{
		ft_putstr_fd("Error : Texture path not valid2\n", 2);
		exit(EXIT_FAILURE);
	}
	if (check_deriction(data))
	{
		ft_putstr_fd("Error : Deriction not valid\n", 2);
		exit(EXIT_FAILURE);
	}
	if (check_colors(data))
	{
		ft_putstr_fd("Error : Colors not valid\n", 2);
		exit(EXIT_FAILURE);
	}
	check_map(data);
	map->map = ft_split(data->files->map, '\n');
	get_pos(map->map, map);
	check_player_pos(data);
	return (0);
}
