/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:24:06 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/01/02 13:24:09 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	empty_string(char const *str)
{
	int	len;

	len = ft_strlen(str);
	if (len == 0)
		return (1);
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

char	*ft_strjoin_with_space(char const *s1, char const *s2)
{
	size_t			s1_len;
	size_t			s2_len;
	char			*str;
	unsigned int	i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (empty_string(s2))
		return (NULL);
	str = malloc(sizeof(char) * (s1_len + s2_len + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	str[i++] = ' ';
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
