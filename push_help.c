/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 13:03:22 by oposhiva          #+#    #+#             */
/*   Updated: 2017/05/06 13:03:23 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zconf.h>
#include "push_swap.h"

int		ft_length(t_stack *stack)
{
	int		len;
	t_stack *temp;

	len = 0;
	temp = stack;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

t_stack	*end_of_stack(t_stack *stack, int length)
{
	int		temp;

	temp = -1;
	while (++temp < length && stack->next)
		stack = stack->next;
	return (stack);
}

void	quicksort(int *mass, int bot, int top)
{
	int		left;
	int		right;
	int		pivot;

	left = bot;
	right = top;
	pivot = mass[(left + right) / 2];
	while (left <= right)
	{
		while (mass[left] < pivot)
			left++;
		while (mass[right] > pivot)
			right--;
		if (left <= right)
			ft_swap(&mass[left++], &mass[right--]);
	}
	if (bot < right)
		quicksort(mass, bot, right);
	if (top > left)
		quicksort(mass, left, top);
}

int		bigger_then_median(t_stack *stack, int median)
{
	while (stack)
	{
		if (stack->data >= median)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int		smaller_then_median(t_stack *stack, int median)
{
	while (stack)
	{
		if (stack->data < median)
			return (1);
		stack = stack->next;
	}
	return (0);
}
