/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:38:38 by rnovotny          #+#    #+#             */
/*   Updated: 2023/02/09 12:18:58 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	not working according to tester:	p, x, X, mix

#include "ft_printf.h"

int	ft_decide(va_list ap, char c)
{
	if (c == 'c')
		return (ft_char(ap));
	if (c == 's')
		return (ft_string(ap));
	if (c == 'p')
		return (ft_hex(ap, c));
	if (c == 'd')
		return (ft_int(ap, c));
	if (c == 'i')
		return (ft_int(ap, c));
	if (c == 'u')
		return (ft_uint(ap, c));
	if (c == 'x' || c == 'X')
		return (ft_hex(ap, c));
	if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			counter += write(1, &format[i], 1);
		else
		{
			i++;
			counter += ft_decide(ap, format[i]);
		}
		i++;
	}
	va_end(ap);
	return (counter);
}
