/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:13:29 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/12 11:02:38 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	read_file(t_data *data, int fd)
{
	char	*str_file;
	char	*buffer;

	str_file = NULL;
	data->files = malloc(sizeof(t_files));
	buffer = get_next_line(fd);
	if (!buffer)
		buffer = ft_strdup("");
	while (buffer)
	{
		if (ft_strlen(buffer) == 1)
		{
			free(buffer);
			buffer = ft_strdup("*\n");
		}
		str_file = ft_strjoin(str_file, buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	// printf("%s\n", str_file);
	// printf("dkhel\n");
	data->files->file = ft_split(str_file, '\n');
	free(str_file);
}