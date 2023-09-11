/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:19:36 by niboukha          #+#    #+#             */
/*   Updated: 2023/09/11 15:28:40 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <mlx.h>
#include <stdlib.h
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct t_coor
{
	int	x;
	int	y;

}		t_coor;


typedef struct t_map
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	t_coord	*coor;
}			t_map;



#endif
