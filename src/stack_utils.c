/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:23:18 by ccamargo          #+#    #+#             */
/*   Updated: 2022/10/14 20:44:30 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

void	push(t_dlist **lst1, t_dlist **lst2, t_stack *stack1, t_stack *stack2)
{
	t_dlist	*tmp;

	if (stack2->len == 0)
		return ;
	ft_dlstadd_front(lst1, ft_dlstnew((*lst2)->nbr));
	stack1->head = *lst1;
	stack1->len++;
	tmp = *lst2;
	*lst2 = (*lst2)->next;
	stack2->head = *lst2;
	ft_dlstdelone(tmp);
	stack2->len--;
}

void	rotate(t_dlist **lst, t_stack *stack)
{
	t_dlist *tmp;

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

