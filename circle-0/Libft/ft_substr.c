/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:25:43 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/01/04 15:22:21 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	s_len;
	size_t	i;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	s_len = ft_strlen(s);
	if (s_len - start < len)
		len = s_len - start;
	arr = malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	i = 0;
	while (i < len && s[start])
	{
		arr[i++] = s[start++];
	}
	arr[i] = '\0';
	return (arr);
}
