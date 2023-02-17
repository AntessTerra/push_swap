/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:24:40 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/17 22:19:38 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doubles(t_stack **top, int argc)
{
	int	*array;
	int	i;

	i = 0;
	array = convert_list_to_array(*top, argc);
	array = bubble_sort(array, argc);
	while (i < argc - 2)
	{
		if (array[i] >= array[i + 1])
		{
			stack_delete(top);
			free(array);
			return (0);
		}
		i++;
	}
	free(array);
	return (1);
}

int	check_int(char *str)
{
	if (*str == '-' && ft_atoi(str) > 0)
		return (0);
	if (*str != '-' && ft_atoi(str) < 0)
		return (0);
	return (1);
}

int	check_arg(char *str, int argc)
{
	int	i;

	i = 0;
	if (!check_int(str) || argc == 0)
		return (0);
	while (str[i])
	{
		if (str[0] == '-')
			i++;
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
