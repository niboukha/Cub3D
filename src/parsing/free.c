/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xshel <xshel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:56:13 by xshel             #+#    #+#             */
/*   Updated: 2023/10/09 10:20:50 by xshel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_colors(t_c_c *colors)
{
	if (colors)
	{
		if (colors->f)
		{
			free(colors->f);
			colors->f = NULL;
		}
		if (colors->c)
		{
			free(colors->c);
			colors->c = NULL;
		}
		free(colors);
	}
}

void	free_d_spl(t_data *data)
{
	int	i;

	i = 0;
	if (data->files->d_spl)
	{
		while (data->files->d_spl[i])
		{
			free(data->files->d_spl[i]);
			i++;
		}
		free(data->files->d_spl);
		data->files->d_spl = NULL;
	}
}

void	free_deriction(t_data *data)
{
	if (data->deriction)
	{
		free(data->deriction);
		data->deriction = NULL;
	}
}
void	free_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->files->map_spl)
	{
		while (data->files->map_spl[i])
		{
			free(data->files->map_spl[i]);
			i++;
		}
		free(data->files->map_spl);
		data->files->map_spl = NULL;
	}
}

int	free_string(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (1);
}
void	free_files(t_data *data)
{
	free_colors(data->c_c);
	free_map(data);
	free_d_spl(data);
	if (data->files->d)
	{
		free(data->files->d);
		data->files->d = NULL;
		// Set the pointer to NULL after freeing to avoid double-free
	}
	if (data->files->clr)
	{
		free(data->files->clr);
		data->files->clr = NULL;
	}
	if (data->files->map)
	{
		free(data->files->map);
		data->files->map = NULL;
	}
	free(data->files->texture._no);
	free(data->files->texture._so);
	free(data->files->texture._we);
	free(data->files->texture._ea);
}

void	free_data(t_data *data)
{
	free_files(data);
	free_colors(data->c_c);
	free(data->deriction);
	free(data->files);
	free(data);
}