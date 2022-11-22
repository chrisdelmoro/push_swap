/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:23:18 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/22 19:45:59 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	push(t_dlist **lst1, t_dlist **lst2, t_stack *stack1, \
t_stack *stack2)
{
	t_dlist	*tmp;

	if (stack2->len == 0)
		return ;
	ft_dlstadd_front(lst1, ft_dlstnew((*lst2)->nbr, (*lst2)->index), stack1);
	if (stack1->len == 1)
	{
		stack1->head = *lst1;
		stack1->tail = *lst1;
	}
	tmp = *lst2;
	*lst2 = (*lst2)->next;
	ft_dlstdelone(tmp, stack2);
	stack2->head = *lst2;
	if (stack2->len == 0)
		stack2->tail = NULL;
}

void	pa(t_dlist **lst1, t_dlist **lst2, t_stack *stack1, t_stack *stack2)
{
	push(lst1, lst2, stack1, stack2);
	ft_printf("pa\n");
}

void	pb(t_dlist **lst1, t_dlist **lst2, t_stack *stack1, t_stack *stack2)
{
	push(lst1, lst2, stack1, stack2);
	ft_printf("pb\n");
}
