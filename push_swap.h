/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:51:52 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/17 22:08:47 by jbartosi         ###   ########.fr       */
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
	struct s_stack	*next;
}				t_stack;

typedef struct s_sort
{
	char	*result;
}				t_sort;

t_stack	*convert_args_into_stack(int argc, char **argv);
int		check_arg(char *str, int argc);
void	stack_delete(t_stack **stack);
void	item_swap(int *a, int *b);
int		*bubble_sort(int *array, int argc);
int		*convert_list_to_array(t_stack *stack, int argc);
int		check_doubles(t_stack **top, int argc);
int		sab(t_stack **top);
int		rab(t_stack	**top);
int		rrab(t_stack **top);
int		pab(t_stack **top_to, t_stack **top_from);
int		ss(t_stack **stack1, t_stack **stack2);
int		rr(t_stack **stack1, t_stack **stack2);
int		rrr(t_stack **stack1, t_stack **stack2);

#endif
