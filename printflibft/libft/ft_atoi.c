/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 16:00:22 by oposhiva          #+#    #+#             */
/*   Updated: 2016/11/27 16:00:23 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int		ft_atoi(const char *str)
{
	long int		i;
	long int		j;

	i = 0;
	j = 0;
	while (*str == ' ' || *str == '\t' || *str == '\v' ||
	*str == '\n' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
		j = 1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		i = i * 10 + (int)(*str - '0');
		str++;
	}
	if (j == 1)
		return (-i);
	return (i);
}
