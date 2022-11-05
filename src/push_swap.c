/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:26:57 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/05 17:24:15 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	printf_stack(t_dlist *stack, char ab)
{
	ft_printf("\n");
	while (stack)
	{
		ft_printf("%c nbr = %d --- index = %d\n", ab, stack->nbr, stack->index);
		stack = stack->next;
	}
}

void	rotate_up_and_push(t_dlist **a, t_stack *a_stack, t_dlist **b, t_stack *b_stack, int target)
{
	while ((*a)->nbr != target)
	{
		ra(a, a_stack);
	}
	pb(b, a, b_stack, a_stack);
}

void	rotate_down_and_push(t_dlist **a, t_stack *a_stack, t_dlist **b, t_stack *b_stack, int target)
{
	while ((*a)->nbr != target)
	{
		rra(a, a_stack);
	}
	pb(b, a, b_stack, a_stack);
}

/* void	sort_stack(t_dlist **a, t_stack *a_stack, t_dlist **b, t_stack *b_stack)
{

} */



int	*pre_sort(t_dlist **a, t_stack *a_stack)
{
	size_t	i;
	size_t	j;
	int		*nbr_array;
	int		tmp;

	//malloc temprary array to store numbers.
	nbr_array = (int *) malloc(a_stack->len * sizeof(int));

	//feed temporary array with UNSORTED numbers.
	i = 0;
	while ((int) i < a_stack->len)
	{
		nbr_array[i] = (*a)->nbr;
		(*a) = (*a)->next;
		i++;
	}
	(*a) = a_stack->head;

	//bubble sorting the array
	i = 0;
	while ((int) i < a_stack->len - 1)
	{
		j = 0;
		while ((int) j < a_stack->len - (int) i - 1)
		{
			if (nbr_array[j] > nbr_array[j + 1])
			{
				tmp = nbr_array[j];
				nbr_array[j] = nbr_array[j + 1];
				nbr_array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (nbr_array);
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



int	main(int argc, char **argv)
{
	t_dlist	*a;
	t_stack a_stack;
	/* t_dlist	*b;
	t_stack b_stack; */

	if (!is_param_valid(argv))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	initialize_stack(&a, &a_stack, argc, argv);

	printf_stack(a, 'A');

	//sort_stack(&a, &a_stack);

	return (EXIT_SUCCESS);
}
