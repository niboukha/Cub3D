/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 03:34:30 by m-boukel          #+#    #+#             */
/*   Updated: 2023/09/26 04:05:25 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


int    parsing(t_data data, int fd)
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
    data.files->map_splited = ft_split(data.files->map, '\n');
    return (0);
}