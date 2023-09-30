/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:43:10 by m-boukel          #+#    #+#             */
/*   Updated: 2023/09/30 12:51:09 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


void    fill_colors(t_data *data, char **lines)
{
    int j;
    
    data->c_c = malloc(sizeof(t_c_c));
    data->c_c->f = malloc(sizeof(t_color));
    data->c_c->c = malloc(sizeof(t_color));
    data->c_c->floor = 0;
    data->c_c->ceiling = 0;
    data->c_c->f->error = 0;
    data->c_c->c->error = 0;
    if (ft_strncmp(lines[0], "F ", 2) == 0)
    {
        j = 0;
        while (lines[0][j])
        {
            if (lines[0][j] == ',')
                data->c_c->f->error += 1;
            j++;
        }
        printf("error : %d\n", data->c_c->f->error);
        if (data->c_c->f->error != 2)
        {
            ft_putstr_fd("Error : Invalid color\n", 2);
            exit(EXIT_FAILURE);
        }
        data->c_c->floor += 1;
        data->c_c->f->r = ft_new_atoi(lines[0] + 2);
        data->c_c->f->g = ft_new_atoi(ft_strchr(lines[0] + 2, ',') + 1);
        data->c_c->f->b = ft_new_atoi(ft_strchr(ft_strchr(lines[0] + 2, ',') + 1, ',') + 1);
    }
    else if (ft_strncmp(lines[1], "F ", 2) == 0)
    {
        j = 0;
        while (lines[1][j])
        {
            if (lines[1][j] == ',')
                data->c_c->f->error += 1;
            j++;
        }
        if (data->c_c->f->error != 2)
        {
            ft_putstr_fd("Error : Invalid color\n", 2);
            exit(EXIT_FAILURE);
        }
        data->c_c->floor += 1;
        data->c_c->f->r = ft_new_atoi(lines[1] + 2);
        data->c_c->f->g = ft_new_atoi(ft_strchr(lines[1] + 2, ',') + 1);
        data->c_c->f->b = ft_new_atoi(ft_strchr(ft_strchr(lines[1] + 2, ',') + 1, ',') + 1);
    }
    if (ft_strncmp(lines[0], "C ", 2) == 0)
    {
        j = 0;
        while (lines[0][j])
        {
            if (lines[0][j] == ',')
                data->c_c->c->error += 1;
            j++;
        }
        if (data->c_c->c->error != 2)
        {
            ft_putstr_fd("Error : Invalid color\n", 2);
            exit(EXIT_FAILURE);
        }
        data->c_c->ceiling += 1;
        data->c_c->c->r = ft_new_atoi(lines[0] + 2);
        data->c_c->c->g = ft_new_atoi(ft_strchr(lines[0] + 2, ',') + 1);
        data->c_c->c->b = ft_new_atoi(ft_strchr(ft_strchr(lines[0] + 2, ',') + 1, ',') + 1);
    }
    else if (ft_strncmp(lines[1], "C ", 2) == 0)
    {
        j = 0;
        while (lines[1][j])
        {
            if (lines[1][j] == ',')
                data->c_c->c->error += 1;
            j++;
        }
        if (data->c_c->c->error != 2)
        {
            ft_putstr_fd("Error : Invalid color\n", 2);
            exit(EXIT_FAILURE);
        }
        data->c_c->ceiling += 1;
        data->c_c->c->r = ft_new_atoi(lines[1] + 2);
        data->c_c->c->g = ft_new_atoi(ft_strchr(lines[1] + 2, ',') + 1);
        data->c_c->c->b = ft_new_atoi(ft_strchr(ft_strchr(lines[1] + 2, ',') + 1, ',') + 1);
    }
    printf("floor : %d\n", data->c_c->floor);
    printf("ceiling : %d\n", data->c_c->ceiling);
    printf("error floor : %d\n", data->c_c->f->error);
    printf("error ceiling : %d\n", data->c_c->c->error);
    
}

int     check_colors(t_data *data)
{
    char    **lines;
    char    **str;
    int     i;

    i = 0;
    str = ft_split(data->files->clr, ' ');
    while (str[i])      
        i++;
    if (i != 3)
        return (1);
    lines = ft_split(data->files->clr, '\n');
    i = 0;
    while (lines[i])
    {
        i++;
    }
    if (i != 2)
        return (1);
    // printf("1\n");
    fill_colors(data, lines);
    if (data->c_c->floor != 1 || data->c_c->ceiling != 1)
        return (1);
    else if ((data->c_c->f->r < 0 || data->c_c->f->r > 255) || (data->c_c->c->r < 0 || data->c_c->c->r > 255))
        return (1);
    else if ((data->c_c->f->g < 0 || data->c_c->f->g > 255) || (data->c_c->c->g < 0 || data->c_c->c->g > 255))
        return (1);
    else if ((data->c_c->f->b < 0 || data->c_c->f->b > 255) || (data->c_c->c->b < 0 || data->c_c->c->b > 255))
        return (1);
    else if (data->c_c->f->error != 2 || data->c_c->c->error != 2)
        return (1);
    return (0);
}
