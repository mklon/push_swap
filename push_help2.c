/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_help2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:02:52 by oposhiva          #+#    #+#             */
/*   Updated: 2017/05/10 14:02:53 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		recursion(t_stack **stack, int top, int num, char **inst_list)
{
	if (sort_check(*stack) && num < top)
		return (1);
	if (top <= num)
	{
		delete_operation(stack, *inst_list);
		return (0);
	}
	if (inst_s(stack) && instructions_recording(SA, inst_list))
		if (recursion(stack, top, num + 1, inst_list))
			return (1);
	if (inst_r(stack) && instructions_recording(RA, inst_list))
		if (recursion(stack, top, num + 1, inst_list))
			return (1);
	if (inst_rr(stack) && instructions_recording(RRA, inst_list))
		if (recursion(stack, top, num + 1, inst_list))
			return (1);
	if (num > 0)
		delete_operation(stack, *inst_list);
	return (0);
}

void	sort_small_stack(t_stack **stack, char **inst)
{
	int		top;

	top = 1;
	while (!recursion(stack, top, 0, inst))
		top++;
	return ;
}

int		sort_check(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->data < stack->next->data)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

int		search_median(t_stack *stack)
{
	int		i;
	int		*mass;
	int		length;

	i = 0;
	length = ft_length(stack);
	mass = malloc(sizeof(int) * length);
	while (stack)
	{
		mass[i++] = stack->data;
		stack = stack->next;
	}
	quicksort(mass, 0, length - 1);
	i = mass[length / 2];
	free(mass);
	return (i);
}

int		small_search_median(t_stack *stack, t_stack *end)
{
	int		i;
	int		*mass;
	int		length;
	t_stack *temp;

	i = 0;
	temp = stack;
	length = 0;
	while (stack && temp->next != end)
	{
		length++;
		temp = temp->next;
	}
	mass = malloc(sizeof(int) * length);
	while (stack && i < length)
	{
		mass[i++] = stack->data;
		stack = stack->next;
	}
	quicksort(mass, 0, length - 1);
	i = mass[length / 2];
	free(mass);
	return (i);
}
