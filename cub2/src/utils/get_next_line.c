/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:15:34 by m-boukel          #+#    #+#             */
/*   Updated: 2023/09/03 13:16:00 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


char	*first_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str || !str[0])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i])
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*next_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	str = ft_substr(str, i + 1, ft_strlen(str) - i - 1);
	return (str);
}

char	*rest(int fd, char *str)
{
	char	*buff;
	int		rb;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (str && ft_strchr(str, '\n'))
	{
		free(buff);
		return (str);
	}
	*buff = '\0';
	rb = 1;
	while (rb && (!str || !ft_strchr(str, '\n')))
	{
		rb = read(fd, buff, BUFFER_SIZE);
		if (rb < 0)
			return (free(buff), NULL);
		buff[rb] = '\0';
		str = ft_strjoin(str, buff);
		if (!str)
			return (NULL);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = rest(fd, str);
	if (!str)
		return (NULL);
	line = first_line(str);
	str = next_line(str);
	return (line);
}