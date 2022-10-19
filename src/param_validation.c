/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:58:03 by ccamargo          #+#    #+#             */
/*   Updated: 2022/10/19 19:58:51 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int are_params_unique(char **argv)
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
			{
				ft_printf("Not all params are unique!\n"); //set standard error!
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int are_params_numbers(char **argv)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				ft_printf("Not all params are numbers!\n"); //set standard error!
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_param_valid(char **argv)
{
	if (are_params_numbers(argv) && are_params_unique(argv))
		return (1);
	return (0);
}
