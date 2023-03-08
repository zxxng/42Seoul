/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:23:19 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/01/12 17:25:59 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr_len(long long n, unsigned int base);
int	ft_putnbr(int n);
int	ft_putnbr_un(unsigned int n, unsigned int len, char *base);
int	ft_putnbr_p(uintptr_t n);
int	ft_printf_type(char str, va_list *ap);
int	ft_printf(const char *str, ...);

#endif
