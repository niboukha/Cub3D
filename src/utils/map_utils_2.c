/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:05:20 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/14 10:05:23 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	joinm(t_data *data, int i)
{
	data->files->map = ft_strjoin(data->files->map,
			data->files->file[i]);
	data->files->map = ft_strjoin(data->files->map, "\n");
}
