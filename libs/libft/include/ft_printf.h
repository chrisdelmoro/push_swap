/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamargo <ccamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:03:01 by ccamargo          #+#    #+#             */
/*   Updated: 2022/08/29 16:57:44 by ccamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

# include <stdarg.h>
# include <libft.h>

int	ft_printf(const char *str, ...);
int	ft_put_c(int c);
int	ft_put_u(unsigned int n);
int	ft_put_x(unsigned long nbr, char *base);
int	ft_put_p(unsigned long ptr);
int	ft_put_s(const char *str);
int	ft_put_di(int nbr);

#endif
