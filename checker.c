/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:24:40 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/15 16:51:13 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
