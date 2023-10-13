/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xshel <xshel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:00:56 by xshel             #+#    #+#             */
/*   Updated: 2023/10/13 12:53:09 by xshel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	joinm(t_data *data, int i)
{
	data->files->map = ft_strjoin(data->files->map,
			data->files->file[i]);
	data->files->map = ft_strjoin(data->files->map, "\n");
}
