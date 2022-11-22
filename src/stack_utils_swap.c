/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:23:18 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/22 19:45:06 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	swap(t_dlist **lst, t_stack *stack)
{
	t_dlist	*tmp;

	if (stack->len <= 1)
		return ;
	stack->tail->next = (*lst)->next;
	(*lst)->next->next->prev = *lst;
	tmp = *lst;
	*lst = (*lst)->next;
	(*lst)->prev = stack->tail;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
	tmp->prev = *lst;
	stack->head = *lst;
	if (stack->len == 2)
		stack->tail = tmp;
}

void	sa(t_dlist **lst, t_stack *stack)
{
	swap(lst, stack);
	ft_printf("sa\n");
}

void	sb(t_dlist **lst, t_stack *stack)
{
	swap(lst, stack);
	ft_printf("sb\n");
}

void	ss(t_dlist **a, t_dlist **b, t_stack *a_stack, t_stack *b_stack)
{
	sa(a, a_stack);
	sb(b, b_stack);
	ft_printf("ss\n");
}
