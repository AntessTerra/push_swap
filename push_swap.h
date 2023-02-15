/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:51:52 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/15 16:51:06 by jbartosi         ###   ########.fr       */
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
int		sab(t_stack **top);
int		rab(t_stack	**top);
int		rrab(t_stack **top);
int		pab(t_stack **top_to, t_stack **top_from);
int		ss(t_stack **stack1, t_stack **stack2);
int		rr(t_stack **stack1, t_stack **stack2);
int		rrr(t_stack **stack1, t_stack **stack2);

#endif
