/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:57:00 by eteofilo          #+#    #+#             */
/*   Updated: 2024/10/14 23:42:38 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void get_arg(va_list *ap, char c)
{
	int i;

	i = 0;
	if (c == 'c')
		ft_putchar(va_arg(*ap, int));
	if (c == 's')
		ft_putstr(va_arg(*ap, char *));
	if (c == 'p')
	{
		ft_putstr("0x");
		ft_putnbr_hex(va_arg(*ap, unsigned long), 'l');
	}
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(*ap, int));
	if (c == 'u')
	{
		i = va_arg(*ap, int);
		if (i < 0)
		{
			ft_putnbr(4294967296 - i);
		}
		else
			ft_putnbr(i);
	}
	if (c == 'x')
		ft_putnbr_hex(va_arg(*ap, unsigned long), 'l');
	if (c == 'X')
		ft_putnbr_hex(va_arg(*ap, unsigned long), 'U');
	if (c == '%')
		ft_putchar('%');
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			get_arg(&ap, *str);
		}
		else
			ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (0);
}
