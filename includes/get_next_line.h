/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:15:25 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/14 10:19:00 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337

# endif

char	*get_next_line(int fd);
char	*ft_strchr_get_next_line(char *str, int c);
char	*ft_substr_get_next_line(char *s, unsigned int start, size_t len);
int		strlen_get_next_line(char *str);
char	*ft_strjoin_get_next_line(char *s1, char *s2);

#endif