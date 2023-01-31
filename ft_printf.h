/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:38:54 by rnovotny          #+#    #+#             */
/*   Updated: 2023/01/31 10:19:45 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_decide(va_list ap, char c);

int		ft_char(va_list ap, char c);
int		ft_string(va_list ap, char c);

int		ft_putnbr(int n);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);

#endif