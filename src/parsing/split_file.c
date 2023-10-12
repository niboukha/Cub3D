/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:05:13 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/12 10:34:42 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_color(char *s)
{
	while (*s == ' ' || *s == '\t')
		s++;
	if (*s == 'F' || *s == 'C')
			return (1);
	return (0);
}

static int	valid_line(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!is_valid(s[i]))
			return (0);
		i++;
	}
	return (1);
}

void	split_file(t_data *data)
{
	int	i;

	data->files->d = NULL;
	data->files->clr = NULL;
	data->files->map = NULL;
	i = 0;
	if (data->files->file)
	{
		if (!data->files->file[0])
		{
			ft_putstr_fd("Error : Emty File.\n", 2);
			exit(EXIT_FAILURE);
		}
		while (data->files->file[i])
		{
			if (ft_strncmp(data->files->file[i], "NO ", 3) == 0
				|| ft_strncmp(data->files->file[i], "EA ", 3) == 0
				|| ft_strncmp(data->files->file[i], "WE ", 3) == 0
				|| ft_strncmp(data->files->file[i], "SO ", 3) == 0)
			{
				data->files->file[i] = ft_strtrim(data->files->file[i], " \t");
				data->files->d = ft_strjoin(data->files->d,
											data->files->file[i]);
				data->files->d = ft_strjoin(data->files->d, "\n");
			}
			else if (is_color(data->files->file[i]))
			{
				data->files->file[i] = ft_strtrim(data->files->file[i], " \t");
				if (ft_strncmp(data->files->file[i], "F ", 2) == 0
						|| ft_strncmp(data->files->file[i], "C ", 2) == 0)
				{
					data->files->clr = ft_strjoin(data->files->clr,
													data->files->file[i]);
					data->files->clr = ft_strjoin(data->files->clr, "\n");
				}
			}
			else if (!is_map(data->files->file[i]))
			{
				while (data->files->file[i])
				{
					if (!ft_strcmp(data->files->file[i], "*"))
					{
						ft_putstr_fd("Error : Invalid line in map1\n", 2);
						exit(EXIT_FAILURE);
					}
					if (valid_line(data->files->file[i]))
					{
						data->files->map = ft_strjoin(data->files->map,
														data->files->file[i]);
						data->files->map = ft_strjoin(data->files->map, "\n");
					}
					else
					{
						if (!data->files->file[i + 1])
							break ;
						else if (data->files->file[i + 1]
								&& !valid_line(data->files->file[i + 1]))
						{
							ft_putstr_fd("Error : Invalid line in map.\n", 2);
							exit(EXIT_FAILURE);
						}
					}
					i++;
				}
				i--;
			}
			
			i++;
		}
	}
}