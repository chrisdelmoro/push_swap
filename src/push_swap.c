/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:26:57 by ccamargo          #+#    #+#             */
/*   Updated: 2022/10/13 17:50:21 by ccamargo         ###   ########.fr       */
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

	if (argc < 2)
	{
		ft_printf("At least two parameters are necessary!\n");
		exit(EXIT_FAILURE);
	}
	initialize_stack_a(&a, &a_stack, argc, argv);
	tmp = a;
	while (tmp->next)
	{
		ft_printf("%d\n", tmp->nbr);
		tmp = tmp->next;
	}
	ft_printf("%d\n", tmp->nbr);
	ft_printf("\nStack struct status:\n");
	ft_printf("A_stack.head = %d\n", a_stack.head->nbr);
	ft_printf("A_stack.tail = %d\n", a_stack.tail->nbr);
	//swap(&a, &a_stack);
	tmp = a;
	while (tmp->next)
	{
		ft_printf("%d\n", tmp->nbr);
		tmp = tmp->next;
	}
	ft_printf("%d\n", tmp->nbr);
	ft_printf("\nStack struct status:\n");
	ft_printf("A_stack.head = %d\n", a_stack.head->nbr);
	ft_printf("A_stack.tail = %d\n", a_stack.tail->nbr);
	/* head = ft_dlstnew(ft_atoi(argv[1]));
	i = 2;
	while (argv[i])
	{
		ft_dlstadd_front(&head, ft_dlstnew(ft_atoi(argv[i])));
		i++;
	}
	ft_dlstdelone(head->next);
	tmp = head;
	while (tmp->next)
	{
		ft_printf("%d\n", tmp->nbr);
		tmp = tmp->next;
	}
	ft_printf("%d\n", tmp->nbr);
	ft_dlstclear(&head); */
	return (EXIT_SUCCESS);
}
