/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:57:14 by rnovotny          #+#    #+#             */
/*   Updated: 2023/02/19 18:49:57 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(va_list ap)
{
	char	a;

	a = (char) va_arg(ap, int);
	return (write(1, &a, 1));
}

int	ft_string(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_int(va_list ap, char c)
{
	int	i;

	i = va_arg(ap, int);
	return (ft_put(i, c));
}

int	ft_uint(va_list ap, char c)
{
	unsigned int	i;

	i = va_arg(ap, unsigned int);
	return (ft_put(i, c));
}

int	ft_hex(va_list ap, char c)
{
	long long	h;

	h = va_arg(ap, long long);
	if (c == 'x' || c == 'X')
		return (ft_put(h, c));
	if (c == 'p' && h == 0)
		return (write(1, "(nil)", 5));
	return (write(1, "0x", 2) + ft_puthex(h, 0, 'x'));
}
