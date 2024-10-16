/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:57:00 by eteofilo          #+#    #+#             */
/*   Updated: 2024/10/16 00:18:14 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	print_u(int n)
{
	int	len;
	if (n < 0)
	{
		len = ft_putnbr(4294967296 + n);
	}
	else
		len = ft_putnbr(n);
	return (len);
}

static int get_arg(va_list *ap, char c)
{
	int	n;

	n = 0;
	if (c == 'c')
		n = ft_putchar(va_arg(*ap, int));
	if (c == 's')
		n = ft_putstr(va_arg(*ap, char *));
	if (c == 'p')
		n = ft_putnbr_ptr(va_arg(*ap, long));
	if (c == 'd' || c == 'i')
		n = ft_putnbr(va_arg(*ap, int));
	if (c == 'u')
		n = print_u(va_arg(*ap, int));
	if (c == 'x')
		n = ft_putnbr_hex(va_arg(*ap, unsigned long), 'x');
	if (c == 'X')
		n = ft_putnbr_hex(va_arg(*ap, unsigned long), 'X');
	if (c == '%')
		n = ft_putchar('%');
	return (n);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int i;

	va_start(ap, str);
	i = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			i += get_arg(&ap, *str);
		}
		else
		{
			ft_putchar(*str);
			i++;
		}
		str++;
	}
	va_end(ap);
	return (i);
}
