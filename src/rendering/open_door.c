/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:47:59 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/12 14:53:07 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void    open_door(t_map *map, int )
// {
//     if (map->coor.d <= 174)
//     {	
//         if (check_door(map, map->wall.h_x, map->wall.h_y, 2) == 1)
//         {
//             if (map->map[(int)map->wall.h_y / 64 - 1][(int)map->wall.h_x / 64] == 'R')
//             {
//                 map->map[(int)map->wall.h_y / 64 - 1][(int)map->wall.h_x / 64] = '0';
//                 map->dr.x = (int)map->wall.h_x / 64;
//                 map->dr.y = (int)map->wall.h_y / 64 - 1;
//             }
//             else if (map->map[(int)map->wall.h_y / 64][(int)map->wall.h_x / 64] == 'R')
//             {
//                 map->map[(int)map->wall.h_y / 64][(int)map->wall.h_x / 64] = '0';					
//                 map->dr.x = (int)map->wall.h_x / 64;
//                 map->dr.y = (int)map->wall.h_y / 64;
//             }
//             map->coor.flag_a = 0;
//         }
//     }
// }
