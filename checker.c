/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheaker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 14:18:09 by oposhiva          #+#    #+#             */
/*   Updated: 2017/04/05 14:18:10 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack *stack;
	t_bonus bonus;

	if (argc < 2)
		usage(1);
	stack = fill_stack(argc, argv, &bonus, 1);
	follow_instructions(stack, &bonus, 0);
	return (0);
}
