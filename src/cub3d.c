/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:04:16 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/14 10:06:14 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	int		fd;
	t_map	*map;
	t_data	data;

	map = malloc(sizeof(t_map));
	data.files = malloc(sizeof(t_files));
	if (ac != 2 || ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
	{
		ft_putstr_fd("Error : file name", 2);
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	if (parsing(&data, map, fd) == 1)
		return (0);
	map->data = &data;
	rendering(map);
	return (0);
}
