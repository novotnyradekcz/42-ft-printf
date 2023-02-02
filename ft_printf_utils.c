/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:41:11 by rnovotny          #+#    #+#             */
/*   Updated: 2023/02/02 16:33:48 by rnovotny         ###   ########.fr       */
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

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

static int	ft_special(int n)
{
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n == 0)
		return (write(1, "0", 1));
	return (0);
}

int	ft_putnbr(long n)
{
	char	buf[10];
	int		i;
	int		neg;
	int		counter;

	i = 0;
	neg = 0;
	counter = 0;
	if (n == 0)
		return (write(1, "0", 1));
	if (n < 0)
	{
		n = -n;
		neg = 1;
	}
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

int	ft_puthex(int n, int x)
{
	char	buf[8];
	int		i;
	int		neg;
	int		counter;

	i = 0;
	neg = 0;
	counter = 0;
	if (n == -2147483648 || n == 0)
		return (ft_special(n));
	if (n < 0 && n != -2147483648)
	{
		n = -n;
		neg = 1;
	}
	while (n > 0)
	{
		if (n % 16 < 10)
			buf[i] = n % 16 + 48;
		else if (x)
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
