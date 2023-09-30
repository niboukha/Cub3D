/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 03:34:30 by m-boukel          #+#    #+#             */
/*   Updated: 2023/09/30 09:54:30 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


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
	return (0);
}