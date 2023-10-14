/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:05:13 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/14 10:04:29 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	emty_file(t_data *data)
{
	if (!data->files->file[0])
	{
		ft_putstr_fd("Error : Emty File.\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	fill_map(t_data *data, int i)
{
	while (data->files->file[i])
	{
		empty_line(data, i);
		invalid_char(data, i);
		if (valid_line(data->files->file[i]))
			joinm(data, i);
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
	return (i);
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
		emty_file(data);
		while (data->files->file[i])
		{
			if (is_texture(data, i))
				joint(data, i);
			else if (is_color(data->files->file[i]))
				joinc(data, i);
			else if (!is_map(data->files->file[i]))
			{
				i = fill_map(data, i);
				i--;
			}
			i++;
		}
	}
}
