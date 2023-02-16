/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:41:11 by rnovotny          #+#    #+#             */
/*   Updated: 2023/02/16 19:04:22 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int	n;

	n = 0;
	while (str[n] != 0)
		n++;
	return (n);
}

int	ft_put(long n, char c)
{
	int	neg;
	int	counter;

	neg = 0;
	counter = 0;
	if (n == 0)
		return (write(1, "0", 1));
	if (n < 0)
	{
		n = -n;
		neg = 1;
	}
	if (c == 'd' || c == 'i' || c == 'u')
		counter += ft_putnbr(n, neg);
	if (c == 'x' || c == 'X')
		counter += ft_puthex(n, neg, c);
	return (counter);
}

int	ft_putnbr(long n, int neg)
{
	char	buf[10];
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (n > 0)
	{
		buf[i] = n % 10 + 48;
		n = n / 10;
		i++;
	}
	if (neg)
		counter += write(1, "-", 1);
	while (i > 0)
	{
		i--;
		counter += write(1, &buf[i], 1);
	}
	return (counter);
}

int	ft_puthex(long long n, int neg, char c)
{
	char	buf[16];
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	while (n > 0)
	{
		if (n % 16 < 10)
			buf[i] = n % 16 + 48;
		else if (c == 'X')
			buf[i] = n % 16 + 55;
		else
			buf[i] = n % 16 + 87;
		n = n / 16;
		i++;
	}
	if (neg)
		counter += write(1, "-", 1);
	while (i > 0)
	{
		i--;
		counter += write(1, &buf[i], 1);
	}
	return (counter);
}
