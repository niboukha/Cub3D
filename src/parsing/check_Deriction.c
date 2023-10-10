/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_Deriction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xshel <xshel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:21:10 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/10 13:15:55 by xshel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	fill_deriction(t_data *data, char **str)
{
	int	i;

	i = 0;
	data->deriction = malloc(sizeof(t_deriction));
	data->deriction->no = 0;
	data->deriction->so = 0;
	data->deriction->we = 0;
	data->deriction->ea = 0;
	while (str[i])
	{
		if (str[i][0] == 'N' && str[i][1] == 'O')
			data->deriction->no = 1;
		else if (str[i][0] == 'S' && str[i][1] == 'O')
			data->deriction->so = 1;
		else if (str[i][0] == 'W' && str[i][1] == 'E')
			data->deriction->we = 1;
		else if (str[i][0] == 'E' && str[i][1] == 'A')
			data->deriction->ea = 1;
		i++;
	}
}

int	check_Deriction(t_data *data)
{
	char **str;
	char **tmp;
	int i;
	int j;

	i = 0;
	str = ft_split(data->files->d, '\n');

	while (str[i])
		i++;
	if (i > 4)
	{
		free_string(str);
		return (1);
	}
	fill_deriction(data, str);

	if (!(data->deriction->no == 1 && data->deriction->so == 1
			&& data->deriction->we == 1 && data->deriction->ea == 1))
	{
		free_string(str);
		free(data->deriction);
		return (1);
	}

	i = 0;
	while (str[i])
	{
		j = 0;
		tmp = ft_split(str[i], ' ');
		while (tmp[j])
			j++;
		free_string(tmp);
		if (j != 2)
		{
			free_string(str);
			free(data->deriction);
			return (1);
		}
		i++;
	}
	free_string(str);
	return (0);
}