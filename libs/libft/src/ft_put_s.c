/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:59:19 by ccamargo          #+#    #+#             */
/*   Updated: 2022/08/25 22:33:32 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_put_s(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		count += 6;
	}
	else
	{
		ft_putstr_fd(str, 1);
		count += ft_strlen(str);
	}
	return (count);
}
