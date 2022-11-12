/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:13:44 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/12 20:03:33 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_2(t_dlist **a, t_stack *a_stack)
{
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, a_stack);
}

void	sort_3(t_dlist **a, t_stack *a_stack)
{
	int	one;
	int	two;
	int	three;

	one = (*a)->nbr;
	two = (*a)->next->nbr;
	three = (*a)->next->next->nbr;
	if (one < two && two > three && three > one)
	{
		sa(a, a_stack);
		ra(a, a_stack);
	}
	else if (one > two && two > three)
	{
		sa(a, a_stack);
		rra(a, a_stack);
	}
	else if (one > two && two < three && three < one)
		ra(a, a_stack);
	else if (one > two && two < three && three > one)
		sa(a, a_stack);
	else if (one < two && two > three && three < one)
		rra(a, a_stack);
}

void	sort_4_5(t_dlist **a, t_stack *a_stack, t_dlist **b, t_stack *b_stack)
{
	while (a_stack->len > 3)
	{
		if ((*a)->index == 0)
			pb(b, a, b_stack, a_stack);
		else if ((*a)->index == 1 && b_stack->len == 1)
			pb(b, a, b_stack, a_stack);
		else
			rra(a, a_stack);
	}
	sort_3(a, a_stack);
	while (b_stack->len > 0)
		pa(a, b, a_stack, b_stack);
}
