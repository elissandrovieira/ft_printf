/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:57:00 by eteofilo          #+#    #+#             */
/*   Updated: 2024/10/14 16:52:23 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void get_arg(va_list *ap, char c)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(*ap, char), 1);
	if (c == 's')
		ft_putstr_fd(va_arg(*ap, char *), 1);
	if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(ft_itoa_hex((unsigned long)ap), 1);
	}
	if (c == 'd')
	{

	}




}

int	ft_printf(const char *str, ...)
{
	va_list	ap;

	va_start(ap, str);
	while (str)
	{
		if (str == '%')
		{
			get_arg();
			str++;
		}
		ft_putstr_fd(str, 1);
		str++;
	}
	va_end(ap);
}
