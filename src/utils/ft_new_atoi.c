/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:05:02 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/14 10:05:05 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_cara(char *s, int j)
{
	while (s[j])
	{
		if (!(s[j] >= '0' && s[j] <= '9') && s[j] != ',')
		{
			ft_putstr_fd("Error : exist of another char\n", 2);
			exit(1);
		}
		j++;
	}
}

int	ft_new_atoi(char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] && str[i] <= 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	check_cara(str, i);
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - 48;
	if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
	{
		write(2, "Error\n", 7);
		exit(1);
	}
	return (result * sign);
}
