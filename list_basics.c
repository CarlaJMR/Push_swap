/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_basics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:53:10 by cjoao-me          #+#    #+#             */
/*   Updated: 2023/06/08 12:44:06 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(long int content)
{
	t_list	*nod;

	nod = malloc (sizeof(t_list));
	if (!nod)
		return (0);
	nod->next = 0;
	nod->content = content;
	return (nod);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int	nbr;

	nbr = 0;
	while (lst)
	{
		nbr++;
		lst = (*lst).next;
	}
	return (nbr);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*aux;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		aux = (*lst)->next;
		free (*lst);
		*lst = aux;
	}
	lst = 0;
}
