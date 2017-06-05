/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   body.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 15:59:52 by oposhiva          #+#    #+#             */
/*   Updated: 2017/04/30 15:59:52 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	conjunction(t_stack **stack_a, t_stack **stack_b, char **inst,
					int length)
{
	int		dop_len;

	if (length < 4)
	{
		ft_top_sorting(stack_a, stack_b, inst);
		while (length-- > 0)
		{
			inst_p(stack_a, stack_b);
			instructions_recording(PA, inst);
		}
		return ;
	}
	dop_len = length;
	length = division_stack_b(stack_a, stack_b, inst, length);
	if (length < 4)
	{
		ft_top_sorting(stack_a, stack_b, inst);
		conjunction(stack_a, stack_b, inst, dop_len - length);
	}
	else
	{
		separation(stack_a, stack_b, inst, length);
		conjunction(stack_a, stack_b, inst, dop_len - length);
	}
}

void	separation(t_stack **stack_a, t_stack **stack_b, char **inst,
					int length)
{
	int		dop_len;

	if (length < 4)
	{
		ft_top_sorting(stack_a, stack_b, inst);
		return ;
	}
	dop_len = length;
	length = division_stack_a(stack_a, stack_b, inst, length);
	separation(stack_a, stack_b, inst, dop_len - length);
	conjunction(stack_a, stack_b, inst, length);
}

void	algorithm_basis(t_stack *stack_a, t_bonus *bonus)
{
	t_stack *stack_b;
	char	*instructions;

	stack_b = NULL;
	instructions = (char*)malloc(1);
	*instructions = '\0';
	if (sort_check(stack_a))
		;
	else if (ft_length(stack_a) < 7)
		sort_small_stack(&stack_a, &instructions);
	else
		separation(&stack_a, &stack_b, &instructions, ft_length(stack_a));
	instructions_cut(&instructions);
	ft_printf("%s", instructions);
	if (bonus->result)
		print_stack(stack_a, stack_b);
	if (bonus->number)
		inst_amount(instructions);
	free(instructions);
	ft_delete(stack_a);
}

void	inst_amount(char *inst)
{
	int		num;

	num = 0;
	while (*inst)
	{
		if (*inst == '\n')
			num++;
		inst++;
	}
	ft_printf("Instructions amount > %d\n", num);
}
