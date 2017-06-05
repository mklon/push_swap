/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 12:57:07 by oposhiva          #+#    #+#             */
/*   Updated: 2017/04/16 12:57:07 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	usage(int i)
{
	if (i)
		ft_printf("usage: ./checker [-c | -v | -p] arguments ...\n");
	else
		ft_printf("usage: ./push_swap [-r | -n] arguments ...\n");
	exit(2);
}

void	error(void)
{
	ft_printf("Error\n");
	exit(2);
}

int		instructions_recording(int num, char **inst)
{
	char	*trash;

	trash = *inst;
	if (num == SA)
		*inst = ft_strjoin(*inst, "sa\n");
	else if (num == SB)
		*inst = ft_strjoin(*inst, "sb\n");
	else if (num == RA)
		*inst = ft_strjoin(*inst, "ra\n");
	else if (num == RB)
		*inst = ft_strjoin(*inst, "rb\n");
	else if (num == PA)
		*inst = ft_strjoin(*inst, "pa\n");
	else if (num == PB)
		*inst = ft_strjoin(*inst, "pb\n");
	else if (num == RRA)
		*inst = ft_strjoin(*inst, "rra\n");
	else if (num == RRB)
		*inst = ft_strjoin(*inst, "rrb\n");
	else
		return (0);
	free(trash);
	return (1);
}

int		extra_cut(char **inst)
{
	if (ft_strstr(*inst, "rra\nrrb\n"))
		optimize(inst, "rra\nrrb\n", "rrr\n", 0);
	else if (ft_strstr(*inst, "rrb\nrra\n"))
		optimize(inst, "rrb\nrra\n", "rrr\n", 0);
	else if (ft_strstr(*inst, "rb\npa\nrrb\n"))
		optimize(inst, "rb\npa\nrrb\n", "sb\npa\n", 0);
	else if (ft_strstr(*inst, "ra\npb\nrra\n"))
		optimize(inst, "ra\npb\nrra\n", "sa\npb\n", 0);
	else if (ft_strstr(*inst, "pb\nrra\npa\n"))
		optimize(inst, "pb\nrra\npa\n", "rra\nsa\n", 0);
	else if (ft_strstr(*inst, "pb\nrb\nsb\nrrb\npa\n"))
		optimize(inst, "pb\nrb\nsb\nrrb\npa\n", "sb\n", 0);
	else
		return (0);
	return (1);
}

int		instructions_cut(char **inst)
{
	if (ft_strstr(*inst, "pa\npb\n"))
		optimize(inst, "pa\npb\n", "\n", 0);
	else if (ft_strstr(*inst, "pb\npa\n"))
		optimize(inst, "pb\npa\n", "\n", 0);
	else if (ft_strstr(*inst, "sa\nsb\n"))
		optimize(inst, "sa\nsb\n", "ss\n", 0);
	else if (ft_strstr(*inst, "sb\nsa\n"))
		optimize(inst, "sb\nsa\n", "ss\n", 0);
	else if (ft_strstr(*inst, "rra\nra\n"))
		optimize(inst, "rra\nra\n", "\n", 0);
	else if (ft_strstr(*inst, "\nra\nrra\n"))
		optimize(inst, "\nra\nrra\n", "\n\n", 0);
	else if (ft_strstr(*inst, "rrb\nrb\n"))
		optimize(inst, "rrb\nrb\n", "\n", 0);
	else if (ft_strstr(*inst, "\nrb\nrrb\n"))
		optimize(inst, "\nrb\nrrb\n", "\n\n", 0);
	else if (ft_strstr(*inst, "\n\n"))
		optimize(inst, "\n\n", "\n", 0);
	else if (extra_cut(inst))
		;
	else
		return (0);
	instructions_cut(inst);
	return (1);
}
