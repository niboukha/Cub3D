/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:03:18 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/14 10:04:15 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_valid(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == ' ' || c == 'R')
		return (1);
	return (0);
}

int	is_map(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (!is_valid(buffer[i]))
			return (1);
		i++;
	}
	return (0);
}
