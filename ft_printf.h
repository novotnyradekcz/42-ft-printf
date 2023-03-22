/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:38:54 by rnovotny          #+#    #+#             */
/*   Updated: 2023/03/22 19:59:08 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_decide(va_list ap, char c);

int		ft_char(va_list ap);
int		ft_string(va_list ap);
int		ft_int(va_list ap, char c);
int		ft_uint(va_list ap, char c);
int		ft_hex(va_list ap, char c);

int		ft_puthex(unsigned long long n, int neg, char c);
int		ft_putnbr(unsigned int n, int neg);
int		ft_put(long n, char c);
size_t	ft_strlen(const char *str);

#endif