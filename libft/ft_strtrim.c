/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:25:31 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/01/02 13:25:34 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fill_arr(int start, int end, char const *s1)
{
	char	*arr;
	int		idx;

	arr = malloc(sizeof(char) * (end - start + 1));
	if (!arr)
		return (0);
	idx = 0;
	while (start < end)
		arr[idx++] = s1[start++];
	arr[idx] = '\0';
	return (arr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		idx;

	len = ft_strlen(s1);
	idx = 0;
	while (s1[idx] && ft_strchr(set, s1[idx]) != 0)
		idx++;
	if (idx >= len)
		return (ft_strdup(""));
	while (len > 0 && ft_strchr(set, s1[len - 1]) != 0)
		len--;
	return (fill_arr(idx, len, s1));
}
