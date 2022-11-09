/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:26:57 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/09 19:07:41 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_dlist	*a;
	t_stack	a_stack;
	t_dlist	*b;
	t_stack	b_stack;

	if (argc <= 1)
		exit(EXIT_SUCCESS);
	if (!is_param_valid(argv))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	initialize_stack(&a, &a_stack, argc, argv);
	if (is_sorted(a))
	{
		ft_dlstclear(&a);
		exit(EXIT_SUCCESS);
	}
	//print_stack(a, 'A');
	sort_stack(&a, &a_stack, &b, &b_stack);
	ft_dlstclear(&a);
	return (EXIT_SUCCESS);
}
