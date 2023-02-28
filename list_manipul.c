/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manipul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:14:45 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/28 14:02:06 by jbartosi         ###   ########.fr       */
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

t_stack	*special_convert(t_stack *item, char *str, int i, int argc)
{
	int		x;
	char	**strs;

	strs = ft_split(str, ' ');
	x = 0;
	while (x < count_items(strs))
	{
		if (!check_arg(strs[x], argc))
		{
			free_strs(strs);
			return (NULL);
		}
		item->num = ft_atoi(strs[x]);
		if (x < count_items(strs) - 1 || i < argc - 1)
		{
			item->next = create_new();
			item = item->next;
		}
		x++;
	}
	free_strs(strs);
	return (item);
}

t_stack	*normal_convert(t_stack *item, char *str, int i, int argc)
{
	item->num = ft_atoi(str);
	if (i < argc - 1)
	{
		item->next = create_new();
		item = item->next;
	}
	return (item);
}

t_stack	*convert_args_into_stack(int argc, char **argv, t_inst **pinst)
{
	int		i;
	t_stack	*first;
	t_stack	*item;

	i = 1;
	first = create_new();
	item = first;
	while (i < argc)
	{
		if (check_space(argv[i]))
		{
			item = special_convert(item, argv[i], i, argc);
			if (item == NULL)
				delete_error(&first, pinst);
		}
		else
		{
			if (!check_arg(argv[i], argc))
				delete_error(&first, pinst);
			item = normal_convert(item, argv[i], i, argc);
		}
		i++;
	}
	return (first);
}
