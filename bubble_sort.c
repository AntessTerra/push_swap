/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:51:32 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/17 22:15:14 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*bubble_sort(int *array, int argc)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	while (i < argc - 2)
	{
		j = 0;
		while (j < argc - i - 2)
		{
			if (array[j] > array [j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (array);
}
