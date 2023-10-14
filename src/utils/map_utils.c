/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:05:30 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/14 10:05:33 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_char(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == 'R')
		return (1);
	return (0);
}

int	valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == 'R')
		return (1);
	return (0);
}

void	check_door(char **map, int i, int j)
{
	if (i == 0 || !map[i + 1] || j == 0 || !map[i][j + 1])
	{
		ft_putstr_fd("Error : Door not closed\n", 2);
		exit(EXIT_FAILURE);
	}
	if ((map[i][j - 1] == '1' && map[i][j + 1] == '1') ||
		(map[i + 1][j] == '1' && map[i - 1][j] == '1'))
		return ;
	else
	{
		ft_putstr_fd("Error : Door not closed\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	empty_line(t_data *data, int i)
{
	if (!ft_strcmp(data->files->file[i], "*"))
	{
		ft_putstr_fd("Error : Invalid line in map.\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	invalid_char(t_data *data, int i)
{
	int	j;

	j = 0;
	while (data->files->file[i][j])
	{
		if (!is_valid(data->files->file[i][j]))
		{
			ft_putstr_fd("Error : Invalid char in map\n", 2);
			exit(EXIT_FAILURE);
		}
		j++;
	}
}
