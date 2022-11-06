/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:23:18 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/06 18:25:20 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

/* void	rr(t_dlist **lst, t_stack *stack)
{

} */

void	rotate(t_dlist **lst, t_stack *stack)
{
	t_dlist	*tmp;

	if (!*lst || stack->len <= 1)
		return ;
	tmp = stack->head;
	*lst = (*lst)->next;
	(*lst)->prev = NULL;
	tmp->prev = stack->tail;
	tmp->next = NULL;
	stack->tail->next = tmp;
	stack->head = *lst;
	stack->tail = tmp;
}
