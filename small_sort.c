/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 14:21:46 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/26 15:51:34 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_stack **stack)
{
	if ((*stack)->num < (*stack)->next->num
		&& (*stack)->next->num < (*stack)->next->next->num)
		return (0);
	if ((*stack)->num > (*stack)->next->num
		&& (*stack)->next->num < (*stack)->next->next->num
		&& (*stack)->num < (*stack)->next->next->num)
		return (sab(stack, "sa"));
	else if ((*stack)->num > (*stack)->next->num
		&& (*stack)->next->num < (*stack)->next->next->num
		&& (*stack)->num > (*stack)->next->next->num)
		return (rab(stack, "ra"));
	else if ((*stack)->num < (*stack)->next->num
		&& (*stack)->next->num > (*stack)->next->next->num
		&& (*stack)->num < (*stack)->next->next->num)
		return (sab(stack, "sa") | rab(stack, "ra"));
	else if ((*stack)->num > (*stack)->next->num
		&& (*stack)->next->num > (*stack)->next->next->num)
		return (sab(stack, "sa") | rrab(stack, "rra"));
	else if ((*stack)->num < (*stack)->next->num
		&& (*stack)->next->num > (*stack)->next->next->num
		&& (*stack)->num > (*stack)->next->next->num)
		return (rrab(stack, "rra"));
	else
		return (0);
}

void	get_smallest_to_top(t_stack **stack)
{
	t_stack	*first;

	first = *stack;
	if ((get_min(stack)->index) < (stack_len(*stack) / 2)
		+ (stack_len(*stack) % 2))
	{
		while (first->num != get_min(stack)->num)
		{
			rab(stack, "ra");
			first = *stack;
		}
	}
	else if ((get_min(stack)->index) > (stack_len(*stack) / 2) - 1)
	{
		while (first->num != get_min(stack)->num)
		{
			rrab(stack, "rra");
			first = *stack;
		}
	}
}

void	sort_five(t_stack **stack, t_stack **stack2, int lenght)
{
	if (lenght == 4)
	{
		get_smallest_to_top(stack);
		pab(stack2, stack, "pb");
		sort_three(stack);
		pab(stack, stack2, "pa");
	}
	else if (lenght == 5)
	{
		get_smallest_to_top(stack);
		pab(stack2, stack, "pb");
		get_smallest_to_top(stack);
		pab(stack2, stack, "pb");
		sort_three(stack);
		pab(stack, stack2, "pa");
		pab(stack, stack2, "pa");
	}
}

void	small_sort(t_stack **stack, t_stack **stack2, int lenght)
{
	if (lenght == 1)
		return ;
	if (lenght == 2 && (*stack)->num > (*stack)->next->num)
		ft_printf("sa\n");
	else if (lenght == 3)
		sort_three(stack);
	else if (lenght == 4 || lenght == 5)
		sort_five(stack, stack2, lenght);
	else
		return ;
}
