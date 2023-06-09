/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:53:10 by cjoao-me          #+#    #+#             */
/*   Updated: 2023/06/09 17:57:44 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_top_a(t_list **stack, int size)
{
	int	a;
	int	b;
	int	c;

	if (size == 2 && (*stack)->content > (*stack)->next->content)
		move_s(stack, 'a');
	if (size == 3)
	{
		a = (*stack)->content;
		b = (*stack)->next->content;
		c = (*stack)->next->next->content;
		if (a > b && a < c && b < c)
			move_s(stack, 'a');
		else if ((a > b && a > c) || (b > a && b > c))
		{
			if (a > b && a > c)
				move_s(stack, 'a');
			move_r(stack, 'a');
			move_s(stack, 'a');
			move_rr(stack, 'a');
			if (a > c && b > c)
				move_s(stack, 'a');
		}
	}
}

void	partition_a(t_list **stack_a, t_list **stack_b, int size, int *pcount)
{
	int	rcount;
	int	pivot;

	rcount = 0;
	pivot = get_pivot(*stack_a, size);
	while (*pcount < size / 2)
	{
		if ((*stack_a)->content < pivot && ++(*pcount))
			move_pb(stack_a, stack_b);
		else if (ft_lstlast(*stack_a)->content < pivot && ++(*pcount))
		{
			move_rr(stack_a, 'a');
			move_pb(stack_a, stack_b);
		}
		else if (++rcount)
			move_r(stack_a, 'a');
	}
	while (rcount-- && size < ft_lstsize(*stack_a))
		move_rr(stack_a, 'a');
}

void	quicksort_a(t_list **stack_a, t_list **stack_b, int size)
{
	int	pcount;

	pcount = 0;
	if (!ft_lstsorted(*stack_a, 'a'))
	{
		if (size <= 5 && size == ft_lstsize(*stack_a))
			sort_untill_5(stack_a, stack_b);
		else if (size <= 3)
			sort_three_top_a(stack_a, size);
		else
		{
			partition_a(stack_a, stack_b, size, &pcount);
			quicksort_a(stack_a, stack_b, size - pcount);
			quicksort_b(stack_a, stack_b, pcount);
		}
	}
}
