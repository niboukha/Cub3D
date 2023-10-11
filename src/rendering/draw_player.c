/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:15:31 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/10 18:46:38 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	*routine(void *ptr)
{
    t_map   *map;
    
    map = (t_map *)ptr;
    while (1)
    {
        usleep(50000);
        pthread_mutex_lock(&map->mut);
        map->index++;
        pthread_mutex_unlock(&map->mut);
        if (map->index > 4)
        {
            map->index = 0;
            break;
        }
    }
    return (NULL);
}


void    animation_gun(t_map *map, int key_code)
{
    pthread_t	th;
    
    if (key_code == SPACE)
    {
        if (pthread_create(&th, NULL, routine, map) == -1)
            exit(1);
    }
    
}
