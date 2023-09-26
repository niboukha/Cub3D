/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:04:16 by m-boukel          #+#    #+#             */
/*   Updated: 2023/09/26 03:48:00 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	int		fd;
	t_data	data;

	data.files = malloc(sizeof(t_files));
	if (ac != 2 || ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
		return (ft_putstr_fd("Error : file name", 2), 0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (perror("Error"), 0);
	if (parsing(data, fd) == 1)
		return (0);
	return (0);
}
