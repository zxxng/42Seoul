/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_get_next_line_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:04:23 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/05/02 19:40:14 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "before_get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*arr;
	int		len;

	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		*s1 = '\0';
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	arr = malloc(sizeof(char) * len + 1);
	if (!arr)
		return (0);
	ft_memcpy(arr, s1, ft_strlen(s1));
	ft_memcpy(arr + ft_strlen(s1), s2, ft_strlen(s2));
	arr[len] = '\0';
	return (arr);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*arr;

	len = ft_strlen(src);
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (!arr)
		return (0);
	i = 0;
	while (src[i])
	{
		arr[i] = src[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
