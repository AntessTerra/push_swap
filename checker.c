/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:24:40 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/18 16:11:15 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	check_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	check_doubles(t_stack **top)
{
	int	*array;
	int	i;
	int	len;

	i = 0;
	len = stack_len(*top);
	array = convert_list_to_array(*top, len);
	array = bubble_sort(array, len);
	while (i < len - 1)
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
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (str[0] == '-')
		len--;
	if (argc == 0 || len > 10)
		return (0);
	while (str[i] && i < len)
	{
		if (str[0] == '-')
			i++;
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (len == 10 && !check_int(str))
		return (0);
	return (1);
}
