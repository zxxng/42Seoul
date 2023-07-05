/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:25:55 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/05 22:21:06 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_messege(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

//#include <stdio.h>
//void print_deque(t_deque *deque)
//{
//  printf("size : %d\n",deque->size);
//  t_node *current;
//	current = deque->front;
//  for (int i = 0; i < deque->size; ++i)
//  {
//    printf("%d ", currnt->num);
//	current = current->next;
//  }
//  printf("\n");
//
//}

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
	if (!conversion_input)
		return (error_messege());
	a = malloc(sizeof(t_deque));
	b = malloc(sizeof(t_deque));
	if (!a || !b)
		exit(1);
	input_to_node(conversion_input, a);
	//print_deque(a);
	free(input);
}
