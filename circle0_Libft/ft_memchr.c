/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:21:53 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/01/02 13:21:57 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*res;
	unsigned char	val;
	size_t			i;

	res = (unsigned char *)s;
	val = (unsigned char)c;
	i = 0;
	while (i < n)
	{	
		if (res[i] == val)
			return (&res[i]);
		i++;
	}
	return (0);
}
