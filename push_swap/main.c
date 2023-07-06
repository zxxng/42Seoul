/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:25:55 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/06 17:21:30 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_messege(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	fn(void)
{
	system("leaks push_swap");
}

void	all_free()
{
	
}


int	main(int ac, char **av)
{
	t_deque	*a;
	t_deque	*b;
	char	**input;
	int		*conversion_input;
	int len;

	atexit(fn);
	if (ac < 2)
		exit(1);
	input = parse_input(join_input(ac, av));
	if (!input)
		return (error_messege());
	conversion_input = conversion(input);
	if (!conversion_input)
		return (error_messege());
	a = malloc(sizeof(t_deque));
	b = malloc(sizeof(t_deque));
	if (!a || !b)
		return (error_messege());
	len = input_length(input);
	input_to_node(conversion_input, a, b, len);
	if (a->size < 2)
		return (error_messege());
	sandglass_start(a, b);
	t_node *tmp = a->front;
	while (tmp != a->rear)
	{
		t_node *tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	free(tmp);
	free(a);
	free(b);
	for (int i=0;i < len;i++)
	{
		free(input[i]);
	}
	free(input);
	//exit(0);
}
