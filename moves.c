/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:53:10 by cjoao-me          #+#    #+#             */
/*   Updated: 2023/06/08 12:46:50 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_s(t_list	**stack, char s)
{
	t_list	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	if (s == 'a')
		write(1, "sa\n", 3);
	else if (s == 'b')
		write(1, "sb\n", 3);
}

void	move_r(t_list	**stack, char s)
{
	t_list	*temp_1;
	t_list	*temp_2;

	temp_1 = *stack;
	while (temp_1->next != NULL)
	{
		temp_1 = temp_1->next;
	}
	temp_2 = *stack;
	*stack = (*stack)->next;
	temp_1->next = temp_2;
	temp_2->next = NULL;
	if (s == 'a')
		write(1, "ra\n", 3);
	else if (s == 'b')
		write(1, "rb\n", 3);
}

void	move_rr(t_list **stack, char s)
{
	t_list	*temp;
	t_list	*new_end;

	temp = *stack;
	temp = ft_lstlast(temp);
	temp->next = *stack;
	new_end = *stack;
	while (new_end->next != temp)
		new_end = new_end->next;
	new_end->next = NULL;
	*stack = temp;
	if (s == 'a')
		write(1, "rra\n", 4);
	else if (s == 'b')
		write(1, "rrb\n", 4);
}

void	move_pa(t_list	**stack_a, t_list	**stack_b)
{
	t_list	*temp;

	if (*stack_b == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	write(1, "pa\n", 3);
}

void	move_pb(t_list	**stack_a, t_list	**stack_b)
{
	t_list	*temp;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	write(1, "pb\n", 3);
}
