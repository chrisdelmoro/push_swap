/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:23:18 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/22 19:45:16 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	rotate(t_dlist **lst, t_stack *stack)
{
	if (!*lst || stack->len <= 1)
		return ;
	*lst = (*lst)->next;
	stack->head = *lst;
	stack->tail = (*lst)->prev;
}

void	ra(t_dlist **lst, t_stack *stack)
{
	rotate(lst, stack);
	ft_printf("ra\n");
}

void	rb(t_dlist **lst, t_stack *stack)
{
	rotate(lst, stack);
	ft_printf("rb\n");
}

void	rr(t_dlist **a, t_dlist **b, t_stack *a_stack, t_stack *b_stack)
{
	rotate(a, a_stack);
	rotate(b, b_stack);
	ft_printf("rr\n");
}
