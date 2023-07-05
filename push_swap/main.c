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
	exit(1);
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

void	add_node(int data, t_deque *stack_a)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->num = data;
	new_node->prev = stack_a->rear;
	if (stack_a->rear != NULL)
		stack_a->rear -> next = new_node;
	new_node->next = NULL;
	if ((stack_a->front) == NULL)
		stack_a->front = new_node;
	stack_a->rear = new_node;
}

void print_sorted_list(t_deque *deque) {
    t_node *current = deque->front;

    while (current != NULL) {
        printf("%d ", current->num);
        current = current->next;
    }
    printf("\n");
}

int	main(int ac, char **av)
{
	t_deque	*a;
	t_deque *b;
	char	**input;
	int		*tmp;
	int		i;
	int		len;

	if (ac < 2)
		exit(1);
	input = parse_input(join_input(ac, av));
	if (!input)
		return (error_messege());
	len = input_length(input);
	tmp = char_to_int(input, len);
	if (tmp == NULL)
		exit(1);
	a = (t_deque *)malloc(sizeof(t_deque));
	b = (t_deque *)malloc(sizeof(t_deque));
	if (!a || !b)
		exit(1);
	a -> front = NULL;
	a -> rear = NULL;
	a -> size = 0;
	while (tmp[i])
	{
		add_node(tmp[i], a);
		printf("data: %d, num: %d\n", tmp[i], a->rear->num); 
		a->size += 1;
		i++;
	}
	free(tmp);
	free(input);
	deque_quick_sort(a);
	print_sorted_list(a);
}

	// int i = 0;
	// while (1)
	// {
	// 	if (test[i] == 0)
	// 		break;
	// 	printf("test[%d] : %d\n", i, test[i]);
	// 	i++;
	// }
