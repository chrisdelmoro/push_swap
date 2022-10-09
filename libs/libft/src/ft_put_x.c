/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:39:35 by ccamargo          #+#    #+#             */
/*   Updated: 2022/08/25 22:33:41 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_put_x(unsigned long nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr / 16 > 0)
		count += ft_put_x(nbr / 16, base);
	ft_putchar_fd(base[nbr % 16], 1);
	return (count + 1);
}
