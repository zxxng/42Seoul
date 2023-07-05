/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:25:55 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/05 20:05:43 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_messege(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

#include <stdio.h>
int	main(int ac, char **av)
{
	t_deque	*a;
	t_deque	*b;
	char	**input;
	int		*conversion_input;
	int		i;

	if (ac < 2)
		exit(1);
	input = parse_input(join_input(ac, av));
	if (!input)
		return (error_messege());
	conversion_input = conversion(input);
	a = malloc(sizeof(t_deque));
	b = malloc(sizeof(t_deque));
	if (!a || !b)
		exit(1);
	input_to_node(conversion_input, &a);
	free(input);
}
