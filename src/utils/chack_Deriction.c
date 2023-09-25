/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chack_Deriction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:21:10 by m-boukel          #+#    #+#             */
/*   Updated: 2023/09/13 11:41:48 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    fill_derictio(t_data *data, char **str)
{
    int i;

    i = 0;
    data->deriction = malloc(sizeof(t_deriction));
    data->deriction->NO = 0;
    data->deriction->SO = 0;
    data->deriction->WE = 0;
    data->deriction->EA = 0;
    while (str[i])
    {
        if (str[i][0] == 'N' && str[i][1] == 'O')
            data->deriction->NO = 1;
        else if (str[i][0] == 'S' && str[i][1] == 'O')
            data->deriction->SO = 1;
        else if (str[i][0] == 'W' && str[i][1] == 'E')
            data->deriction->WE = 1;
        else if (str[i][0] == 'E' && str[i][1] == 'A')
            data->deriction->EA = 1;
        i++;
    }
}

int    check_Deriction(t_data *data)
{
    char    **str;
    char    **tmp;
    int     i;
    int     j;

    i = 0;
    str = ft_split(data->files->D, '\n');
    while (str[i])
        i++;
    if (i > 4)
        return (1);
    i = 0;
    fill_derictio(data, str);
    if (!(data->deriction->NO == 1 && data->deriction->SO == 1 && data->deriction->WE == 1 && data->deriction->EA == 1))
        return (1);
    while (str[i])
    {
        j = 0;
        tmp = ft_split(str[i], ' ');
        while(tmp[j])
            j++;
        if (j != 2)
            return (1);
        i++;
    }
    return (0);
}