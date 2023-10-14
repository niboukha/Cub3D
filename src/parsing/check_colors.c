/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:03:53 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/14 10:19:33 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	split_digits(t_data *data, char *numbers, char c)
{
	char	**str;
	char	**tmp;
	int		i;

	i = 0;
	str = ft_split(numbers, ',');
	free(numbers);
	while (i < 3)
	{
		str[i] = ft_strtrim(str[i], " \t");
		tmp = ft_split(str[i], ' ');
		if (tmp[1])
		{
			ft_putstr_fd("Color error : Check spaces\n", 2);
			free_string(tmp);
			exit(EXIT_FAILURE);
		}
		if (c == 'F')
			split_rgb(data->c_c->f, str[i], i);
		else if (c == 'C')
			split_rgb(data->c_c->c, str[i], i);
		free_string(tmp);
		i++;
	}
	free_string(str);
}

void	initialize_color_components(t_c_c *c_c)
{
	c_c->f = malloc(sizeof(t_color));
	c_c->c = malloc(sizeof(t_color));
	if (!c_c->f || !c_c->c)
	{
		ft_putstr_fd("Error: Memory allocation failed for color components.\n",
			2);
		exit(EXIT_FAILURE);
	}
}

void	parse_and_split_color(t_data *data, char *line, char c)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
			break ;
		i++;
	}
	split_digits(data, ft_substr(line, i, ft_strlen(line) - 1), c);
}

void	fill_colors(t_data *data, char **lines)
{
	int		j;
	char	c;

	j = 0;
	data->c_c = malloc(sizeof(t_c_c));
	if (!data->c_c)
	{
		ft_putstr_fd("Error: Memory allocation failed for colors.\n", 2);
		exit(EXIT_FAILURE);
	}
	initialize_color_components(data->c_c);
	while (j < 2)
	{
		lines[j] = ft_strtrim(lines[j], " \t");
		if (!ft_strncmp(lines[j], "F ", 2) || !ft_strncmp(lines[j], "C ", 2))
		{
			check_coma(lines[j]);
			if (!ft_strncmp(lines[j], "F ", 2))
				c = 'F';
			else if (!ft_strncmp(lines[j], "C ", 2))
				c = 'C';
			parse_and_split_color(data, lines[j], c);
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
		return (free_string(lines), 1);
	fill_colors(data, lines);
	free_string(lines);
	if ((data->c_c->f->r < 0 || data->c_c->f->r > 255) || (data->c_c->c->r < 0
			|| data->c_c->c->r > 255))
		return (1);
	else if ((data->c_c->f->g < 0 || data->c_c->f->g > 255)
		|| (data->c_c->c->g < 0 || data->c_c->c->g > 255))
		return (1);
	else if ((data->c_c->f->b < 0 || data->c_c->f->b > 255)
		|| (data->c_c->c->b < 0 || data->c_c->c->b > 255))
		return (1);
	return (0);
}
