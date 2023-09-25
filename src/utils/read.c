/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:13:29 by m-boukel          #+#    #+#             */
/*   Updated: 2023/09/12 16:38:04 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void read_map(t_data *data, int fd)
// {
//     char	*str_map;
// 	char	*buffer;

// 	str_map = NULL;
// 	buffer = NULL;
// 	buffer = get_next_line(fd);
// 	if (!buffer)
// 	{
// 		ft_putstr_fd("EMPTY FILE!\n", 2);
// 		exit(1);
// 	}
// 	while (buffer)
// 	{
// 		if (ft_strlen(buffer) == 1)
// 		{
// 			ft_putstr_fd("EMPTY LINE!\n", 2);
// 			exit(EXIT_FAILURE);
// 		}
// 		str_map = ft_strjoin(str_map, buffer);
// 		free(buffer);
// 		buffer = get_next_line(fd);
// 	}
// 	data->map = ft_split(str_map, '\n');
// 	data->cmap = ft_split(str_map, '\n');
// 	free(str_map);
// }

void read_file(t_data *data, int fd)
{
    char	*str_file;
	char	*buffer;

	str_file = NULL;
	buffer = NULL;
    data->files = malloc(sizeof(t_files));
	buffer = get_next_line(fd);
	if (!buffer)
		buffer = ft_strdup("");
	while (buffer)
	{
        if (ft_strlen(buffer) == 1)
            buffer = ft_strdup("");
		str_file = ft_strjoin(str_file, buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	data->files->file = ft_split(str_file, '\n');
	free(str_file);
}
