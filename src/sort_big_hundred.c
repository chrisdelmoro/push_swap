/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_hundred.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:20:19 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/12 20:12:12 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	hold_first(t_dlist *a, int chunk)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->index >= chunk && a->index < (chunk + 20))
			return (i);
		i++;
		a = a->next;
	}
	return (-1);
}

static int	hold_second(t_stack a_stack, int chunk)
{
	t_dlist	*tmp;
	int		i;

	tmp = a_stack.tail;
	i = 0;
	while (tmp)
	{
		if (tmp->index >= chunk && tmp->index < (chunk + 20))
			return (i);
		i++;
		tmp = tmp->prev;
	}
	return (-1);
}

static void	sort_and_return_to_a(t_dlist **a, t_stack *a_stack, t_dlist **b, \
t_stack *b_stack)
{
	int	i;

	i = b_stack->len - 1;
	while (*b)
	{
		if ((*b)->index == i)
		{
			pa(a, b, a_stack, b_stack);
			i--;
		}
		else if (find_biggest(*b, i) < b_stack->len / 2)
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
	while (chunk < 5)
	{
		i = 0;
		while (i < 20)
		{
			first = hold_first(*a, chunk * 20);
			second = hold_second(*a_stack, chunk * 20);
			if (first < second)
				rotate_up_and_push(a, a_stack, b, b_stack, first);
			else
				rotate_down_and_push(a, a_stack, b, b_stack, second);
			i++;
		}
		chunk++;
	}
}

void	sort_hundred(t_dlist **a, t_stack *a_stack, t_dlist **b, \
t_stack *b_stack)
{
	pre_sort_to_b(a, a_stack, b, b_stack);
	sort_and_return_to_a(a, a_stack, b, b_stack);
}
