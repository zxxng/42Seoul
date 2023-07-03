/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:51:26 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/03 19:24:16 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_messege(void)
{
	write(1, "Error\n", 6);
}

int	main(int ac, char **av)
{
	t_node	arr;

	if (ac < 2)
		error_messege();
	if (!(ft_strchr(av[1], " ")))
	{
		arr->inp_arr = ft_split(avp[1]);
	}
	else
	{
		while ()
	}
}
