/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 18:01:09 by oposhiva          #+#    #+#             */
/*   Updated: 2017/06/04 18:01:10 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*one_argument(char *str, int quantity, t_bonus *bonus, int i)
{
	char	*dop;
	char	*point;
	char	**temp;
	int		amount;
	int		*mass;

	dop = ft_strjoin("# ", str);
	point = dop;
	temp = ft_strsplit(dop, ' ');
	while (*(++dop))
		if (*dop != ' ' && (*(dop + 1) == ' ' || *(dop + 1) == '\0'))
			quantity++;
	amount = flags_check(quantity, temp, bonus, i);
	if ((amount - quantity) == -1 && amount > 0)
		usage(i);
	check_args(amount, quantity + 1, temp);
	mass = (int*)malloc(sizeof(int) * (quantity - amount) + 1);
	mass = fill_mass(mass, temp, quantity + 1, amount + 1);
	double_check(mass, quantity - amount);
	amount = -1;
	while (++amount <= quantity)
		free(temp[amount]);
	free(temp);
	free(point);
	return (mass);
}
