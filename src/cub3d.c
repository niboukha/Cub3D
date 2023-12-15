/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:44:53 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/15 11:22:50 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_hidden_file(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] == '/' && s[i + 1] == '.')
			|| (s[i] == '.' && !ft_isalpha(s[i + 1])))
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	t_map	*map;
	t_data	data;

	map = malloc(sizeof(t_map));
	data.files = malloc(sizeof(t_files));
	if (ac != 2 || ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4)
		|| check_hidden_file(av[1]))
	{
		ft_putstr_fd("Error : file name\n", 2);
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
