/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:38:38 by rnovotny          #+#    #+#             */
/*   Updated: 2023/01/28 16:52:11 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: parse 'string' and count '%' signs = number of arguments
// 		determine type of argument based on char after '%'
//		argument types: char, char *, long, double

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);

	va_end(ap);
}