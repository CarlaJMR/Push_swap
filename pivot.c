/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:53:10 by cjoao-me          #+#    #+#             */
/*   Updated: 2023/06/08 15:16:50 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_pivot(t_list *lst, int size)
{
	int	*arr;
	int	i;
	int	pivot;

	i = 0;
	arr = malloc(sizeof(int) * size);
	/*if (!arr)
		return (0);*/
	while (i < size)
	{
		arr[i++] = lst->content;
		lst = (*lst).next;
	}
	pivot = sort_array(arr, size)[size / 2];
	free(arr);
	return (pivot);
}

int	*sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}
