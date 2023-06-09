/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:53:10 by cjoao-me          #+#    #+#             */
/*   Updated: 2023/06/09 17:56:58 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_top_b(t_list **stack, int size)
{
	int	a;
	int	b;
	int	c;

	if (size == 2 && (*stack)->content < (*stack)->next->content)
		move_s(stack, 'b');
	if (size == 3)
	{
		a = (*stack)->content;
		b = (*stack)->next->content;
		c = (*stack)->next->next->content;
		if (a < b && a > c && b > c)
			move_s(stack, 'b');
		else if ((a < b && a < c) || (b < a && b < c))
		{
			if (a < b && a < c)
				move_s(stack, 'b');
			move_r(stack, 'b');
			move_s(stack, 'b');
			move_rr(stack, 'b');
			if (c > a && c > b)
				move_s(stack, 'b');
		}
	}
}

void	partition_b(t_list **stack_a, t_list **stack_b, int size, int *pcount)
{
	int	rcount;
	int	pivot;

	rcount = 0 ;
	pivot = get_pivot(*stack_b, size);
	while (*pcount < size / 2 + size % 2)
	{
		if ((*stack_b)->content >= pivot && ++(*pcount))
			move_pa(stack_a, stack_b);
		else if (++rcount)
			move_r(stack_b, 'b');
	}
	while (rcount-- && size - *pcount < ft_lstsize(*stack_b))
		move_rr(stack_b, 'b');
}

void	quicksort_b(t_list **stack_a, t_list **stack_b, int size)
{
	int	pcount;

	pcount = 0;
	if (ft_lstsorted(*stack_b, 'b'))
	{
		while (ft_lstsize(*stack_b))
			move_pa(stack_a, stack_b);
	}
	else
	{
		if (size <= 3)
		{
			sort_three_top_b(stack_b, size);
			while (pcount++ < size)
				move_pa(stack_a, stack_b);
		}
		else
		{
			partition_b(stack_a, stack_b, size, &pcount);
			quicksort_a(stack_a, stack_b, pcount);
			quicksort_b(stack_a, stack_b, size - pcount);
		}
	}
}
