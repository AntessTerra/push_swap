/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:59:22 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/28 13:45:19 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	delete_error(t_stack **first, t_inst **pinst)
{
	stack_delete(first);
	if (*pinst != NULL)
		delete_inst(*pinst);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	*convert_list_to_array(t_stack *stack, int len)
{
	int	*array;
	int	i;

	array = (int *)malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		array[i++] = stack->num;
		stack = stack->next;
	}
	return (array);
}

int	stack_len(t_stack *stack)
{
	int		i;
	t_stack	*item;

	i = 0;
	item = stack;
	while (item)
	{
		item = item->next;
		i++;
	}
	return (i);
}

int	count_items(char **strs)
{
	int	i;

	if (!strs)
		return (0);
	i = 0;
	while (strs[i])
		i++;
	return (i);
}
