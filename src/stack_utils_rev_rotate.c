/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_rev_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:23:18 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/13 19:43:40 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rra(t_dlist **lst, t_stack *stack)
{
	rev_rotate(lst, stack);
	ft_printf("rra\n");
}

void	rrb(t_dlist **lst, t_stack *stack)
{
	rev_rotate(lst, stack);
	ft_printf("rrb\n");
}

void	rrr(t_dlist **a, t_dlist **b, t_stack *a_stack, t_stack *b_stack)
{
	rev_rotate(a, a_stack);
	rev_rotate(b, b_stack);
	ft_printf("rrr\n");
}

void	rev_rotate(t_dlist **lst, t_stack *stack)
{
	t_dlist	*tmp;

	if (!*lst || stack->len <= 1)
		return ;
	tmp = stack->tail->prev;
	*lst = stack->tail;
	(*lst)->next = stack->head;
	(*lst)->prev = NULL;
	stack->head->prev = stack->tail;
	tmp->next = NULL;
	stack->tail = tmp;
	stack->head = *lst;
}
