/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:57:00 by eteofilo          #+#    #+#             */
/*   Updated: 2024/10/15 16:03:33 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static char *print_u(int n)
{
	char *str;
	if (n < 0)
	{
		str = ft_itoa(4294967296 + n);
	}
	else
		str = ft_itoa(n);
	return (str);
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
	{
		n = ft_putstr("0x");
		n += ft_putstr(ft_itoa_hex(va_arg(*ap, unsigned long), 'l'));
	}
	if (c == 'd' || c == 'i')
		n = ft_putstr(ft_itoa(va_arg(*ap, int)));
	if (c == 'u')
		n = ft_putstr(print_u(va_arg(*ap, int)));
	if (c == 'x')
		n = ft_putstr(ft_itoa_hex(va_arg(*ap, unsigned long), 'l'));
	if (c == 'X')
		n = ft_putstr(ft_itoa_hex(va_arg(*ap, unsigned long), 'U'));
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
