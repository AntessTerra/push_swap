/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fastest_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:04:23 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/27 16:46:19 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_key_number(int lenght)
{
	static int	i;

	if (lenght <= 100 && i < 3)
		return ((lenght / 4) * ++i);
	else if (lenght <= 500 && i < 10)
		return ((lenght / 11) * ++i);
	else
		return (0);
}

void	fastest_sort_more_more(t_stack **stack, t_stack **stack2,
	t_stack *item, t_stack *first)
{
	item = *stack2;
	while (item)
	{
		first = *stack2;
		if ((get_index(stack2, get_max(stack2)->num)) < (stack_len(*stack2) / 2)
			+ (stack_len(*stack2) % 2))
		{
			while (get_max(stack2)->num != first->num)
			{
				rab(stack2, "rb");
				first = *stack2;
			}
		}
		else
		{
			while (get_max(stack2)->num != first->num)
			{
				rrab(stack2, "rrb");
				first = *stack2;
			}
		}
		pab(stack, stack2, "pa");
		item = *stack2;
	}
}

void	fastest_sort_more(t_stack **stack, t_stack **stack2,
	t_stack *item, t_stack *first)
{
	item = *stack;
	while (item)
	{
		first = *stack;
		if ((get_index(stack, get_min(stack)->num)) < (stack_len(*stack) / 2)
			+ (stack_len(*stack) % 2))
		{
			while (get_min(stack)->num != first->num)
			{
				rab(stack, "ra");
				first = *stack;
			}
		}
		else
		{
			while (get_min(stack)->num != first->num)
			{
				rrab(stack, "rra");
				first = *stack;
			}
		}
		pab(stack2, stack, "pb");
		item = *stack;
	}
}

void	more(t_stack **stack, t_stack **stack2,
	t_stack **item, t_stack **first)
{
	while ((*first)->num != (*item)->num)
	{
		if ((stack_len(*stack) / 2) > get_index(stack, (*item)->num))
			rab(stack, "ra");
		else
			rrab(stack, "rra");
		*first = *stack;
	}
	pab(stack2, stack, "pb");
	*item = *stack;
}

void	fastest_sort(t_stack **stack, t_stack **stack2)
{
	t_sort	sort;
	t_stack	*item;
	t_stack	*first;

	sort.lenght = stack_len(*stack);
	sort.key_number = get_key_number(sort.lenght) - 1;
	item = *stack;
	sort.i = -1;
	while (item)
	{
		first = *stack;
		if (item->num <= sort.key_number)
		{
			more(stack, stack2, &item, &first);
			sort.i++;
		}
		else
			item = item->next;
		if (sort.i == sort.key_number)
			sort.key_number = get_key_number(sort.lenght) - 1;
	}
	fastest_sort_more(stack, stack2, item, first);
	fastest_sort_more_more(stack, stack2, item, first);
}
