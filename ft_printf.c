/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:38:38 by rnovotny          #+#    #+#             */
/*   Updated: 2023/01/28 17:59:05 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// IDEA: parse 'format' and count '%' signs = number of arguments
// 		determine type of argument based on char after '%'
//		each type will be handled by a different function
//		function converts argument appropriately and outputs string
//		string is combined with format and output with 'write'
// TODO: finish ft_decide and ft_types

#include "ft_printf.h"

char	*ft_decide(va_list ap, char c)
{
	if (c == 'c')
		return (ft_char(ap, c));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			write(1, &format[i], 1);
		else
		{
			i++;
			ft_putstr_fd(ft_decide(ap, format[i]), 1);
		}
	}
	va_end(ap);
}