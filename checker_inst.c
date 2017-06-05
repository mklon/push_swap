/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_inst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 13:22:13 by oposhiva          #+#    #+#             */
/*   Updated: 2017/04/07 13:22:14 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_instructions(char *str)
{
	if (ft_strcmp(str, "sa\n") == 0 ||
		ft_strcmp(str, "sb\n") == 0 ||
		ft_strcmp(str, "ss\n") == 0 ||
		ft_strcmp(str, "pa\n") == 0 ||
		ft_strcmp(str, "pb\n") == 0 ||
		ft_strcmp(str, "ra\n") == 0 ||
		ft_strcmp(str, "rb\n") == 0 ||
		ft_strcmp(str, "rr\n") == 0 ||
		ft_strcmp(str, "rra\n") == 0 ||
		ft_strcmp(str, "rrb\n") == 0 ||
		ft_strcmp(str, "rrr\n") == 0)
		return ;
	else
		error();
}

void	perform_inst2(t_stack **stack_a, t_stack **stack_b, char i)
{
	if (i == '6')
		inst_r(stack_a);
	else if (i == '7')
		inst_r(stack_b);
	else if (i == '8')
	{
		inst_r(stack_a);
		inst_r(stack_b);
	}
	else if (i == '9')
		inst_rr(stack_a);
	else if (i == '0')
		inst_rr(stack_b);
	else if (i == 'A')
	{
		inst_rr(stack_a);
		inst_rr(stack_b);
	}
}

void	perform_inst(t_stack **stack_a, t_stack **stack_b, char i)
{
	if (i == '1')
		inst_s(stack_a);
	else if (i == '2')
		inst_s(stack_b);
	else if (i == '3')
	{
		inst_s(stack_a);
		inst_s(stack_b);
	}
	else if (i == '4')
		inst_p(stack_a, stack_b);
	else if (i == '5')
		inst_p(stack_b, stack_a);
	else
		perform_inst2(stack_a, stack_b, i);
}

void	check_sorting(t_stack *stack_a, t_stack *stack_b, int i)
{
	int		is_ok;

	is_ok = 1;
	if (stack_b)
		is_ok = 0;
	while (stack_a->next && is_ok)
	{
		if (stack_a->data <= stack_a->next->data)
			stack_a = stack_a->next;
		else
			is_ok = 0;
	}
	sleep(1);
	if (is_ok && !i)
		ft_printf("OK\n");
	else if (!is_ok && !i)
		ft_printf("KO\n");
	else if (is_ok)
		ft_printf("\x1b[32mOK\n");
	else
		ft_printf("\x1b[31mKO\n");
}

void	follow_instructions(t_stack *stack_a, t_bonus *bonus, int i)
{
	char	*inst;
	char	*mass;
	t_stack	*stack_b;

	stack_b = NULL;
	mass = (char*)malloc(1);
	*mass = '\0';
	while (get_next_line(0, &inst))
	{
		check_instructions(inst);
		mass = add_element(mass, inst_number(inst), ++i);
		free(inst);
	}
	i = -1;
	while (mass[++i])
	{
		perform_inst(&stack_a, &stack_b, mass[i]);
		if (bonus->visible)
			print_stack(stack_a, stack_b);
		if (bonus->pause)
			sleep(2);
	}
	free(mass);
	check_sorting(stack_a, stack_b, bonus->color);
	ft_delete(stack_a);
}
