/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:11:21 by eteofilo          #+#    #+#             */
/*   Updated: 2024/10/15 15:37:57 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	if (src == 0)
		return (0);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dest == 0)
		return (0);
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	get_len(unsigned long n)
{
	int	len;

	len = 2;
	while (n > 15)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*ft_itoa_hex(unsigned long n, char c)
{
	char			*base;
	char			*str;
	unsigned long	len;

	if (c == 'l')
		base = "0123456789abcdef";
	if (c == 'U')
		base = "0123456789ABCDEF";
	if (n == 0)
		return (ft_strdup("0"));
	len = get_len(n);
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (0);
	str[len] = '\0';
	len--;
	while (len--)
	{
		if (n > 0)
		{
			str[len] = base[n % 16];
			n /= 16;
		}
	}
	return(str);
}
