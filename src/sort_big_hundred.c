/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_hundred.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:20:19 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/18 02:29:49 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	hold_first(t_dlist *a, int chunk, int len)
{
	int	i;

	i = 0;
	while (len)
	{
		if (a->index >= chunk && a->index < (chunk + 20))
			return (i);
		i++;
		a = a->next;
		len--;
	}
	return (-1);
}

static int	hold_second(t_stack a_stack, int chunk)
{
	t_dlist	*tmp;
	int		len;
	int		i;

	tmp = a_stack.tail;
	len = a_stack.len;
	i = 0;
	while (len)
	{
		if (tmp->index >= chunk && tmp->index < (chunk + 20))
			return (i);
		i++;
		len--;
		tmp = tmp->prev;
	}
	return (-1);
}

static void	sort_and_return_to_a(t_dlist **a, t_stack *a_stack, t_dlist **b, \
t_stack *b_stack)
{
	int	i;

	i = b_stack->len - 1;
	while (b_stack->len > 0)
	{
		if ((*b)->index == i)
		{
			pa(a, b, a_stack, b_stack);
			i--;
		}
		else if (find_biggest(*b, i, b_stack->len) < b_stack->len / 2)
			rb(b, b_stack);
		else
			rrb(b, b_stack);
	}
}

static void	pre_sort_to_b(t_dlist **a, t_stack *a_stack, t_dlist **b, \
t_stack *b_stack)
{
	int	i;
	int	chunk;
	int	first;
	int	second;

	chunk = 0;
	while (a_stack->len > 0)
	{
		i = 0;
		while (i < 20)
		{
			first = hold_first(*a, chunk * 20, a_stack->len);
			second = hold_second(*a_stack, chunk * 20);
			if (first < second)
				rotate_up_and_push(a, a_stack, first);
			else
				rotate_down_and_push(a, a_stack, second);
			pb(b, a, b_stack, a_stack);
			i++;
		}
		chunk++;
	}
	*a = NULL;
}

void	sort_hundred(t_dlist **a, t_stack *a_stack, t_dlist **b, \
t_stack *b_stack)
{
	pre_sort_to_b(a, a_stack, b, b_stack);
	sort_and_return_to_a(a, a_stack, b, b_stack);
}
