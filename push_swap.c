/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:53:10 by cjoao-me          #+#    #+#             */
/*   Updated: 2023/06/09 17:52:16 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	while (i < argc)
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(argv[i++])));
	if (check_arg_order(argc, argv))
	{
		if (argc <= 6)
			sort_untill_5(&stack_a, &stack_b);
		else
			quicksort_a(&stack_a, &stack_b, argc - 1);
	}
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		exit (1);
	if (check_arg_error(argc, argv))
		write(2, "Error\n", 6);
	else
		push_swap(argc, argv);
	return (0);
}
