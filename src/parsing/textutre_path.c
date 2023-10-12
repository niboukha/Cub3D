/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textutre_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 21:06:36 by xshel             #+#    #+#             */
/*   Updated: 2023/10/11 10:14:55 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


int    check_texture_path(t_data *data)
{
    int i;
    int flag;
    
    i = 0;
    char **tmp;
    flag = 0;
    tmp = NULL;
    data->files->d_spl = ft_split(data->files->d, '\n');
    while (data->files->d_spl[i])
    {
        tmp = ft_split(data->files->d_spl[i], ' ');
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
            if (open(tmp[1], O_RDONLY) == -1)
                flag += 1;       
        }
        free(tmp[0]);
        free(tmp[1]);
        free(tmp);
        i++;
    }
    if (!flag)
        return (1);
    return 0;
}