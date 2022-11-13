/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:27:55 by ccamargo          #+#    #+#             */
/*   Updated: 2022/11/13 18:41:11 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MIN_INT -2147483648
# define MAX_INT 2147483647

# include <libft.h>
# include <ft_printf.h>

typedef struct s_dlist
{
	int				nbr;
	int				index;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

typedef struct s_stack
{
	int		len;
	t_dlist	*head;
	t_dlist	*tail;
}	t_stack;

/* param_validation.c */
int		is_param_valid(char **argv);

/* dlist_utils.c */
t_dlist	*ft_dlstnew(int nbr, int index);
void	ft_dlstadd_front(t_dlist **lst, t_dlist *new);
void	ft_dlstadd_back(t_dlist **lst, t_dlist *new);
t_dlist	*ft_dlstlast(t_dlist *lst);
void	ft_dlstclear(t_dlist **lst);

/* dlist_utils_2.c */
void	ft_dlstdelone(t_dlist *lst);

/* stack_utils_swap.c */
void	sa(t_dlist **lst, t_stack *stack);
void	sb(t_dlist **lst, t_stack *stack);
void	swap(t_dlist **lst, t_stack *stack);

/* stack_utils_push.c */
void	pa(t_dlist **lst1, t_dlist **lst2, t_stack *stack1, t_stack *stack2);
void	pb(t_dlist **lst1, t_dlist **lst2, t_stack *stack1, t_stack *stack2);
void	push(t_dlist **lst1, t_dlist **lst2, t_stack *stack1, t_stack *stack2);

/* stack_utils_rotate.c */
void	ra(t_dlist **lst, t_stack *stack);
void	rb(t_dlist **lst, t_stack *stack);
void	rotate(t_dlist **lst, t_stack *stack);

/* stack_utils_rev_rotate.c */
void	rra(t_dlist **lst, t_stack *stack);
void	rrb(t_dlist **lst, t_stack *stack);
void	rev_rotate(t_dlist **lst, t_stack *stack);

/* stack_initialization.c */
void	initialize_stack(t_dlist **a, t_stack *a_stack, int argc, char **argv);

/* sort_stack.c */
int		is_sorted(t_dlist *lst);
void	sort_stack(t_dlist **a, t_stack *a_stack, t_dlist **b, \
t_stack *b_stack);

/* sort_small.c */
void	sort_2(t_dlist **a, t_stack *a_stack);
void	sort_3(t_dlist **a, t_stack *a_stack);
void	sort_4_5(t_dlist **a, t_stack *a_stack, t_dlist **b, t_stack *b_stack);

/* sort_big_hundred.c */
void	sort_hundred(t_dlist **a, t_stack *a_stack, t_dlist **b, \
t_stack *b_stack);

/* sort_big_five_hundred.c */
void	sort_five_hundred(t_dlist **a, t_stack *a_stack, t_dlist **b, \
t_stack *b_stack);

/* sort_big_utils.c */
void	rotate_up_and_push(t_dlist **a, t_stack *a_stack, int target);
void	rotate_down_and_push(t_dlist **a, t_stack *a_stack, int target);
int		find_biggest(t_dlist *lst, int target);

#endif