/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 18:36:52 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/05 22:20:36 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_length(char **input)
{
	int	i;

	i = 0;
	while (input[i])
		i++;
	return (i);
}

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

void	input_to_node(int *conversion_input, t_deque *a)
{
	int	i;

	a->front = NULL;
	a->rear = NULL;
	a->size = 0;
	i = 0;
	while (conversion_input[i])
	{
		add_node(conversion_input[i], a);
		a->size += 1;
		i++;
	}
	free(conversion_input);
}

int	*conversion(char **original_input)
{
	int	*input;
	int	*sort_input;
	int	len;
	int	i;
	int	j;

	len = input_length(original_input);
	input = char_to_int(original_input, len);
	if (!input)
		return (NULL);
	sort_input = sort_array(input, len);
	if (!sort_input)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (input[i] == sort_input[j])
				input[i] = j;
		}
	}
	free(sort_input);
	return (input);
}
