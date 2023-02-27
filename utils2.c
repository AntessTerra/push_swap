/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:59:22 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/27 14:05:15 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_max(t_stack **stack)
{
	t_stack	*item;
	t_stack	*max;

	item = *stack;
	max = item;
	while (item)
	{
		if (item->num > max->num)
			max = item;
		item = item->next;
	}
	return (max);
}

t_stack	*get_min(t_stack **stack)
{
	t_stack	*item;
	t_stack	*min;

	item = *stack;
	min = get_max(stack);
	while (item)
	{
		if (item->num < min->num)
			min = item;
		item = item->next;
	}
	return (min);
}

int	get_index(t_stack **stack, int val)
{
	t_stack	*item;
	int		i;

	item = *stack;
	i = 0;
	while (item)
	{
		if (item->num == val)
			return (i);
		item = item->next;
		i++;
	}
	return (i);
}

void	simlpify_numbers(t_stack **stack)
{
	int		*array;
	int		i;
	int		x;
	t_stack	*item;
	t_stack	*first;

	item = *stack;
	first = *stack;
	array = convert_list_to_array(*stack, stack_len(*stack));
	array = bubble_sort(array, stack_len(*stack));
	x = 0;
	while (item)
	{
		i = 0;
		while (item->num != array[i])
			i++;
		item->num = i;
		item->index = x;
		item = item->next;
		x++;
	}
	*stack = first;
	free(array);
}
