/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 13:12:11 by oposhiva          #+#    #+#             */
/*   Updated: 2017/05/08 13:12:12 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	division_help_a(t_stack **stack_a, t_stack **stack_b, char **inst,
						int inst_num)
{
	if (inst_num == PB)
	{
		inst_p(stack_b, stack_a);
		instructions_recording(PB, inst);
	}
	else if (inst_num == RA)
	{
		inst_r(stack_a);
		instructions_recording(RA, inst);
	}
	else if (inst_num == RRA)
	{
		inst_rr(stack_a);
		instructions_recording(RRA, inst);
	}
}

int		division_part_of_a(t_stack **stack_a, t_stack **stack_b, char **inst,
							t_stack *end)
{
	int		median;
	int		new_len;
	int		rr_num;

	rr_num = 0;
	new_len = 0;
	median = small_search_median(*stack_a, end);
	while (smaller_then_median(*stack_a, median))
	{
		while ((*stack_a)->data <= median)
		{
			division_help_a(stack_a, stack_b, inst, PB);
			new_len++;
		}
		if (smaller_then_median(*stack_a, median))
		{
			division_help_a(stack_a, stack_b, inst, RA);
			rr_num++;
		}
	}
	while (--rr_num > -1)
		division_help_a(stack_a, stack_b, inst, RRA);
	return (new_len);
}

int		division_full_a(t_stack **stack_a, t_stack **stack_b, char **inst)
{
	int		median;
	int		new_len;

	new_len = 0;
	median = search_median(*stack_a);
	while (smaller_then_median(*stack_a, median))
	{
		while ((*stack_a)->data < median)
		{
			inst_p(stack_b, stack_a);
			instructions_recording(PB, inst);
			new_len++;
		}
		if (smaller_then_median(*stack_a, median))
		{
			inst_r(stack_a);
			instructions_recording(RA, inst);
		}
	}
	return (new_len);
}

int		division_stack_a(t_stack **stack_a, t_stack **stack_b, char **inst,
						int length)
{
	t_stack *end;

	end = end_of_stack(*stack_a, length);
	if (end->next)
		return (division_part_of_a(stack_a, stack_b, inst, end));
	else
		return (division_full_a(stack_a, stack_b, inst));
}
