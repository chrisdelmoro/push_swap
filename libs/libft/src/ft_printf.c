/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:12:42 by ccamargo          #+#    #+#             */
/*   Updated: 2022/08/25 22:35:36 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	ft_parse(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_put_c(va_arg(args, int));
	if (c == 's')
		count += ft_put_s(va_arg(args, char *));
	if (c == 'p')
		count += ft_put_p(va_arg(args, unsigned long));
	if (c == 'd' || c == 'i')
		count += ft_put_di(va_arg(args, int));
	if (c == 'u')
		count += ft_put_u(va_arg(args, unsigned int));
	if (c == 'x')
		count += ft_put_x(va_arg(args, unsigned int), HEX_LOWER);
	if (c == 'X')
		count += ft_put_x(va_arg(args, unsigned int), HEX_UPPER);
	if (c == '%')
		count += ft_put_c('%');
	return (count);
}

static int	ft_vprintf(const char *str, va_list args)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += ft_parse(str[i + 1], args);
			i += 2;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			count++;
			i++;
		}
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (!str)
		return (0);
	va_start(args, str);
	count = ft_vprintf(str, args);
	va_end(args);
	return (count);
}
