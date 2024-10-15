/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:19:12 by eteofilo          #+#    #+#             */
/*   Updated: 2024/10/15 16:05:28 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
	{
		write(1, "0", 6);
		return (0);
	}
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}
