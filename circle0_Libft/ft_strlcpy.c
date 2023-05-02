/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:24:27 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/01/02 13:24:30 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	idx;
	size_t	len;

	idx = 0;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (idx < len && idx + 1 < size)
	{
		dest[idx] = src[idx];
		idx++;
	}
	dest[idx] = '\0';
	return (len);
}
