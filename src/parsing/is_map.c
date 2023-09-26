/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:03:18 by m-boukel          #+#    #+#             */
/*   Updated: 2023/09/14 12:10:40 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int is_valid(char c)
{
    if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == ' ')
        return (1);
    return (0);
}

static int valid_line(char c)
{
    if(is_valid(c))
        return (1);
    return (0);
}

int is_map(char *buffer)
{
    int i;

    i = 0;
    while (buffer[i])
    {
        if (!valid_line(buffer[i]) || !valid_line(buffer[i + 1]) || !valid_line(buffer[i + 2]))
            return (1);
        i++;
    }
    return (0);   
}