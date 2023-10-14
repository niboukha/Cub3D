/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:26:05 by  m-boukel         #+#    #+#             */
/*   Updated: 2023/10/14 10:05:10 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

char	*ft_strchr_get_next_line(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&str[i]);
	return (0);
}

int	strlen_get_next_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr_get_next_line(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*p;

	i = -1;
	j = 0;
	if (start > (unsigned int)strlen_get_next_line(s))
		len = 0;
	else if (strlen_get_next_line(s) - start < len)
		len = strlen_get_next_line(s) - start;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (s[++i])
	{
		if (i >= start && j < len)
		{
			p[j] = s[i];
			j++;
		}
	}
	free(s);
	p[j] = '\0';
	return (p);
}

char	*ft_strjoin_get_next_line(char *s1, char *s2)
{
	char	*p;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	len = strlen_get_next_line(s1) + strlen_get_next_line(s2);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (i < len && s1[j])
		p[i++] = s1[j++];
	j = 0;
	while (i < len && s2[j])
		p[i++] = s2[j++];
	p[i] = '\0';
	return (free(s1), p);
}
