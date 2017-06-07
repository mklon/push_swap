/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oposhiva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 13:36:56 by oposhiva          #+#    #+#             */
/*   Updated: 2017/06/01 13:36:57 by oposhiva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "printflibft/get_next_line.h"
# include "printflibft/ft_printf.h"
# include "printflibft/libft/libft.h"

# define SA 1
# define SB 2
# define RA 3
# define RB 4
# define PA 5
# define PB 6
# define RRA 7
# define RRB 8

typedef struct	s_tack
{
	int				data;
	struct s_tack	*next;
}				t_stack;

typedef struct	s_bonus
{
	int				number;
	int				pause;
	int				color;
	int				visible;
	int				result;
}				t_bonus;

/*
** checker.c
*/
int				main(int argc, char **argv);

/*
** check_help.c
*/
char			*add_element(char *mass, char add, int size);
char			inst_number(char *str);
int				flags_check(int argc, char **argv, t_bonus *bonus, int num);
void			zero_bonus(t_bonus *bonus);
void			print_stack(t_stack *stack_a, t_stack *stack_b);

/*
** arguments.c
*/
t_stack			*fill_stack(int argc, char **argv, t_bonus *bonus, int i);
t_stack			*create_stack(int *mass);
void			double_check(int *mass, int size);
int				*fill_mass(int *mass, char **argv, int argc, int start);
int				*fill_mass(int *mass, char **argv, int argc, int start);
void			check_args(int i, int argc, char **argv);

/*
** checker_inst.c
*/
void			follow_instructions(t_stack *stack_a, t_bonus *bonus, int i);
void			perform_inst(t_stack **stack_a, t_stack **stack_b, char i);
void			perform_inst2(t_stack **stack_a, t_stack **stack_b, char i);
void			check_instructions(char *str);

/*
** instructions.c
*/
int				inst_s(t_stack **stack);
int				inst_p(t_stack **first_stack, t_stack **second_stack);
int				inst_r(t_stack **stack);
int				inst_rr(t_stack **stack);

/*
** both.c
*/
void			usage(int i);
void			error(void);
int				instructions_recording(int num, char **inst);
int				extra_cut(char **inst);
int				instructions_cut(char **inst);

/*
** body.c
*/
void			algorithm_basis(t_stack *stack_a, t_bonus *bonus);
void			separation(t_stack **stack_a, t_stack **stack_b, char **inst,
						int length);
void			conjunction(t_stack **stack_a, t_stack **stack_b, char **inst,
						int length);
void			inst_amount(char *inst);

/*
** push_help.c
*/
int				ft_length(t_stack *stack);
t_stack			*end_of_stack(t_stack *stack, int length);
void			quicksort(int *mass, int bot, int top);
int				smaller_then_median(t_stack *stack, int median);
int				bigger_then_median(t_stack *stack, int median);

/*
** push_help2.c
*/
int				recursion(t_stack **stack, int top, int num,
							char **inst_list);
int				search_median(t_stack *stack);
int				small_search_median(t_stack *stack, t_stack *end);
void			sort_small_stack(t_stack **stack, char **inst);
int				sort_check(t_stack *stack_a);

/*
** top_sort.c
*/
void			ft_top_sorting(t_stack **stack_a, t_stack **stack_b,
								char **inst);
int				check_n_swap(t_stack **stack);
void			delete_operation(t_stack **stack, char *inst);
void			optimize(char **inst, char *old, char *new, int i);
void			ft_delete(t_stack *stack);

/*
** separation.c
*/
int				division_stack_a(t_stack **stack_a, t_stack **stack_b,
								char **inst, int length);
int				division_full_a(t_stack **stack_a, t_stack **stack_b,
								char **inst);
int				division_part_of_a(t_stack **stack_a, t_stack **stack_b,
								char **inst, t_stack *end);
void			division_help_a(t_stack **stack_a, t_stack **stack_b,
								char **inst, int inst_num);

/*
** conjunction.c
*/
int				division_stack_b(t_stack **stack_a, t_stack **stack_b,
								char **inst, int length);
int				division_full_b(t_stack **stack_a, t_stack **stack_b,
								char **inst);
int				division_part_of_b(t_stack **stack_a, t_stack **stack_b,
								char **inst, t_stack *end);
void			division_help_b(t_stack **stack_a, t_stack **stack_b,
								char **inst, int inst_num);
/*
** one_arg.c
*/
int				*one_argument(char *str, int amount, t_bonus *bonus, int i);

#endif
