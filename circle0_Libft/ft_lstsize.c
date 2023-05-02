/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:12:50 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/01/04 13:32:00 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	cnt;

	if (lst == 0)
		return (0);
	cnt = 1;
	while (lst->next)
	{
		cnt++;
		lst = lst->next;
	}
	return (cnt);
}
