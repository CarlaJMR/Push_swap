/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:53:10 by cjoao-me          #+#    #+#             */
/*   Updated: 2023/06/09 17:51:11 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
//#include <stdio.h>

typedef struct s_list
{
	struct s_list	*next;
	int				content;
}				t_list;

long int	ft_atoi(const char *nptr);
t_list		*ft_lstnew(long int content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
void		ft_lstclear(t_list **lst);
int			ft_lstminimum(t_list *lst);
int			ft_lstposition(int n, t_list *lst);
int			ft_lstsorted(t_list *lst, char l);
//void	print_lst(t_list *lista);
int			check_arg_order(int argc, char **argv);
int			check_arg_error(int argc, char **argv);
void		move_s(t_list	**stack, char s);
void		move_r(t_list	**stack, char s);
void		move_rr(t_list **stack, char s);
void		move_pa(t_list	**stack_a, t_list	**stack_b);
void		move_pb(t_list	**stack_a, t_list	**stack_b);
void		sort_3(t_list **stack_a);
//void	pull_number_up(t_list **stack_a, int nbr)
void		sort_untill_5(t_list **stack_a, t_list **stack_b);
int			get_pivot(t_list *lst, int size);
int			*sort_array(int *arr, int size);
void		sort_three_top_a(t_list **stack, int size);
//void	sort_five_top_a(t_list **stack_a, t_list **stack_b, int size);
void		sort_three_top_b(t_list **stack, int size);
void		partition_a(t_list **stack_a, t_list **stack_b, int size, \
int *pcount);
void		partition_b(t_list **stack_a, t_list **stack_b, int size, \
int *pcount);
void		quicksort_a(t_list **stack_a, t_list **stack_b, int size);
void		quicksort_b(t_list **stack_a, t_list **stack_b, int size);
void		push_swap(int argc, char **argv);

#endif