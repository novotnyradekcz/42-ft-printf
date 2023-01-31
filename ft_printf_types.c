/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:57:14 by rnovotny          #+#    #+#             */
/*   Updated: 2023/01/31 10:20:53 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(va_list ap, char c)
{
	char a;

	a = (char) va_arg(ap, int);
	return (write(1, &a, 1));
}

int	ft_string(va_list ap, char c)
{
	char *str;

	str = va_arg(ap, char *);
	return (write(1, str, ft_strlen(str)));
}

int	ft_int(va_list ap, char c)
{
	char a;

	a = (char) va_arg(ap, int);
	return (write(1, &a, 1));
}
