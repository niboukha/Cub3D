/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:20:43 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/07 20:10:01 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int    check_char(char c)
{
    if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == 'R')
        return (1);
    return (0);
}

int valid_char(char c)
{
    if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == 'R')
        return (1);
    return (0);
}
void    check_map(t_data *data)
{
    char **map;
    int i;
    int j;

    if (!data->files->map)
    {
        ft_putstr_fd("Error : No map\n", 2);
        exit(EXIT_FAILURE);
    }
    map = ft_split(data->files->map, '\n');
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (!valid_char(map[i][j]) && map[i][j] != ' ')
            {
                ft_putstr_fd("Error : Invalid char in map\n", 2);
                exit(EXIT_FAILURE);
            }
            if (check_char(map[i][j]))
            {
                if (i == 0 && map[i][j] != '1')
                {
                    ft_putstr_fd("Error : Map not closed\n", 2);
                    exit(EXIT_FAILURE);
                }
                if (!map[i + 1] && (map[i][j] != '1' && map[i][j] != ' '))
                {
                    ft_putstr_fd("Error : Map not closed\n", 2);
                    exit(EXIT_FAILURE);
                }
                if (!valid_char(map[i][j + 1]) || !valid_char(map[i][j - 1]) || !valid_char(map[i + 1][j]) || !valid_char(map[i - 1][j]))
                {
                    ft_putstr_fd("Error : Map not closed\n", 2);
                    exit(EXIT_FAILURE);
                }
            }
            j++;
        }
        i++;
    }
}
