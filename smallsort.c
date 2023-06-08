/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:53:10 by cjoao-me          #+#    #+#             */
/*   Updated: 2023/06/08 13:16:35 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if (a > b && a > c)
	{
		move_r(stack_a, 'a');
		if (b > c)
			move_s(stack_a, 'a');
	}
	else if (b > a && b > c)
	{
		move_rr(stack_a, 'a');
		if (a < c)
			move_s(stack_a, 'a');
	}
	else
		move_s(stack_a, 'a');
}

void	pull_number_up(t_list **stack_a, int nbr)
{
	int	len;
	int	pos;
	int	i;

	len = ft_lstsize(*stack_a);
	pos = ft_lstposition(nbr, *stack_a);
	i = 0;
	if (pos <= len / 2 + 1)
	{
		while (++i < pos)
			move_r(stack_a, 'a');
	}
	else
	{
		while (len - i >= pos)
		{
			move_rr(stack_a, 'a');
			i++;
		}
	}
}

void	sort_untill_5(t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = ft_lstsize(*stack_a);
	if (len == 2)
		move_s(stack_a, 'a');
	else if (len == 3)
		sort_3(stack_a);
	else
	{
		if (len > 4)
		{
			pull_number_up(stack_a, ft_lstminimum(*stack_a));
			move_pb(stack_a, stack_b);
		}
		if (!ft_lstsorted(*stack_a, 'a'))
		{
			pull_number_up(stack_a, ft_lstminimum(*stack_a));
			move_pb(stack_a, stack_b);
			if (!ft_lstsorted(*stack_a, 'a'))
				sort_3(stack_a);
			move_pa(stack_a, stack_b);
		}
		if (len > 4)
			move_pa(stack_a, stack_b);
	}
}
