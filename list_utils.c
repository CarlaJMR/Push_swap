/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:53:10 by cjoao-me          #+#    #+#             */
/*   Updated: 2023/06/07 18:06:45 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstminimum(t_list *lst)
{
	int	min;

	min = lst->content;
	while (lst)
	{
		if (min > lst->content)
			min = lst->content;
		lst = (*lst).next;
	}
	return (min);
}

int	ft_lstposition(int n, t_list *lst)
{
	int	p;

	p = 1;
	while (lst && n != lst->content)
	{
		p++;
		lst = (*lst).next;
	}
	return (p);
}

int	ft_lstsorted(t_list *lst, char l)
{
	if (l == 'a')
	{
		while (lst && (*lst).next)
		{
			if (lst->content > (*lst).next->content)
				return (0);
			lst = (*lst).next;
		}
	}
	else
	{
		while (lst && (*lst).next)
		{
			if (lst->content < (*lst).next->content)
				return (0);
			lst = (*lst).next;
		}
	}
	return (1);
}

/*void	print_lst(t_list *lista)
{
	t_list *temp;

	temp = lista;
 	while (temp)
 	{
 		printf("%d ", temp->content);
 		temp = temp->next;
 	}
 	printf("\n");
 }*/