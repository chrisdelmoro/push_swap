/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:11:51 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/09 16:40:38 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_stack(t_dlist *stack, char ab)
{
	ft_printf("\n");
	while (stack)
	{
		ft_printf("%c nbr = %d --- index = %d\n", ab, stack->nbr, stack->index);
		stack = stack->next;
	}
}

static void	rotate_up_and_push(t_dlist **a, t_stack *a_stack, t_dlist **b, t_stack *b_stack, int target)
{
	int	i;

	i = 0;
	while (i <= target)
	{
		ra(a, a_stack);
		i++;
	}
	pb(b, a, b_stack, a_stack);

	/* while ((*a)->nbr != target)
	{
		ra(a, a_stack);
	}
	pb(b, a, b_stack, a_stack); */
}

static void	rotate_down_and_push(t_dlist **a, t_stack *a_stack, t_dlist **b, t_stack *b_stack, int target)
{
	int	i;

	i = 0;
	while (i <= target)
	{
		rra(a, a_stack);
		i++;
	}
	pb(b, a, b_stack, a_stack);

	/* while ((*a)->nbr != target)
	{
		rra(a, a_stack);
	}
	pb(b, a, b_stack, a_stack); */
}

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

static void	sort_hundred(t_dlist **a, t_stack *a_stack, t_dlist **b, t_stack *b_stack)
{
	int	i;
	int chunk;
	int first;
	int second;

	chunk = 0;
	while (chunk < 5)
	{
		i = 0;
		while (i < 20)
		{
			first = hold_first(*a, chunk * 20);
			second = hold_second(*a_stack, chunk * 20);
			if (first > second)
			{
				rotate_up_and_push(a, a_stack, b, b_stack, first);
			}
			else
			{
				rotate_down_and_push(a, a_stack, b, b_stack, second);
			}
			i++;
		}
		chunk++;
	}
}

int		is_sorted(t_dlist *lst)
{
	while (lst->next)
	{
		if (lst->index > lst->next->index)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	sort_two(t_dlist **a, t_stack *a_stack)
{
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, a_stack);
}

void	sort_three(t_dlist **a, t_stack *a_stack)
{
	if ((*a)->nbr > (*a)->next->nbr && (*a)->nbr < (*a)->next->next->nbr)
	{
		sa(a, a_stack);
		return ;
	}
	if ((*a)->nbr > (*a)->next->nbr && (*a)->next->nbr > (*a)->next->next->nbr)
	{
		sa(a, a_stack);
		rra(a, a_stack);
		return;
	}
	if ((*a)->nbr > (*a)->next->nbr && (*a)->next->nbr < (*a)->next->next->nbr)
	{
		ra(a, a_stack);
		return;
	}
	if ((*a)->nbr < (*a)->next->nbr && (*a)->nbr < (*a)->next->next->nbr)
	{
		sa(a, a_stack);
		ra(a, a_stack);
		return ;
	}
	if ((*a)->nbr < (*a)->next->nbr && (*a)->next->nbr > (*a)->next->next->nbr)
		rra(a, a_stack);
}

void	sort_five(t_dlist **a, t_stack *a_stack, t_dlist **b, t_stack *b_stack)
{
	pb(b, a, b_stack, a_stack);
	pb(b, a, b_stack, a_stack);
	sort_three(a, a_stack);
	pa(a, b, a_stack, b_stack);
	while (!is_sorted(*a))
		ra(a, a_stack);
	pa(a, b, a_stack, b_stack);
	while (!is_sorted(*a))
		ra(a, a_stack);
}

void	sort_stack(t_dlist **a, t_stack *a_stack, t_dlist **b, t_stack *b_stack)
{
	if (a_stack->len == 2)
		sort_two(a, a_stack);
	if (a_stack->len == 3)
		sort_three(a, a_stack);
	if (a_stack->len > 3 && a_stack->len <= 5)
		sort_five(a, a_stack, b, b_stack);
	if (a_stack->len > 10 && a_stack->len <= 100)
		sort_hundred(a, a_stack, b, b_stack);
	/* if (a_stack->len > 100)
		sort_five_hundred(); */
}