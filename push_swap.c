/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 12:56:03 by oposhiva          #+#    #+#             */
/*   Updated: 2017/04/16 12:56:03 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack	*stack;
	t_bonus	bonus;

	if (argc < 2)
		usage(0);
	stack = fill_stack(argc, argv, &bonus, 0);
	algorithm_basis(stack, &bonus);
	return (0);
}
