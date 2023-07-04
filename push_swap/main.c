/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:25:55 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/04 16:35:47 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_messege(void)
{
	write(1, "Error\n", 6);
	return (1);
}

int	input_length(char **input)
{
	int	i;

	i = 0;
	while (input[i])
		i++;
	return (i);
}

#include <stdio.h>

int	main(int ac, char **av)
{
	t_data	data;
	char	**input;

	if (ac < 2)
		return (0);
	input = parse_input(join_input(ac, av));
	if (!input)
		return (error_messege());
	data.size = input_length(input);
	int *test = char_to_int(input, data.size);
	if (test == NULL)
		return (error_messege());
	//data->raw = char_to_int(input, len);
	int i = 0;
	while (1)
	{
		if (test[i] == 0)
			break;
		printf("test[%d] : %d\n", i, test[i]);
		i++;
	}
}
