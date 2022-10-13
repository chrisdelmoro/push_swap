/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:53:32 by ccamargo          #+#    #+#             */
/*   Updated: 2022/10/13 17:54:22 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_dlstclear(t_dlist **lst)
{
	t_dlist	*tmp;
	t_dlist	*nxt;

	if (!lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		nxt = tmp->next;
		ft_dlstdelone(tmp);
		tmp = nxt;
	}
	*lst = NULL;
}
