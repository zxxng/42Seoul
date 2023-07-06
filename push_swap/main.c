/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:25:55 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/06 21:25:25 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_messege(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	input_free(char **input, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(input[i++]);
	free(input);
}

void	all_free(t_deque *a, t_deque *b)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = a->front;
	while (tmp != a->rear)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	free(tmp);
	free(a);
	free(b);
}

int	push_swap(int *conversion_input, int len)
{
	t_deque	*a;
	t_deque	*b;

	a = malloc(sizeof(t_deque));
	if (!a)
		return (0);
	b = malloc(sizeof(t_deque));
	if (!b)
		return (0);
	input_to_node(conversion_input, a, b, len);
	if (a->size < 2)
		return (0);
	sandglass_start(a, b);
	all_free(a, b);
	return (1);
}

int	main(int ac, char **av)
{
	char	**input;
	int		*conversion_input;
	int		len;

	if (ac < 2)
		exit(1);
	input = parse_input(join_input(ac, av));
	if (!input)
		return (error_messege());
	len = input_length(input);
	conversion_input = conversion(input);
	if (!conversion_input)
		return (error_messege());
	input_free(input, len);
	if (!push_swap(conversion_input, len))
		return (error_messege());
	exit(0);
}
