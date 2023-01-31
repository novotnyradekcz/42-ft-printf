/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:38:38 by rnovotny          #+#    #+#             */
/*   Updated: 2023/01/31 10:20:27 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// IDEA: parse 'format' and count '%' signs = number of arguments
// 		determine type of argument based on char after '%'
//		each type will be handled by a different function
//		function converts argument appropriately and outputs string
//		string is combined with format and output with 'write'
// TODO: finish ft_decide and ft_types

#include "ft_printf.h"

int	ft_decide(va_list ap, char c)
{
	if (c == 'c')
		return (ft_char(ap, c));
	if (c == 's')
		return (ft_string(ap, c));
	if (c == 'p')
		return (ft_char(ap, c));
	if (c == 'd')
		return (ft_char(ap, c));
	if (c == 'i')
		return (ft_int(ap, c));
	if (c == 'u')
		return (ft_char(ap, c));
	if (c == 'x' || c == 'X')
		return (ft_char(ap, c));
	if (c == '%')
		return (write(1, "%", 1));
	else
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
	}
	va_end(ap);
	return (counter);
}
