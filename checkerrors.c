/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerrors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjoao-me <cjoao-me@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:53:10 by cjoao-me          #+#    #+#             */
/*   Updated: 2023/06/08 13:08:30 by cjoao-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi(const char *nptr)
{
	long int	res;
	int			sinal;

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
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
			else
				return (-1);
		}
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
	int	i;

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
