/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:21:41 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/01/02 13:21:47 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	arr_size(long long n)
{
	int	cnt;

	cnt = 0;
	if (n <= 0)
	{
		cnt++;
		n = -n;
	}
	while (n > 0)
	{
		cnt++;
		n = n / 10;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	long long	nb;
	int			len;
	char		*res;

	nb = n;
	len = arr_size(nb);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	if (nb == 0)
		res[0] = '0';
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	res[len] = '\0';
	len -= 1;
	while (nb > 0)
	{
		res[len--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (res);
}
