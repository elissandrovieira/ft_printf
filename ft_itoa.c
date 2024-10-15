/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:11:21 by eteofilo          #+#    #+#             */
/*   Updated: 2024/10/15 15:09:32 by eteofilo         ###   ########.fr       */
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

static int	get_len(long int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(long int n)
{
	char	*str;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	len = get_len(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	str[len] = '\0';
	len--;
	while (n > 0)
	{
		str[len--] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}
