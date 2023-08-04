/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:23:25 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/08/01 19:26:58 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_split_size(char *str, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (!str[i])
			break ;
		while (str[i] != c && str[i])
			i++;
		cnt++;
	}
	return (cnt);
}

static char	*ft_strdup_s(char *str, int len)
{
	char	*arr;

	arr = malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	ft_memcpy(arr, str, len);
	arr[len] = '\0';
	return (arr);
}

static char	**ft_free(char **split, int arr)
{
	int	i;

	i = 0;
	while (i < arr)
		free(split[i++]);
	free(split);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		arr;
	char	**split;

	split = malloc(sizeof(char *) * (ft_split_size((char *)s, c) + 1));
	if (!split)
		return (0);
	arr = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (!*s)
			break ;
		i = 0;
		while (s[i] != c && s[i])
			i++;
		split[arr++] = ft_strdup_s((char *)s, i);
		s += i;
		if (!split[arr - 1])
			return (ft_free(split, arr));
	}
	split[arr] = 0;
	return (split);
}
