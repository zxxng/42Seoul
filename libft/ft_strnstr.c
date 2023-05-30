/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:25:01 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/01/02 13:25:04 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str;
	char	*find;
	size_t	i;
	size_t	j;
	size_t	k;

	str = (char *)haystack;
	find = (char *)needle;
	if (find[0] == '\0')
		return (str);
	i = 0;
	while (str[i] && i < len)
	{
		j = 0;
		k = i;
		while (str[k] == find[j] && k < len)
		{
			k++;
			j++;
			if (!find[j])
				return (&str[k - j]);
		}
		i++;
	}
	return (0);
}
