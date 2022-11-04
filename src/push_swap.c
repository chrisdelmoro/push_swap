/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:26:57 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/03 21:06:01 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* void	index_stack(t_dlist **stack, t_stack *stack_data)
{
	int	nbr_tested;
	int	i;

	i = 0;
	nbr_tested = (*stack)->nbr;
	while (i < stack_data->len)
	{
		while ((*stack))
		{
			if ((*stack)->nbr < nbr_tested)
				nbr_tested = (*stack)->nbr;
			(*stack) = (*stack)->next;
		}
		(*stack) = stack_data->head;
		while ((*stack))
		{
			if ((*stack)->nbr == nbr_tested)
			{
				(*stack)->index = i;
				break ;
			}
			(*stack) = (*stack)->next;
		}
		(*stack) = stack_data->head;
		i++;
	}
} */

void	printf_stack(t_dlist *stack, char ab)
{
	ft_printf("\n");
	while (stack)
	{
		ft_printf("%c nbr = %d\n", ab, stack->nbr);
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
	//push(b, a, b_stack, a_stack);
}

void	rotate_down_and_push(t_dlist **a, t_stack *a_stack, t_dlist **b, t_stack *b_stack, int target)
{
	while ((*a)->nbr != target)
	{
		rra(a, a_stack);
	}
	pb(b, a, b_stack, a_stack);
	//push(b, a, b_stack, a_stack);
}

void	sort_stack(t_dlist **a, t_stack *a_stack)
{
	t_dlist	*b;
	t_stack b_stack;
	int		nbr_index[2];
	int		i;

	nbr_index[0] = (*a)->nbr;
	i = 0;
	b = NULL;
	b_stack.len = 0;
	b_stack.head = b;
	b_stack.tail = b;
	while (a_stack->len > 1)
	{
		while ((*a))
		{
			if ((*a)->nbr < nbr_index[0])
			{
				nbr_index[0] = (*a)->nbr;
				nbr_index[1] = i;
			}
			(*a) = (*a)->next;
			i++;
		}
		(*a) = a_stack->head;
		if (nbr_index[1] < (a_stack->len / 2))
		{
			rotate_up_and_push(a, a_stack, &b, &b_stack, nbr_index[0]);
		}
		else
		{
			rotate_down_and_push(a, a_stack, &b, &b_stack, nbr_index[0]);
		}
		i = 0;
		nbr_index[0] = (*a)->nbr;
	}
	//printf_stack((*a), 'A');
	//printf_stack(b, 'B');
	while (b)
	{
		pa(a, &b, a_stack, &b_stack);
		//push(a, &b, a_stack, &b_stack);
	}
	//printf_stack((*a), 'A');
	//printf_stack(b, 'B');
}

void	initialize_stack(t_dlist **a, t_stack *a_stack, int argc, char **argv)
{
	size_t	i;

	i = 2;
	*a = ft_dlstnew(ft_atoi(argv[1]));
	while (argv[i])
	{
		ft_dlstadd_front(a, ft_dlstnew(ft_atoi(argv[i])));
		i++;
	}
	a_stack->len = argc - 1;
	a_stack->head = *a;
	a_stack->tail = ft_dlstlast(*a);
	//index_stack(a, a_stack);
}

int	main(int argc, char **argv)
{
	t_dlist	*a;
	t_stack a_stack;

	if (!is_param_valid(argv))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	initialize_stack(&a, &a_stack, argc, argv);

	//printf_stack(a, 'A');

	sort_stack(&a, &a_stack);

	return (EXIT_SUCCESS);
}
