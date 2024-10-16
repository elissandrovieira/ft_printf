/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eteofilo <eteofilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:50:18 by eteofilo          #+#    #+#             */
/*   Updated: 2024/10/16 00:17:54 by eteofilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int				ft_printf(const char *str, ...);
int				ft_putchar(char c);
int				ft_putstr(char *s);
int				ft_putnbr_hex(unsigned int n, char base);
int				ft_putnbr_ptr(long int n);
int				ft_putnbr(long int n);
char			*ft_itoa(long int n);
char			*ft_itoa_hex(unsigned long n, char c);
unsigned long	ft_strlen(const char *s);

#endif
