/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_rev_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:23:18 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/06 18:27:21 by ccamargo         ###   ########.fr       */
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

/* void	rrr(t_dlist **lst, t_stack *stack)
{

} */

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
