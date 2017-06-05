/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 14:32:35 by oposhiva          #+#    #+#             */
/*   Updated: 2017/04/11 14:32:36 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		inst_s(t_stack **stack)
{
	int		tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->data;
		(*stack)->data = (*stack)->next->data;
		(*stack)->next->data = tmp;
		return (1);
	}
	return (0);
}

int		inst_p(t_stack **first_stack, t_stack **second_stack)
{
	t_stack *temp;

	if (!(*second_stack))
		return (0);
	temp = *second_stack;
	*second_stack = (*second_stack)->next;
	temp->next = *first_stack;
	*first_stack = temp;
	return (1);
}

int		inst_r(t_stack **stack)
{
	t_stack *temp;
	t_stack *tmp;

	if (!(*stack) || !(*stack)->next)
		return (0);
	temp = *stack;
	tmp = (*stack)->next;
	while ((*stack)->next)
		*stack = (*stack)->next;
	temp->next = NULL;
	(*stack)->next = temp;
	*stack = tmp;
	return (1);
}

int		inst_rr(t_stack **stack)
{
	t_stack *temp;

	if (!(*stack) || !(*stack)->next)
		return (0);
	temp = *stack;
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	(*stack)->next->next = temp;
	temp = (*stack)->next;
	(*stack)->next = NULL;
	*stack = temp;
	return (1);
}
