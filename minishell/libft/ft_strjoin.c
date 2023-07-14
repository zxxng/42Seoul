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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	arr = malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	ft_memcpy(arr, s1, ft_strlen(s1));
	ft_memcpy(&arr[ft_strlen(s1)], s2, ft_strlen(s2) + 1);
	return (arr);
}
