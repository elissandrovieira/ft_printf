/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 21:45:33 by eteofilo          #+#    #+#             */
/*   Updated: 2024/10/14 23:30:52 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_hex(unsigned long n, char c)
{
	char	*hex;

	if (c == 'l')
		hex = "0123456789abcdef";
	if (c == 'U')
		hex = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_putnbr_hex(n / 16, c);
		write(1, &hex[n % 16], 1);
	}
	if (n < 16)
	{
		write(1, &hex[n % 16], 1);
	}
}
