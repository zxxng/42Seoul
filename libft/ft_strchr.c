/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:23:34 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/01/02 13:23:40 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	tmp;
	char	*arr;

	i = 0;
	tmp = (char)c;
	arr = (char *)s;
	while (arr[i])
	{
		if (arr[i] == tmp)
			return (&arr[i]);
		i++;
	}
	if (!tmp)
		return (&arr[i]);
	return (0);
}
