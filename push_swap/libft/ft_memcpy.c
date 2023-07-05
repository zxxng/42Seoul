/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:22:11 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/05 18:32:15 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*res;
	unsigned char	*val;

	res = (unsigned char *)dst;
	val = (unsigned char *)src;
	i = 0;
	if (res != val && n)
	{
		while (i < n)
		{
			res[i] = val[i];
			i++;
		}
	}
	return (res);
}
