/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:40:32 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/20 13:53:38 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	partition (int	*array, int lt, int rt)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[rt];
	i = (lt - 1);
	j = lt;
	while (j++ <= rt - 1)
	{
		if (array[j] < pivot)
		{
			i++;
			item_swap(array[i], array[j]);
		}
	}
	item_swap(array[i + 1], array[rt]);
	return (i + 1);
}

void	quick_sort(int *array, int lt, int rt)
{
	int	mid;

	if (lt < rt)
	{
		mid = partition(array, lt, rt);
		quick_sort(array, lt, mid - 1);
		quick_sort(array, mid + 1, rt);
	}
}

int	make(t_stack **stack)
{
	int	*array;
	int	len;
	int	i;

	len = stack_len(*stack);
	array = convert_list_to_array(*stack, len);
	quick_sort(array, 0, len - 1);
	i = 0;
	while (i < len)
	{
		ft_printf("Item %i: %i", i + 1, array[i]);
		i++;
	}
	return (0);
}
