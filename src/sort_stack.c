/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:11:51 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/12 20:04:06 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_stack(t_dlist *stack, char ab)
{
	ft_printf("\n");
	while (stack)
	{
		ft_printf("%c nbr = %d --- index = %d\n", ab, stack->nbr, stack->index);
		stack = stack->next;
	}
}

int	is_sorted(t_dlist *lst)
{
	while (lst->next)
	{
		if (lst->index > lst->next->index)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	sort_stack(t_dlist **a, t_stack *a_stack, t_dlist **b, t_stack *b_stack)
{
	if (a_stack->len == 2)
		sort_2(a, a_stack);
	if (a_stack->len == 3)
		sort_3(a, a_stack);
	if (a_stack->len > 3 && a_stack->len <= 5)
		sort_4_5(a, a_stack, b, b_stack);
	if (a_stack->len > 10 && a_stack->len <= 100)
		sort_hundred(a, a_stack, b, b_stack);
	/* if (a_stack->len > 100)
		sort_five_hundred(); */
}
