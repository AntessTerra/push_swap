/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:27:50 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/21 15:22:01 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_action(char *str)
{
	if (str[0] != '\0')
		ft_printf("%s\n", str);
	return (0);
}

int	sab(t_stack **top, char *str)
{
	t_stack	*stack;
	int		tmp;

	stack = *top;
	if (stack && stack->next)
	{
		tmp = stack->num;
		stack->num = stack->next->num;
		stack->next->num = tmp;
	}
	return (print_action(str));
}

int	rab(t_stack	**top, char *str)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*stack;

	stack = *top;
	if (!(stack && stack->next))
		return (0);
	first = stack;
	stack = stack->next;
	last = stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	*top = stack;
	return (print_action(str));
}

int	rrab(t_stack **top, char *str)
{
	t_stack	*next_to_last;
	t_stack	*last;
	t_stack	*stack;

	stack = *top;
	if (!(stack && stack->next))
		return (0);
	last = stack;
	while (last->next)
	{
		next_to_last = last;
		last = last->next;
	}
	last->next = stack;
	next_to_last->next = NULL;
	*top = last;
	return (print_action(str));
}

int	pab(t_stack **top_to, t_stack **top_from, char *str)
{
	t_stack	*tmp;
	t_stack	*to;
	t_stack	*from;

	to = *top_to;
	from = *top_from;
	if (!from)
		return (0);
	tmp = from;
	from = from->next;
	*top_from = from;
	if (!to)
	{
		to = tmp;
		to->next = NULL;
		*top_to = to;
	}
	else
	{
		tmp->next = to;
		*top_to = tmp;
	}
	return (print_action(str));
}
