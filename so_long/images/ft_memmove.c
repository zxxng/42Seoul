/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:22:23 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/11 20:19:52 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char	*res;
	unsigned char	*val;
	size_t			i;

	res = (unsigned char *)dst;
	val = (unsigned char *)src;
	i = 0;
	if (!res && !val)
		return (0);
	if ((size_t)dst - (size_t)val < len)
	{
		i = len - 1;
		while (i < len)
		{
			res[i] = val[i];
			i--;
		}
	}
	else
		res = ft_memcpy(res, val, len);
	return (res);
}
