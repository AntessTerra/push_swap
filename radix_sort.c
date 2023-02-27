/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:52:36 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/27 12:44:29 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack **stack, t_stack **stack2)
{
	t_stack	*item;
	t_sort	sort;

	item = *stack;
	sort.max_bits = 0;
	sort.lenght = stack_len(*stack);
	while ((get_max(stack)->num >> sort.max_bits) != 0)
		++sort.max_bits;
	sort.i = 0;
	while (sort.i < sort.max_bits)
	{
		sort.j = 0;
		while (sort.j < sort.lenght)
		{
			item = *stack;
			if ((item->num >> sort.i) & 1)
				rab(stack, "ra");
			else
				pab(stack2, stack, "pb");
			sort.j++;
		}
		while (stack_len(*stack2) != 0)
			pab(stack, stack2, "pa");
		sort.i++;
	}
}
