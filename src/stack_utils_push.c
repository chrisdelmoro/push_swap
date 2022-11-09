/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:23:18 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/09 16:24:01 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

void	push(t_dlist **lst1, t_dlist **lst2, t_stack *stack1, t_stack *stack2)
{
	t_dlist	*tmp;

	if (stack2->len == 0)
		return ;
	ft_dlstadd_front(lst1, ft_dlstnew((*lst2)->nbr, (*lst2)->index));
	stack1->head = *lst1;
	stack1->len++;
	tmp = *lst2;
	*lst2 = (*lst2)->next;
	stack2->head = *lst2;
	ft_dlstdelone(tmp);
	stack2->len--;
}
