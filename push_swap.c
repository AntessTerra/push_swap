/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:56:51 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/20 17:02:53 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	if ((*stack)->num < (*stack)->next->num
		&& (*stack)->next->num < (*stack)->next->next->num)
		return ;
	if ((*stack)->num > (*stack)->next->num
		&& (*stack)->next->num < (*stack)->next->next->num
		&& (*stack)->num < (*stack)->next->next->num)
		ft_printf("sa\n");
	else if ((*stack)->num > (*stack)->next->num
		&& (*stack)->next->num < (*stack)->next->next->num
		&& (*stack)->num > (*stack)->next->next->num)
		ft_printf("ra\n");
	else if ((*stack)->num < (*stack)->next->num
		&& (*stack)->next->num > (*stack)->next->next->num
		&& (*stack)->num < (*stack)->next->next->num)
		ft_printf("sa\nra\n");
	else if ((*stack)->num > (*stack)->next->num
		&& (*stack)->next->num > (*stack)->next->next->num)
		ft_printf("sa\nrra\n");
	else if ((*stack)->num < (*stack)->next->num
		&& (*stack)->next->num > (*stack)->next->next->num
		&& (*stack)->num > (*stack)->next->next->num)
		ft_printf("rra\n");
}

void	small_sort(t_stack **stack, int lenght)
{
	if (lenght == 1)
		return ;
	if (lenght == 2 && (*stack)->num > (*stack)->next->num)
		ft_printf("sa\n");
	else if (lenght == 3)
		sort_three(stack);
	else
		quick_sort();
}
/*
int	print_stacks(t_stack **top1, t_stack **top2)
{
	int		i;
	t_stack	*stack1;
	t_stack	*stack2;

	stack1 = *top1;
	stack2 = *top2;
	i = 1;
	if (stack1)
	{
		while (stack1->next)
		{
			ft_printf("stack1.%i: %i\n", i++, stack1->num);
			stack1 = stack1->next;
		}
		ft_printf("stack1.%i: %i\n\n", i++, stack1->num);
	}
	else
		ft_printf("Stack1 is empty.\n\n");
	i = 1;
	if (stack2)
	{
		while (stack2->next)
		{
			ft_printf("stack2.%i: %i\n", i++, stack2->num);
			stack2 = stack2->next;
		}
		ft_printf("stack2.%i: %i\n", i++, stack2->num);
	}
	else
		ft_printf("Stack2 is empty.\n");
	return (0);
}
*/
int	main(int argc, char **argv)
{
	t_stack	*stack1;
	t_stack	*stack2;
	int		lenght;

	if (argc == 1)
		exit(0);
	stack1 = convert_args_into_stack(argc, argv);
	if (!stack1 || check_doubles(&stack1) == 0)
		exit_error();
	stack2 = NULL;
	lenght = stack_len(stack1);
	if (lenght < 4)
	{
		small_sort(&stack1, lenght);
		stack_delete(&stack1);
		return (0);
	}
	//print_stacks(&stack1, &stack2);
	stack_delete(&stack1);
	return (0);
}
