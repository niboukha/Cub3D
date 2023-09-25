/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:04:16 by m-boukel          #+#    #+#             */
/*   Updated: 2023/09/25 20:53:00 by niboukha         ###   ########.fr       */
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
	read_file(&data, fd);
	split_file(&data);
	if (check_Deriction(&data))
	{
		ft_putstr_fd("Error : Deriction not valid\n", 2);
		// sould free data->deriction
		return (0);
	}
	if (check_colors(&data))
	{
		ft_putstr_fd("Error : Colors not valid\n", 2);
		// sould free data->Clr
		return (0);
	}
	check_map(&data);
	// for(int i = 0; i < 1; i++)
	// 	printf("%s\n", data.files->D);
	// for(int i = 0; i < 1; i++)
	// 	printf("%s\n", data.files->Clr);
	// for(int i = 0; i < 1; i++)
	// 	printf("%s\n", data.files->map);
	return (0);
}
