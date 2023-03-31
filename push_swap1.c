/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:53:10 by cjoao-me          #+#    #+#             */
/*   Updated: 2023/03/31 17:31:44 by cjoao-me         ###   ########.fr       */
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

void	move_sa(t_list	**stack)
{
	t_list	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	write(1,"sa\n", 3);
}

void	move_ra(t_list	**stack)
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
	write(1,"ra\n", 3);
}

void	move_rra(t_list **stack)
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
	write(1,"rra\n", 4);
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
		move_ra(stack_a);
		if (b > c)
		move_sa(stack_a);
	}
	else if (b > a && b > c)
	{
		move_rra(stack_a);
		if (a < c)
		move_sa(stack_a);
	}
	else
		move_sa(stack_a);
}

void	pull_min_up(t_list **stack_a)
{
	int	len;
	int	min;
	int	pos;
	int	i;

	len = ft_lstsize(*stack_a);
	min = ft_lstminimum(*stack_a);
	pos = ft_lstposition(min, *stack_a);
	i = 0;
	if (pos <= len /2 + 1)
		while(++i < pos)
			move_ra(stack_a);
	else
		while(len - i >= pos)
		{
			move_rra(stack_a);
			i++;
		}
}

void	sort_4_5(t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = ft_lstsize(*stack_a);
	if (len > 4)
	{
		pull_min_up(stack_a);
		move_pb(stack_a, stack_b);
	}
	pull_min_up(stack_a);
	move_pb(stack_a, stack_b);
	sort_3(stack_a);
	move_pa(stack_a, stack_b);
	if (len > 4)
		move_pa(stack_a, stack_b);
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
	print_lst(stack_a);
	if (check_arg_order(argc, argv))
	{
		if (argc == 3)
			move_sa(&stack_a);
		else if (argc == 4)
			sort_3(&stack_a);
		else if (argc == 5 || argc == 6)
			sort_4_5(&stack_a, &stack_b);
		else
		{
			//sort_up_5(stack_a, stack_b);
		}
		print_lst(stack_a);
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		exit (0);
	if (check_arg_error(argc, argv))
		write(1, "Error\n", 6);
	else
		push_swap(argc, argv);
	return (0);
}
