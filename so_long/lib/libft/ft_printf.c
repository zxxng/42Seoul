/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:04:34 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/27 20:44:22 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_printf_type(char str, va_list *ap)
{
	int	len;

	len = 0;
	if (str == 'c')
		len += ft_putchar(va_arg(*ap, int));
	else if (str == 's')
		len += ft_putstr(va_arg(*ap, char *));
	else if (str == 'd' || str == 'i')
		len += ft_putnbr(va_arg(*ap, int));
	else if (str == 'u')
		len += ft_putnbr_un(va_arg(*ap, unsigned int), 10, "0123456789");
	else if (str == 'p')
	{
		len += ft_putstr("0x");
		len += ft_putnbr_p(va_arg(*ap, uintptr_t));
	}
	else if (str == 'x')
		len += ft_putnbr_un(va_arg(*ap, unsigned int), 16, "0123456789abcdef");
	else if (str == 'X')
		len += ft_putnbr_un(va_arg(*ap, unsigned int), 16, "0123456789ABCDEF");
	else if (str == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
			len += ft_putchar(str[i++]);
		else
		{
			len += ft_printf_type(str[i + 1], &ap);
			i += 2;
		}
	}
	va_end(ap);
	return (len);
}
