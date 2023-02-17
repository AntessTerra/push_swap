/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:56:51 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/17 22:44:54 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char **argv)
{
	t_stack	*stack1;
	t_stack	*stack2;

	if (argc == 1)
		exit(0);
	stack1 = convert_args_into_stack(argc, argv);
	if (!stack1 || check_doubles(&stack1, argc) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	stack2 = NULL;
	print_stacks(&stack1, &stack2);
	stack_delete(&stack1);
	return (0);
}