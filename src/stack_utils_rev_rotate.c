/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_rev_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:23:18 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/22 19:45:29 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	rev_rotate(t_dlist **lst, t_stack *stack)
{
	if (!*lst || stack->len <= 1)
		return ;
	*lst = (*lst)->prev;
	stack->head = *lst;
	stack->tail = (*lst)->prev;
}

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
