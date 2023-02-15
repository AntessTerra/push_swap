/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:27:50 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/15 16:34:57 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	item_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	sab(t_stack **top)
{
	t_stack	*stack;

	stack = *top;
	if (stack && stack->next)
		item_swap(&stack->num, &stack->next->num);
	return (0);
}

int	rab(t_stack	**top)
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
	return (0);
}

int	rrab(t_stack **top)
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
	return (0);
}

int	pab(t_stack **top_to, t_stack **top_from)
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
	return (0);
}
