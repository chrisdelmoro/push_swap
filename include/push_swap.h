/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:27:55 by ccamargo          #+#    #+#             */
/*   Updated: 2022/10/13 17:54:08 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <ft_printf.h>

typedef struct s_dlist
{
	int				nbr;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

typedef struct s_stack
{
	int		len;
	t_dlist	*head;
	t_dlist	*tail;
}	t_stack;

/* dlist_utils.c */
t_dlist	*ft_dlstnew(int nbr);
void	ft_dlstadd_front(t_dlist **lst, t_dlist *new);
void	ft_dlstadd_back(t_dlist **lst, t_dlist *new);
t_dlist	*ft_dlstlast(t_dlist *lst);
void	ft_dlstclear(t_dlist **lst);

/* dlist_utils_2.c */
void	ft_dlstdelone(t_dlist *lst);

/* stack_utils.c */
void	swap(t_dlist **lst, t_stack *stack);

#endif