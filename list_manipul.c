/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:14:45 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/15 16:50:14 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_delete(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tofree;

	tmp = *stack;
	while (tmp)
	{
		tofree = tmp;
		tmp = tmp->next;
		free(tofree);
	}
	*stack = NULL;
}

t_stack	*create_new(void)
{
	t_stack	*item;

	item = (t_stack *)malloc(sizeof(t_stack));
	item->num = 0;
	item->next = 0;
	return (item);
}

t_stack	*convert_args_into_stack(int argc, char **argv)
{
	int		i;
	t_stack	*first;
	t_stack	*item;

	i = 1;
	first = create_new();
	item = first;
	while (i < argc)
	{
		if (!check_arg(argv[i], argc))
		{
			stack_delete(&first);
			return (NULL);
		}
		item->num = ft_atoi(argv[i]);
		if (i < argc - 1)
		{
			item->next = create_new();
			item = item->next;
		}
		i++;
	}
	return (first);
}
