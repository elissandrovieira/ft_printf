/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 22:17:08 by eteofilo          #+#    #+#             */
/*   Updated: 2024/10/16 00:16:16 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	get_len(unsigned long n)
{
	int	len;

	len = 3;
	while (n > 15)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static void	ft_putnbr_base(unsigned long n, char *base)
{
	if (n >= 16)
	{
		ft_putnbr_base(n / 16, base);
		write(1, &base[n % 16], 1);
	}
	if (n < 16)
		write(1, &base[n % 16], 1);
}

int	ft_putnbr_ptr(long int n)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	ft_putnbr_base(n, hex);
	return (get_len(n));
}
