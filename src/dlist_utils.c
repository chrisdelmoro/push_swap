/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:56:23 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/20 01:06:41 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_dlist	*ft_dlstnew(int nbr, int index)
{
	t_dlist	*newnode;

	newnode = malloc(sizeof(t_dlist));
	if (!newnode)
		return (NULL);
	newnode->nbr = nbr;
	newnode->index = index;
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new, t_stack *stack)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (stack->len == 1)
	{
		(*lst)->next = new;
		(*lst)->prev = new;
		new->prev = *lst;
		new->next = *lst;
	}
	else
	{
		new->prev = (*lst)->prev;
		new->next = *lst;
		(*lst)->prev->next = new;
		(*lst)->prev = new;
	}
	stack->tail = new;
	stack->len++;
}

void	ft_dlstadd_front(t_dlist **lst, t_dlist *new, t_stack *stack)
{
	if (!*lst)
	{
		*lst = new;
		(*lst)->next = *lst;
		(*lst)->prev = *lst;
		stack->head = new;
		stack->tail = new;
		stack->len++;
		return ;
	}
	else
	{
		new->prev = (*lst)->prev;
		new->next = *lst;
		(*lst)->prev->next = new;
		(*lst)->prev = new;
	}
	*lst = new;
	stack->head = new;
	stack->tail = new->prev;
	stack->len++;
}

void	ft_dlstdelone(t_dlist *lst, t_stack *stack)
{
	t_dlist	*prevlst;
	t_dlist	*nextlst;

	if (!lst)
		return ;
	prevlst = lst->prev;
	nextlst = lst->next;
	if (lst->prev)
		prevlst->next = nextlst;
	if (lst->next)
		nextlst->prev = prevlst;
	free(lst);
	stack->len--;
}

void	ft_dlstclear(t_dlist **lst, t_stack *stack)
{
	t_dlist	*tmp;
	t_dlist	*nxt;
	int		i;

	if (!lst)
		return ;
	tmp = *lst;
	i = 0;
	while (i < stack->len)
	{
		nxt = tmp->next;
		ft_dlstdelone(tmp, stack);
		tmp = nxt;
	}
	*lst = NULL;
}
