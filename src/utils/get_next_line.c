/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:19:01 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/08 16:28:40 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

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
	str = ft_substr_get_next_line(str, i + 1, strlen_get_next_line(str) - i
			- 1);
	return (str);
}

char	*rest(int fd, char *str)
{
	char	*buff;
	int		rb;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	if (str && ft_strchr_get_next_line(str, '\n'))
	{
		free(buff);
		return (str);
	}
	*buff = '\0';
	rb = 1;
	while (rb && (!str || !ft_strchr_get_next_line(str, '\n')))
	{
		rb = read(fd, buff, BUFFER_SIZE);
		if (rb < 0)
			return (free(buff), NULL);
		buff[rb] = '\0';
		str = ft_strjoin_get_next_line(str, buff);
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
