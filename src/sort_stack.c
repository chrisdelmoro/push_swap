/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:11:51 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/18 00:53:23 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_stack(t_dlist *stack, int len, char ab)
{
	ft_printf("\n");
	while (len)
	{
		ft_printf("%c nbr = %d --- index = %d\n", ab, stack->nbr, stack->index);
		ft_printf("nbr.next = %p --- nbr.prev = %p\n", stack->next, stack->prev);
		stack = stack->next;
		len--;
	}
}

void	print_stack_data(t_stack stack, char ab)
{
	ft_printf("%c_stack.head.nbr = %d\n", ab, stack.head->nbr);
	ft_printf("%c_stack.tail.nbr = %d\n", ab, stack.tail->nbr);
	ft_printf("%c_stack.len = %d\n", ab, stack.len);
}

int	is_sorted(t_dlist *lst, int len)
{
	while (len - 1)
	{
		if (lst->index > lst->next->index)
			return (0);
		lst = lst->next;
		len--;
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
	if (a_stack->len > 5 && a_stack->len <= 100)
		sort_hundred(a, a_stack, b, b_stack);
	if (a_stack->len > 100)
		sort_five_hundred(a, a_stack, b, b_stack);
}
