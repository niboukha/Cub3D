/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textutre_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:04:44 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/14 10:19:42 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_ps(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.' && s[i + 1] == '/' && ft_isalpha(s[i + 2]))
			return (1);
		i++;
	}
	return (0);
}

char	split_tab_or_space(char *s)
{
	int		j;
	char	c;

	j = 0;
	c = '\0';
	while (s[j])
	{
		if (s[j] == ' ' || s[j] == '\t')
		{
			c = s[j];
			break ;
		}
		j++;
	}
	return (c);
}

int	direction_name(t_data *data, char **tmp)
{
	int	flag;

	flag = 0;
	if (ft_strcmp(tmp[0], "NO") == 0 || ft_strcmp(tmp[0], "SO") == 0
		|| ft_strcmp(tmp[0], "WE") == 0 || ft_strcmp(tmp[0], "EA") == 0)
	{
		check_empty_path(tmp);
		if (ft_strcmp(tmp[0], "NO") == 0)
			data->files->texture._no = ft_strdup(tmp[1]);
		else if (ft_strcmp(tmp[0], "SO") == 0)
			data->files->texture._so = ft_strdup(tmp[1]);
		else if (ft_strcmp(tmp[0], "WE") == 0)
			data->files->texture._we = ft_strdup(tmp[1]);
		else if (ft_strcmp(tmp[0], "EA") == 0)
			data->files->texture._ea = ft_strdup(tmp[1]);
		if (!check_ps(tmp[1]))
		{
			ft_putstr_fd("Error : Texture path not valid\n", 2);
			exit(1);
		}
		if (open(tmp[1], O_RDONLY) == -1)
			flag += 1;
	}
	return (flag);
}

int	check_texture_path(t_data *data)
{
	int		i;
	char	c;
	char	**tmp;
	int		flag;

	tmp = NULL;
	flag = 0;
	data->files->d_spl = ft_split(data->files->d, '\n');
	if (check_split_count(data->files->d_spl, 4))
	{
		ft_putstr_fd("Error : Texture path not valid1\n", 2);
		exit(1);
	}
	i = 0;
	while (data->files->d_spl[i])
	{
		c = split_tab_or_space(data->files->d_spl[i]);
		tmp = ft_split(data->files->d_spl[i], c);
		flag += direction_name(data, tmp);
		free_string(tmp);
		i++;
	}
	if (flag != 0)
		return (1);
	return (0);
}
