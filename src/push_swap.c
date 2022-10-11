/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:26:57 by ccamargo          #+#    #+#             */
/*   Updated: 2022/10/11 19:58:35 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_dlist		*head;
	t_dlist		*tmp;
	size_t		i;

	if (argc < 2)
	{
		ft_printf("At least two parameters are necessary!\n");
		exit(EXIT_FAILURE);
	}
	head = ft_dlstnew(ft_atoi(argv[1]));
	i = 2;
	while (argv[i])
	{
		ft_dlstadd_front(&head, ft_dlstnew(ft_atoi(argv[i])));
		i++;
	}
	ft_dlstdelone(head->next);
	tmp = head;
	while (tmp->next)
	{
		ft_printf("%d\n", tmp->nbr);
		tmp = tmp->next;
	}
	ft_printf("%d\n", tmp->nbr);
	ft_dlstclear(&head);
	return (EXIT_SUCCESS);
}
