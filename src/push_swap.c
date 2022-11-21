/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:26:57 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/18 02:29:40 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_dlist	*a;
	t_stack	a_stack;
	t_dlist	*b;
	t_stack	b_stack;

	if (argc <= 2)
		exit(EXIT_SUCCESS);
	if (!is_param_valid(argv))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	initialize_stack(&a, &a_stack, argv);
	b = NULL;
	b_stack.head = NULL;
	b_stack.tail = NULL;
	b_stack.len = 0;
	if (is_sorted(a, a_stack.len))
	{
		ft_dlstclear(&a, &a_stack);
		exit(EXIT_SUCCESS);
	}
	sort_stack(&a, &a_stack, &b, &b_stack);
	ft_dlstclear(&a, &a_stack);
	return (EXIT_SUCCESS);
}
