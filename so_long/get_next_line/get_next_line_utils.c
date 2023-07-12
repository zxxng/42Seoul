/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 08:18:55 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/11 20:49:49 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		i;
	int		len;
	char	*arr;

	len = ft_strlen(s1);
	arr = malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char	*res;
	unsigned char	*val;
	size_t			i;

	res = (unsigned char *)dst;
	val = (unsigned char *)src;
	i = 0;
	if (!res && !val)
		return (NULL);
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*arr;
	int		len;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	arr = malloc(sizeof(char) * (len + 1));
	if (!arr)
	{
		free(s1);
		return (NULL);
	}
	ft_memcpy(arr, s1, ft_strlen(s1));
	ft_memcpy(&arr[ft_strlen(s1)], s2, ft_strlen(s2) + 1);
	arr[len] = '\0';
	free(s1);
	return (arr);
}
