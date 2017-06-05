/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 14:00:46 by oposhiva          #+#    #+#             */
/*   Updated: 2017/04/06 14:00:46 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*add_element(char *mass, char add, int size)
{
	int		i;
	char	*new;

	i = -1;
	new = (char*)malloc(sizeof(char) * size + 1);
	while (++i < size - 1)
		new[i] = mass[i];
	new[i++] = add;
	new[i] = '\0';
	free(mass);
	return (new);
}

char	inst_number(char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		return ('1');
	if (ft_strcmp(str, "sb\n") == 0)
		return ('2');
	if (ft_strcmp(str, "ss\n") == 0)
		return ('3');
	if (ft_strcmp(str, "pa\n") == 0)
		return ('4');
	if (ft_strcmp(str, "pb\n") == 0)
		return ('5');
	if (ft_strcmp(str, "ra\n") == 0)
		return ('6');
	if (ft_strcmp(str, "rb\n") == 0)
		return ('7');
	if (ft_strcmp(str, "rr\n") == 0)
		return ('8');
	if (ft_strcmp(str, "rra\n") == 0)
		return ('9');
	if (ft_strcmp(str, "rrb\n") == 0)
		return ('0');
	if (ft_strcmp(str, "rrr\n") == 0)
		return ('A');
	else
		error();
	return ('\0');
}

int		flags_check(int argc, char **argv, t_bonus *bonus, int num)
{
	int		i;

	i = 1;
	zero_bonus(bonus);
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-n") == 0 && !num)
			bonus->number = 1;
		else if (ft_strcmp(argv[i], "-c") == 0 && num)
			bonus->color = 1;
		else if (ft_strcmp(argv[i], "-p") == 0 && num)
			bonus->pause = 1;
		else if (ft_strcmp(argv[i], "-v") == 0 && num)
			bonus->visible = 1;
		else if (ft_strcmp(argv[i], "-r") == 0 && !num)
			bonus->result = 1;
		else
			break ;
		i++;
	}
	return (--i);
}

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("┏━━━━━━━━━━━━━┳━━━━━━━━━━━━━┓\n");
	ft_printf("┃   Stack A   ┃   Stack B   ┃\n");
	ft_printf("┣━━━━━━━━━━━━━╋━━━━━━━━━━━━━┫\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_printf("┃  %-11d┃", stack_a->data);
			stack_a = stack_a->next;
		}
		else
			ft_printf("┃             ┃");
		if (stack_b)
		{
			ft_printf("  %-11d┃", stack_b->data);
			stack_b = stack_b->next;
		}
		else
			ft_printf("             ┃");
		ft_printf("\n");
	}
	ft_printf("┗━━━━━━━━━━━━━┻━━━━━━━━━━━━━┛\n");
}

void	zero_bonus(t_bonus *bonus)
{
	bonus->number = 0;
	bonus->color = 0;
	bonus->pause = 0;
	bonus->visible = 0;
	bonus->result = 0;
}
