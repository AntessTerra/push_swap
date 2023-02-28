/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:51:52 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/28 11:30:41 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
}				t_stack;

typedef struct s_sort
{
	int		max_bits;
	int		i;
	int		j;
	int		lenght;
	int		key_number;
}				t_sort;

typedef struct s_inst
{
	char	*inst;
	char	str[100];
	int		x;
	int		i;
	int		correct;
	char	c;
}				t_inst;

t_stack	*convert_args_into_stack(int argc, char **argv);
int		check_arg(char *str, int argc);
int		count_items(char **strs);
int		check_space(char *str);
int		stack_len(t_stack *stack);
void	stack_delete(t_stack **stack);
int		*bubble_sort(int *array, int len);
int		*convert_list_to_array(t_stack *stack, int len);
int		check_doubles(t_stack **top);
int		sab(t_stack **top, char *str);
int		rab(t_stack	**top, char *str);
int		rrab(t_stack **top, char *str);
int		pab(t_stack **top_to, t_stack **top_from, char *str);
int		ss(t_stack **stack1, t_stack **stack2, int m);
int		rr(t_stack **stack1, t_stack **stack2, int m);
int		rrr(t_stack **stack1, t_stack **stack2, int m);
void	exit_error(void);
void	delete_error(t_stack **first);
int		check_sorted(t_stack *stack);
int		sort_three(t_stack **stack);
void	small_sort(t_stack **stack, t_stack **stack2, int lenght);
void	radix_sort(t_stack **stack, t_stack **stack2);
void	fastest_sort(t_stack **stack, t_stack **stack2);
t_stack	*get_max(t_stack **stack);
t_stack	*get_min(t_stack **stack);
void	simlpify_numbers(t_stack **stack);
int		get_index(t_stack **stack, int val);
void	delete_inst(t_inst *inst);
int		print_stacks(t_stack **top1, t_stack **top2);

#endif
