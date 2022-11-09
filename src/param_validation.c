/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:58:03 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/09 19:06:29 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

static int	are_params_unique(char **argv)
{
	size_t	i;
	size_t	j;
	int		tested_arg;

	i = 1;
	while (argv[i])
	{
		tested_arg = ft_atoi(argv[i]);
		j = i + 1;
		while (argv[j])
		{
			if (tested_arg == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	are_params_numbers(char **argv)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	are_params_ints(char **argv)
{
	size_t		i;
	long long	tmp;

	i = 1;
	while (argv[i])
	{
		tmp = (long long) ft_atoll(argv[i]);
		if (tmp < MIN_INT || tmp > MAX_INT)
			return (0);
		i++;
	}
	return (1);
}

int	is_param_valid(char **argv)
{
	if (are_params_numbers(argv) && \
	are_params_unique(argv) && \
	are_params_ints(argv))
		return (1);
	return (0);
}
