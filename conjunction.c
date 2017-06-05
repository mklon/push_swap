/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conjunction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:56:46 by oposhiva          #+#    #+#             */
/*   Updated: 2017/05/10 14:56:46 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	division_help_b(t_stack **stack_a, t_stack **stack_b, char **inst,
						int inst_num)
{
	if (inst_num == PA)
	{
		inst_p(stack_a, stack_b);
		instructions_recording(PA, inst);
	}
	else if (inst_num == RB)
	{
		inst_r(stack_b);
		instructions_recording(RB, inst);
	}
	else if (inst_num == RRB)
	{
		inst_rr(stack_b);
		instructions_recording(RRB, inst);
	}
}

int		division_part_of_b(t_stack **stack_a, t_stack **stack_b, char **inst,
							t_stack *end)
{
	int		median;
	int		new_len;
	int		rr_num;

	rr_num = 0;
	new_len = 0;
	median = small_search_median(*stack_b, end);
	while (bigger_then_median(*stack_b, median))
	{
		while ((*stack_b)->data >= median)
		{
			division_help_b(stack_a, stack_b, inst, PA);
			new_len++;
		}
		if (bigger_then_median(*stack_b, median))
		{
			division_help_b(stack_a, stack_b, inst, RB);
			rr_num++;
		}
	}
	while (--rr_num > -1)
		division_help_b(stack_a, stack_b, inst, RRB);
	return (new_len);
}

int		division_full_b(t_stack **stack_a, t_stack **stack_b, char **inst)
{
	int		median;
	int		new_len;

	new_len = 0;
	median = search_median(*stack_b);
	while (bigger_then_median(*stack_b, median))
	{
		while ((*stack_b)->data >= median)
		{
			inst_p(stack_a, stack_b);
			instructions_recording(PA, inst);
			new_len++;
		}
		if (bigger_then_median(*stack_b, median))
		{
			inst_r(stack_b);
			instructions_recording(RB, inst);
		}
	}
	return (new_len);
}

int		division_stack_b(t_stack **stack_a, t_stack **stack_b, char **inst,
							int length)
{
	t_stack *end;

	end = end_of_stack(*stack_b, length);
	if (end->next)
		return (division_part_of_b(stack_a, stack_b, inst, end));
	else
		return (division_full_b(stack_a, stack_b, inst));
}
