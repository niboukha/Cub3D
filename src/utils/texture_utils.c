/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:05:38 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/14 10:05:40 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	joint(t_data *data, int i)
{
	data->files->file[i] = ft_strtrim(data->files->file[i], " \t");
	data->files->d = ft_strjoin(data->files->d,
			data->files->file[i]);
	data->files->d = ft_strjoin(data->files->d, "\n");
}

int	is_texture(t_data *data, int i)
{
	int	j;

	j = 0;
	while (data->files->file[i][j] == ' ' || data->files->file[i][j] == '\t')
		j++;
	if ((data->files->file[i][j] == 'N' && data->files->file[i][j + 1] == 'O')
			|| (data->files->file[i][j] == 'S' && data->files->file[i][j
			+ 1] == 'O') || (data->files->file[i][j] == 'E'
			&& data->files->file[i][j + 1] == 'A')
			|| (data->files->file[i][j] == 'W' && data->files->file[i][j
			+ 1] == 'E'))
		return (1);
	return (0);
}

void	check_empty_path(char **tmp)
{
	if (!tmp[1])
	{
		ft_putstr_fd("Error : Emty texture path\n", 2);
		exit(EXIT_FAILURE);
	}
}
