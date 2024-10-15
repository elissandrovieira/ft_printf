/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:50:18 by eteofilo          #+#    #+#             */
/*   Updated: 2024/10/14 23:37:59 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int				ft_printf(const char *str, ...);
void			ft_putnbr_hex(unsigned long n, char c);
void			ft_putnbr(long int n);
void			ft_putchar(char c);
void			ft_putstr(char *s);
unsigned long	ft_strlen(const char *s);

#endif
