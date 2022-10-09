/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 20:45:08 by ccamargo          #+#    #+#             */
/*   Updated: 2022/08/25 22:33:25 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_put_di(int nbr)
{
	char	*nbr_to_str;
	int		count;

	count = 0;
	nbr_to_str = ft_itoa(nbr);
	count += ft_strlen(nbr_to_str);
	ft_putstr_fd(nbr_to_str, 1);
	ft_freethis(&nbr_to_str, NULL);
	return (count);
}
