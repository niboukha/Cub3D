/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:43:10 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/12 10:32:46 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_coma(char *s)
{
	int i;
	int error;
	int count;

	i = 0;
	error = 0;
	count = 0;
	while (s[i])
	{
		if (i > 0 && s[i - 1] == ',' && s[i] == ',')
			error += 1;
		if (s[i] == ',')
			count += 1;
		i++;
	}
	if (count != 2 || error != 0)
	{
		ft_putstr_fd("Error: coma!\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	split_digits(t_data *data, char *numbers, char c)
{
	char **str;
	char **tmp;
	int i;

	i = 0;
	str = ft_split(numbers, ',');
	free(numbers);
	while(i < 3)
	{
		str[i] = ft_strtrim(str[i], " \t");
		tmp = ft_split(str[i], ' ');
		if (tmp[1])
		{
			ft_putstr_fd("Check spaces\n", 2);
			free_string(tmp);
			exit(EXIT_FAILURE);
		}
		if (c == 'F')
		{
			if (i == 0)
				data->c_c->f->r = ft_new_atoi(str[i]);
			else if (i == 1)
				data->c_c->f->g = ft_new_atoi(str[i]);
			else if (i == 2)
				data->c_c->f->b = ft_new_atoi(str[i]);
		}
		else if (c == 'C')
		{
			if (i == 0)
				data->c_c->c->r = ft_new_atoi(str[i]);
			else if (i == 1)
				data->c_c->c->g = ft_new_atoi(str[i]);
			else if (i == 2)
				data->c_c->c->b = ft_new_atoi(str[i]);
		}
		free_string(tmp);
		i++;
	}
	free_string(str);
}

void	fill_colors(t_data *data, char **lines)
{
	int i;
	char c;
	int j;
	
	j = 0;
	data->c_c = malloc(sizeof(t_c_c));
	if (!data->c_c)
	{
		ft_putstr_fd("Error: Memory allocation failed for colors.\n", 2);
		exit(EXIT_FAILURE);
	}
	data->c_c->f = malloc(sizeof(t_color));
	data->c_c->c = malloc(sizeof(t_color));
	if (!data->c_c->f || !data->c_c->c)
	{
		ft_putstr_fd("Error: Memory allocation failed for color components.\n",
						2);
		free_colors(data->c_c);
		exit(EXIT_FAILURE);
	}
	while (j < 2)
	{
		lines[j] = ft_strtrim(lines[j], " \t");
		if (!ft_strncmp(lines[j], "F ", 2) || !ft_strncmp(lines[j], "C ", 2))
		{
			check_coma(lines[j]);
			if (!ft_strncmp(lines[j], "F ", 2))
				c = 'F';
			else if(!ft_strncmp(lines[j], "C ", 2))
				c = 'C';
			i = 0;
			while(lines[j][i])
			{
				if (ft_isdigit(lines[j][i]))
					break ;
				i++;
			}
			split_digits(data, ft_substr(lines[j], i, ft_strlen(lines[j]) - 1), c);
		}
		else if (!ft_strncmp(lines[j], "F ", 2) || !ft_strncmp(lines[j], "C ", 2))
		{
			check_coma(lines[j]);
			if (!ft_strncmp(lines[j], "F ", 2))
				c = 'F';
			else if(!ft_strncmp(lines[j], "C ", 2))
				c = 'C';
			i = 0;
			while(lines[j][i])
			{
				if (ft_isdigit(lines[j][i]))
					break ;
				i++;
			}
			split_digits(data, ft_substr(lines[j], i, ft_strlen(lines[j]) - 1), c);
		}
		j++;
	}
}

int	check_colors(t_data *data)
{
	char	**lines;
	int		i;

	lines = ft_split(data->files->clr, '\n');
	i = 0;
	while (lines[i])
		i++;
	if (i != 2)
	{
		free_string(lines);
		return (1);
	}
	fill_colors(data, lines);
	free_string(lines);
	if ((data->c_c->f->r < 0 || data->c_c->f->r > 255)
			|| (data->c_c->c->r < 0 || data->c_c->c->r > 255))
		return (1);
	else if ((data->c_c->f->g < 0 || data->c_c->f->g > 255)
			|| (data->c_c->c->g < 0 || data->c_c->c->g > 255))
		return (1);
	else if ((data->c_c->f->b < 0 || data->c_c->f->b > 255)
			|| (data->c_c->c->b < 0 || data->c_c->c->b > 255))
		return (1);
	return (0);
}