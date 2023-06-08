/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:53:10 by cjoao-me          #+#    #+#             */
/*   Updated: 2023/06/08 15:20:41 by cjoao-me         ###   ########.fr       */
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
		/*if (a < b && b > c)
		{
			move_r(stack, 'a');
			move_s(stack, 'a');
			move_rr(stack, 'a');
			if (a > c)
				move_s(stack, 'a');
		}
		else if (a > b && a > c)
		{
			move_s(stack, 'a');
			move_r(stack, 'a');
			move_s(stack, 'a');
			move_rr(stack, 'a');
			if (b > c)
				move_s(stack, 'a');
		}
		else if (a > b && a < c && b < c)
			move_s(stack, 'a');*/
	}
}

/*void	sort_five_top_a(t_list **stack_a, t_list **stack_b, int size)
{
	int	pcount;
	int	rcount;
	
	pcount = 0;
	rcount = 0;
	
	while (pcount < size - 3)
	{
		if ((*stack_a)->content == ft_lstminimum(*stack_a))
		{
			move_pb(stack_a, stack_b);
			pcount++;
		}
		else
			while ((*stack_a)->content != ft_lstminimum(*stack_a) && rcount + pcount < size && ++rcount)
				move_r(stack_a, 'a');
	}
	while (rcount--)
		move_rr(stack_a, 'a');
	sort_three_top_a(stack_a, 3);
	while (pcount--)
		move_pa(stack_a, stack_b);
}*/

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
		/*if (a > b && b < c)
		{
			move_r(stack, 'b');
			move_s(stack, 'b');
			move_rr(stack, 'b');
			if (a < c)
				move_s(stack, 'b');
		}
		else if (a < b && a < c)
		{
			move_s(stack, 'b');
			move_r(stack, 'b');
			move_s(stack, 'b');
			move_rr(stack, 'b');
			if (b < c)
				move_s(stack, 'b');
		}
		else if (a < b && b > c && a > c)
			move_s(stack, 'b');*/
	}
}

void	quicksort_a(t_list **stack_a, t_list **stack_b, int size)
{
	int	pcount;
	int	rcount;
	int	pivot;

	pcount = 0;
	rcount = 0;
	if (!ft_lstsorted(*stack_a, 'a'))
	{
		if (size <= 5 && size == ft_lstsize(*stack_a))
			sort_untill_5(stack_a, stack_b);
		else if (size <= 3)
			sort_three_top_a(stack_a, size);
			//sort_five_top_a(stack_a, stack_b, size);
			/*if (size == ft_lstsize(*stack_a))
				sort_untill_5(stack_a, stack_b);
			else
				sort_five_top_a(stack_a, stack_b, size);*/
		else
		{
			pivot = get_pivot(*stack_a, size);
			//printf("pivot = %i\n", pivot);
			while (pcount < size / 2)
			{
				if ((*stack_a)->content < pivot && ++pcount)
					move_pb(stack_a, stack_b);
				else if (ft_lstlast(*stack_a)->content < pivot && ++pcount)
				{
					move_rr(stack_a, 'a');
					move_pb(stack_a, stack_b);
				}
				else if (++rcount)
					move_r(stack_a, 'a');
			}
			while (rcount-- && size < ft_lstsize(*stack_a))
				move_rr(stack_a, 'a');
			//print_lst(*stack_a);
			//print_lst(*stack_b);
			quicksort_a(stack_a, stack_b, size - pcount);
			quicksort_b(stack_a, stack_b, pcount);
		}
	}
}

void	quicksort_b(t_list **stack_a, t_list **stack_b, int size)
{
	int	pcount;
	int	rcount;
	int	pivot;

	pcount = 0;
	rcount = 0;
	if (ft_lstsorted(*stack_b, 'b'))
	{
		while (ft_lstsize(*stack_b))
			move_pa(stack_a, stack_b);
	}
	else
	{
		if (size <= 3)
		//if (size <= 3 && size != ft_lstsize(*stack_b))
		{
			sort_three_top_b(stack_b, size);
			while (pcount++ < size)
				move_pa(stack_a, stack_b);
		}
		else
		{
			pivot = get_pivot(*stack_b, size);
			//printf("pivot = %i\n", pivot);
			while (pcount < size / 2 + size % 2)
			{
				if ((*stack_b)->content >= pivot && ++pcount)
					move_pa(stack_a, stack_b);
				else if (++rcount)
					move_r(stack_b, 'b');
			}
			while (rcount-- && size - pcount < ft_lstsize(*stack_b))
				move_rr(stack_b, 'b');
			//print_lst(*stack_a);
			//print_lst(*stack_b);
			quicksort_a(stack_a, stack_b, pcount);
			quicksort_b(stack_a, stack_b, size - pcount);
		}
	}
}
