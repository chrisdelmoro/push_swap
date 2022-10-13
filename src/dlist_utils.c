/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:56:23 by ccamargo          #+#    #+#             */
/*   Updated: 2022/10/13 17:53:17 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_dlist	*ft_dlstnew(int nbr)
{
	t_dlist	*newnode;

	newnode = malloc(sizeof(t_dlist));
	if (!newnode)
		return (NULL);
	newnode->nbr = nbr;
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*tmp;

	tmp = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_dlstlast(tmp);
	tmp->next = new;
	new->prev = tmp;
	new->next = NULL;
}

t_dlist	*ft_dlstlast(t_dlist *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_dlstadd_front(t_dlist **lst, t_dlist *new)
{
	new->next = *lst;
	new->prev = NULL;
	if (*lst)
		(*lst)->prev = new;
	*lst = new;
}

void	ft_dlstdelone(t_dlist *lst)
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
}
