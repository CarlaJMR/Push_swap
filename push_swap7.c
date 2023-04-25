/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:53:10 by cjoao-me          #+#    #+#             */
/*   Updated: 2023/04/25 18:21:14 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	int			content;
	struct s_list	*next;
}				t_list;

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

void	print_lst(t_list *lista)
{
	t_list *temp;

	temp = lista;
 	while (temp)
 	{
 		printf("%d ", temp->content);
 		temp = temp->next;
 	}
 	printf("\n");
 }

long int	ft_atoi(const char *nptr)
{
	int	sinal;
	long int	res;

	sinal = 1;
	res = 0;

	if (*nptr && (*nptr == '+' || *nptr == '-'))
	{
		if (*nptr == '-')
			sinal = -sinal;
		nptr++;
	}
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		res = (*nptr - 48) + res * 10;
		nptr++;
	}
	return (res * sinal);
}

int	check_arg_error(int argc, char **argv)
{
	int i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j++;
		while (argv[i][j])
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
			else
				return (-1);
		if (ft_atoi(argv[i]) < -2147483648 || ft_atoi(argv[i]) > 2147483647)
				return (-1);
		j = i;
		while (j < argc - 1)
			if (ft_atoi(argv[i]) == ft_atoi(argv[++j]))
				return (-1);
		i++;
	}
	return (0);
}

int	check_arg_order(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc - 1)
	{
		if (ft_atoi(argv[i]) < ft_atoi(argv[i + 1]))
		i++;
		else
			return (-1);
	}
	return (0);
}

void	move_s(t_list	**stack, char s)
{
	t_list	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	if (s == 'a')
		write(1,"sa\n", 3);
	else if (s == 'b')
		write(1,"sb\n", 3);
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
		write(1,"ra\n", 3);
	else if (s == 'b')
		write(1,"rb\n", 3);
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
		write(1,"rra\n", 4);
	else if (s == 'b')
		write(1,"rrb\n", 4);
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
	if (pos <= len /2 + 1)
		while(++i < pos)
			move_r(stack_a, 'a');
	else
		while(len - i >= pos)
		{
			move_rr(stack_a, 'a');
			i++;
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

int	get_pivot(t_list *lst, int size)
{
	int	arr[size];
	int	i, j;
	int	temp;

	i= 0;
	while (i < size)
	{
		arr[i++] = lst->content;
		lst = (*lst).next;
	}
	i = 0;
	temp = arr[0];
	while (i< size)
	{
		j = i + 1;
		while (j< size)
		{
			if(arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (arr[size / 2]);
}

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
		if (a < b && b > c)
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
		else
			move_s(stack, 'a');
	}
}

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
		if (a > b && b < c)
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
			move_r(stack, 'a');
			move_s(stack, 'b');
			move_rr(stack, 'b');
			if (b < c)
				move_s(stack, 'b');
		}
		else if (a < b && b > c && a > c)
			move_s(stack, 'b');
	}
}
void	quicksort_b(t_list **stack_a, t_list **stack_b, int size);

void	quicksort_a(t_list **stack_a, t_list **stack_b, int size)
{
	int pcount;
	int rcount;
	int	pivot;

	pcount = 0;
	rcount = 0;
	if (!ft_lstsorted(*stack_a, 'a'))
	{
		if (size <=3)
			sort_three_top_a(stack_a, size);
		else
		{
			pivot = get_pivot(*stack_a, size);
			//printf("pivot = %i\n", pivot);
			while (pcount < size / 2)
				if ((*stack_a)->content < pivot && ++pcount)
					move_pb(stack_a, stack_b);
				else if (++rcount)
					move_r(stack_a, 'a');
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
	int pcount;
	int rcount;
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
		if (size <= 2)
		{
			if ((*stack_b)->content < (*stack_b)->next->content)
				move_s(stack_b, 'b');
			while (pcount++ < size)
				move_pa(stack_a, stack_b);
		}
		/*if (size <=3 && ft_lstsize(*stack_b) > 3)
		{
			sort_three_top_b(stack_b, size);
			while (pcount++ < size)
				move_pa(stack_a, stack_b);
		}*/
		else
		{
			pivot = get_pivot(*stack_b, size);
			//printf("pivot = %i\n", pivot);
			while (pcount + 1 < size / 2 + size % 2)
			if ((*stack_b)->content > pivot && ++pcount)
				move_pa(stack_a, stack_b);
			else if (++rcount)
				move_r(stack_b, 'b');
			while (rcount-- && size - pcount < ft_lstsize(*stack_b))
				move_rr(stack_b, 'b');
			//print_lst(*stack_a);
			//print_lst(*stack_b);
			quicksort_a(stack_a, stack_b, pcount);
			quicksort_b(stack_a, stack_b, size - pcount);
		}
	}
}

void	push_swap(int argc, char **argv)
{
	int	i;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;

	i = 1;
	while (i < argc)
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(argv[i++])));
	//print_lst(stack_a);
	if (check_arg_order(argc, argv))
	{
		if (argc <= 6)
			sort_untill_5(&stack_a, &stack_b);
		else
			quicksort_a(&stack_a, &stack_b, argc - 1);
	}
	//print_lst(stack_a);
	//print_lst(stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		exit (0);
	if (check_arg_error(argc, argv))
		write(2, "Error\n", 6);
	else
		push_swap(argc, argv);
	return (0);
}
