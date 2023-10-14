/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:04:57 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/14 10:19:51 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_coma(char *s)
{
	int	i;
	int	error;
	int	count;

	i = 0;
	error = 0;
	count = 0;
	while (s[i])
	{
		if (i > 0 && s[i - 1] == ',' && s[i] == ',')
			error += 1;
		if (s[i] == ',')
			count += 1;
		if (s[i] == ',' && s[i + 1] == '\0')
			error += 1;
		i++;
	}
	if (count != 2 || error != 0)
	{
		ft_putstr_fd("Error: coma!\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	split_rgb(t_color *color, char *str, int i)
{
	if (i == 0)
		color->r = ft_new_atoi(str);
	else if (i == 1)
		color->g = ft_new_atoi(str);
	else if (i == 2)
		color->b = ft_new_atoi(str);
}

void	joinc(t_data *data, int i)
{
	data->files->file[i] = ft_strtrim(data->files->file[i], " \t");
	{
		data->files->clr = ft_strjoin(data->files->clr,
				data->files->file[i]);
		data->files->clr = ft_strjoin(data->files->clr, "\n");
	}
}

int	is_color(char *s)
{
	while (*s == ' ' || *s == '\t')
		s++;
	if (*s == 'F' || *s == 'C')
		return (1);
	return (0);
}
