/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:00:02 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/28 11:02:11 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ss(t_stack **stack1, t_stack **stack2, int m)
{
	if (m)
	{
		sab(stack1, "sa");
		sab(stack2, "sb");
	}
	else
	{
		sab(stack1, "");
		sab(stack2, "");
	}
	return (0);
}

int	rr(t_stack **stack1, t_stack **stack2, int m)
{
	if (m)
	{
		rab(stack1, "ra");
		rab(stack2, "rb");
	}
	else
	{
		rab(stack1, "");
		rab(stack2, "");
	}
	return (0);
}

int	rrr(t_stack **stack1, t_stack **stack2, int m)
{
	if (m)
	{
		rrab(stack1, "rra");
		rrab(stack2, "rrb");
	}
	else
	{
		rrab(stack1, "");
		rrab(stack2, "");
	}
	return (0);
}
