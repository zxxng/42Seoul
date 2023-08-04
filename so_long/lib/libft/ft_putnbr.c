/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:23:05 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/27 20:43:50 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_putnbr_len(long long n, unsigned int base)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n >= base)
	{
		n = n / base;
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	long long	nb;

	nb = (long long)n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
	return (ft_putnbr_len(n, 10));
}

int	ft_putnbr_un(unsigned int n, unsigned int len, char *base)
{
	unsigned int	nb;

	nb = n;
	if (nb >= len)
		ft_putnbr_un(nb / len, len, base);
	ft_putchar(base[nb % len]);
	return (ft_putnbr_len(n, len));
}

int	ft_putnbr_p(uintptr_t n)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_putnbr_p(n / 16);
		len += ft_putnbr_p(n % 16);
	}
	else if (n < 16)
		len += ft_putchar("0123456789abcdef"[n]);
	return (len);
}
