/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:05:27 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/12 20:07:56 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rotate_up_and_push(t_dlist **a, t_stack *a_stack, t_dlist **b, t_stack *b_stack, int target)
{
	int	i;

	i = 0;
	while (i < target)
	{
		ra(a, a_stack);
		i++;
	}
	pb(b, a, b_stack, a_stack);
}

void	rotate_down_and_push(t_dlist **a, t_stack *a_stack, t_dlist **b, t_stack *b_stack, int target)
{
	int	i;

	i = 0;
	while (i <= target)
	{
		rra(a, a_stack);
		i++;
	}
	pb(b, a, b_stack, a_stack);
}

int	find_biggest(t_dlist *lst, int target)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->index == target)
			return (i);
		i++;
		lst = lst->next;
	}
	return (-1);
}
