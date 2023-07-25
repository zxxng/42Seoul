/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:22:32 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/25 19:30:54 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*res;
	unsigned char	val;

	res = (unsigned char *)b;
	val = (unsigned char)c;
	i = 0;
	while (i < len)
		res[i++] = val;
	return (res);
}
