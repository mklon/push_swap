/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 13:19:16 by oposhiva          #+#    #+#             */
/*   Updated: 2017/05/06 13:19:16 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_n_swap(t_stack **stack)
{
	if (*stack != NULL)
		if ((*stack)->next != NULL)
			return ((*stack)->data > (*stack)->next->data);
	return (-1);
}

void	ft_top_sorting(t_stack **stack_a, t_stack **stack_b, char **inst)
{
	int		a;
	int		b;

	if (check_n_swap(stack_a) > 0 && inst_s(stack_a))
		instructions_recording(SA, inst);
	if ((!check_n_swap(stack_b)) > 0 && inst_s(stack_b))
		instructions_recording(SB, inst);
	if ((a = (*stack_a != NULL && check_n_swap(&(*stack_a)->next)
			&& inst_r(stack_a))))
		instructions_recording(RA, inst);
	if ((b = (*stack_b != NULL && !check_n_swap(&(*stack_b)->next)
			&& inst_r(stack_b))))
		instructions_recording(RB, inst);
	if (a && inst_s(stack_a))
		instructions_recording(SA, inst);
	if (b && inst_s(stack_b))
		instructions_recording(SB, inst);
	if (a && inst_rr(stack_a))
		instructions_recording(RRA, inst);
	if (b && inst_rr(stack_b))
		instructions_recording(RRB, inst);
	if (check_n_swap(stack_a) > 0 && inst_s(stack_a))
		instructions_recording(SA, inst);
	if ((!check_n_swap(stack_b)) > 0 && inst_s(stack_b))
		instructions_recording(SB, inst);
}

void	delete_operation(t_stack **stack, char *inst)
{
	int		i;

	i = 0;
	while (inst[i + 2])
		i++;
	while (inst[i - 1] != '\n' && i > 0)
		i--;
	if (inst[i] == 's' && inst[i + 1] == 'a')
		inst_s(stack);
	else if (inst[i] == 'r' && inst[i + 1] == 'a')
		inst_rr(stack);
	else if (inst[i] == 'r' && inst[i + 1] == 'r' && inst[i + 2] == 'a')
		inst_r(stack);
	ft_strclr(&inst[i]);
}

void	optimize(char **inst, char *old, char *new, int i)
{
	char		*source;
	char		*point;
	int			temp;
	char		*trash;
	char		*new_inst;

	source = *inst;
	trash = source;
	new_inst = ft_strnew(ft_strlen(*inst));
	point = ft_strstr(source, old);
	while (source != point)
		new_inst[i++] = *source++;
	ft_strcat(new_inst, new);
	temp = (int)ft_strlen(old);
	while (--temp > -1)
		source++;
	ft_strcat(new_inst, source);
	*inst = new_inst;
	free(trash);
}

void	ft_delete(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
