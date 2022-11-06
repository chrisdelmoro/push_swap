/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:23:18 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/06 18:21:33 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

/* void	ss(t_dlist **lst, t_stack *stack)
{

} */

void	swap(t_dlist **lst, t_stack *stack)
{
	t_dlist	*tmp;

	if (stack->len <= 1)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	(*lst)->prev = NULL;
	tmp->next = (*lst)->next;
	(*lst)->next = tmp;
	tmp->prev = *lst;
	stack->head = *lst;
	if (stack->len == 2)
		stack->tail = tmp;
}
