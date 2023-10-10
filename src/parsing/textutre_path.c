/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textutre_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xshel <xshel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 21:06:36 by xshel             #+#    #+#             */
/*   Updated: 2023/10/10 19:44:32 by xshel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_ps(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.' && s[i + 1] == '/' && ft_isalpha(s[i + 2]))
			return (1);
		i++;
	}
	return (0);
}

int	check_texture_path(t_data *data)
{
	int		i;
	char	c;
	int		j;
	char 	**tmp;
	int		flag;

	tmp = NULL;
	flag = 0;
	data->files->d_spl = ft_split(data->files->d, '\n');
	i = 0;
	while (data->files->d_spl[i])
	{
		j = 0;
		while (data->files->d_spl[i][j])
		{
			if (data->files->d_spl[i][j] == ' ' || data->files->d_spl[i][j] == '\t')
			{
				c = data->files->d_spl[i][j];
				break ;
			}
			j++;
		}
		tmp = ft_split(data->files->d_spl[i], c);
		if (ft_strcmp(tmp[0], "NO") == 0 || ft_strcmp(tmp[0], "SO") == 0 ||
			ft_strcmp(tmp[0], "WE") == 0 || ft_strcmp(tmp[0], "EA") == 0)
		{
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
			if (open(tmp[1], O_RDONLY) == -1 )
				flag += 1;
		}
		free_string(tmp);
		i++;
	}
	if (flag != 0)
		return 1;
	return (0);
}
