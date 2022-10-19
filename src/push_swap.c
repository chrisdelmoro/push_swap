/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:26:57 by ccamargo          #+#    #+#             */
/*   Updated: 2022/10/19 19:58:35 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	initialize_stack_a(t_dlist **a, t_stack *a_stack, int argc, char **argv)
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
}

int	main(int argc, char **argv)
{
	t_dlist	*a;
	t_dlist *tmp;
	//t_dlist	*b;
	t_stack a_stack;
	//t_stack b_stack;

	if (!is_param_valid(argv))
	{
		ft_printf("Error!\n");
		exit(EXIT_FAILURE);
	}
	initialize_stack_a(&a, &a_stack, argc, argv);
	//initialize_stack_a(&b, &b_stack, argc, argv);


	tmp = a;
	while (tmp->next)
	{
		ft_printf("%d\n", tmp->nbr);
		tmp = tmp->next;
	}
	ft_printf("%d\n", tmp->nbr);
	ft_printf("\nStack struct status:\n");
	ft_printf("A_stack.head = %d\n", a_stack.head->nbr);
	ft_printf("A_stack.tail = %d\n\n", a_stack.tail->nbr);
	ft_printf("A_stack.len = %d\n\n", a_stack.len);

	rev_rotate(&a, &a_stack);

	tmp = a;
	while (tmp->next)
	{
		ft_printf("%d\n", tmp->nbr);
		tmp = tmp->next;
	}
	ft_printf("%d\n", tmp->nbr);
	ft_printf("\nStack struct status:\n");
	ft_printf("A_stack.head = %d\n", a_stack.head->nbr);
	ft_printf("A_stack.tail = %d\n\n", a_stack.tail->nbr);
	ft_printf("A_stack.len = %d\n\n", a_stack.len);
	return (EXIT_SUCCESS);
}
