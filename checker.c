/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:07:33 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/28 11:35:57 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_inst	*init_inst(void)
{
	t_inst	*inst;
	int		i;

	inst = (t_inst *)malloc(sizeof(t_inst) * 12);
	i = 0;
	while (i < 11)
		inst[i++].inst = 0;
	inst[0].inst = ft_strdup("sa");
	inst[1].inst = ft_strdup("sb");
	inst[2].inst = ft_strdup("ss");
	inst[3].inst = ft_strdup("pa");
	inst[4].inst = ft_strdup("pb");
	inst[5].inst = ft_strdup("ra");
	inst[6].inst = ft_strdup("rb");
	inst[7].inst = ft_strdup("rr");
	inst[8].inst = ft_strdup("rra");
	inst[9].inst = ft_strdup("rrb");
	inst[10].inst = ft_strdup("rrr");
	inst[11].inst = NULL;
	return (inst);
}

static void	exec_inst_more(t_inst **pinst, t_stack **pstack,
	t_stack **pstack2, int ninst)
{
	t_inst	*inst;

	inst = *pinst;
	if (ninst == 6)
		rab(pstack2, "");
	else if (ninst == 7)
		rr(pstack, pstack2, 0);
	else if (ninst == 8)
		rrab(pstack, "");
	else if (ninst == 9)
		rrab(pstack2, "");
	else if (ninst == 10)
		rrr(pstack, pstack2, 0);
	else
		return ;
	(*inst).correct = 1;
}

static void	exec_inst(t_inst **pinst, t_stack **pstack,
	t_stack **pstack2, int ninst)
{
	t_inst	*inst;

	inst = *pinst;
	if (ninst == 0)
		sab(pstack, "");
	else if (ninst == 1)
		sab(pstack2, "");
	else if (ninst == 2)
		ss(pstack, pstack2, 0);
	else if (ninst == 3)
		pab(pstack, pstack2, "");
	else if (ninst == 4)
		pab(pstack2, pstack, "");
	else if (ninst == 5)
		rab(pstack, "");
	else
		exec_inst_more(pinst, pstack, pstack2, ninst);
	(*inst).correct = 1;
}

static int	check_inst(t_inst **pinst, t_stack **pstack, t_stack **pstack2)
{
	t_inst	*inst;

	inst = *pinst;
	(*inst).i = 0;
	ft_bzero((*inst).str, 100);
	while (read(0, &(*inst).c, 1) > 0)
	{
		if ((*inst).c != '\n')
			(*inst).str[(*inst).i++] = (*inst).c;
		else
		{
			(*inst).x = 0;
			(*inst).correct = 0;
			while ((*inst).x < 11)
				if (ft_strncmp((*inst).str, inst[(*inst).x++].inst, 100) == 0)
					exec_inst(pinst, pstack, pstack2, (*inst).x - 1);
			if ((*inst).correct == 0)
				return (1);
			ft_bzero((*inst).str, 100);
			(*inst).i = 0;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack1;
	t_stack	*stack2;
	t_inst	*inst;

	inst = init_inst();
	if (argc == 1)
		exit(1);
	stack1 = convert_args_into_stack(argc, argv);
	if (!stack1 || check_doubles(&stack1) == 0)
	{
		delete_inst(inst);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	simlpify_numbers(&stack1);
	stack2 = NULL;
	if (check_inst(&inst, &stack1, &stack2))
		ft_putstr_fd("Error\n", 2);
	delete_inst(inst);
	if (check_sorted(stack1) && stack_len(stack2) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	stack_delete(&stack1);
	return (0);
}
