/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 13:16:23 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/13 17:41:19 by niboukha         ###   ########.fr       */
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
int     strlen_get_next_line(char *str);
char	*ft_strjoin_get_next_line(char *s1, char *s2);

#endif