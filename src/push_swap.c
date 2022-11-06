/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:26:57 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/06 18:42:45 by ccamargo         ###   ########.fr       */
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



int	main(int argc, char **argv)
{
	t_dlist	*a;
	t_stack	a_stack;
	/* t_dlist	*b;
	t_stack	b_stack; */

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
