/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:25:16 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/01/02 13:25:19 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	tmp;
	char	*arr;

	i = ft_strlen(s) - 1;
	tmp = (char)c;
	arr = (char *)s;
	if (!tmp)
		return (&arr[i + 1]);
	while (i >= 0)
	{
		if (arr[i] == tmp)
			return (&arr[i]);
		i--;
	}
	return (0);
}
