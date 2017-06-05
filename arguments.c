/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckecker_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:13:41 by oposhiva          #+#    #+#             */
/*   Updated: 2017/04/06 15:13:41 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args(int i, int argc, char **argv)
{
	int		j;

	while (++i < argc)
	{
		j = 0;
		while (argv[i][j] == ' ')
			j++;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		while (argv[i][j])
			if (!ft_isdigit(argv[i][j++]))
				error();
	}
}

int		*fill_mass(int *mass, char **argv, int argc, int start)
{
	int			i;
	long int	l;

	i = 1;
	while (start < argc)
	{
		l = ft_atoi(&argv[start][0]);
		if (l > 2147483647 || l < -2147483648)
			error();
		mass[i++] = (int)l;
		start++;
	}
	mass[i] = '\0';
	mass[0] = i - 1;
	return (mass);
}

void	double_check(int *mass, int size)
{
	int		i;
	int		j;

	i = 1;
	j = 2;
	while (i <= size)
	{
		while (j <= size)
		{
			if (mass[i] == mass[j])
				error();
			j++;
		}
		i++;
		j = i + 1;
	}
}

t_stack	*create_stack(int *mass)
{
	int		i;
	int		*p;
	t_stack *begin;
	t_stack *stack;
	t_stack *previous;

	p = mass++;
	i = 0;
	stack = malloc(sizeof(*stack));
	begin = stack;
	stack->data = *mass;
	while (++i < p[0])
	{
		++mass;
		previous = stack;
		stack = malloc(sizeof(*stack));
		previous->next = stack;
		stack->data = *mass;
	}
	stack->next = NULL;
	free(p);
	return (begin);
}

t_stack	*fill_stack(int argc, char **argv, t_bonus *bonus, int i)
{
	int		amount;
	int		*mass;

	amount = flags_check(argc, argv, bonus, i);
	if ((argc - amount) == 1)
		usage(i);
	else if (argc == 2)
		return (create_stack(one_argument(&argv[1][0], 0, bonus, i)));
	check_args(amount, argc, argv);
	mass = (int*)malloc(sizeof(int) * (argc - amount) + 1);
	mass = fill_mass(mass, argv, argc, amount + 1);
	double_check(mass, argc - amount - 1);
	return (create_stack(mass));
}
