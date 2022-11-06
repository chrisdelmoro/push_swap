/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:40:54 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/06 19:04:00 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	pre_swap(int **nbr_array, size_t i)
{
	int	tmp;

	tmp = (*nbr_array)[i];
	(*nbr_array)[i] = (*nbr_array)[i + 1];
	(*nbr_array)[i + 1] = tmp;
}

static void	bubble_sort(int **nbr_array, t_stack *a_stack)
{
	size_t	i;
	size_t	j;

	i = 0;
	while ((int) i < a_stack->len - 1)
	{
		j = 0;
		while ((int) j < a_stack->len - (int) i - 1)
		{
			if (nbr_array[j] > nbr_array[j + 1])
				pre_swap(nbr_array, j);
			j++;
		}
		i++;
	}
}

static int	*pre_sort(t_dlist **a, t_stack *a_stack)
{
	size_t	i;
	int		*nbr_array;

	nbr_array = (int *) malloc(a_stack->len * sizeof(int));
	i = 0;
	while ((int) i < a_stack->len)
	{
		nbr_array[i] = (*a)->nbr;
		(*a) = (*a)->next;
		i++;
	}
	(*a) = a_stack->head;
	bubble_sort(&nbr_array, a_stack);
	return (nbr_array);
}

static void	feed_indexes(t_dlist **a, t_stack *a_stack, int *nbr_array)
{
	size_t	i;

	i = 0;
	while ((int) i < a_stack->len)
	{
		while ((*a))
		{
			if (nbr_array[i] == (*a)->nbr)
			{
				(*a)->index = i;
				break ;
			}
			(*a) = (*a)->next;
		}
		(*a) = a_stack->head;
		i++;
	}
}

void	initialize_stack(t_dlist **a, t_stack *a_stack, int argc, char **argv)
{
	size_t	i;
	int		*nbr_array;

	i = 2;
	*a = ft_dlstnew(ft_atoi(argv[1]));
	while (argv[i])
	{
		ft_dlstadd_back(a, ft_dlstnew(ft_atoi(argv[i])));
		i++;
	}
	a_stack->len = argc - 1;
	a_stack->head = *a;
	a_stack->tail = ft_dlstlast(*a);
	nbr_array = pre_sort(a, a_stack);
	feed_indexes(a, a_stack, nbr_array);
}
