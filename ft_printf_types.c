/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:57:14 by rnovotny          #+#    #+#             */
/*   Updated: 2023/02/02 17:45:11 by rnovotny         ###   ########.fr       */
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
	int	h;

	h = va_arg(ap, int);
	if (c == 'x' || c == 'X')
		return (ft_put(h, c));
	return (write(1, "0x", 2) + ft_puthex(h, 0, 'x'));
}
