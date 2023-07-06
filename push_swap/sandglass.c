/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandglass.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:56:50 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/06 16:05:43 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_node(t_deque *b, int length)
{
	int		counter;
	int		flag;
	t_node	*current;

	counter = 0;
	flag = 1;
	current = b->front;
	while (counter <= length / 2)
	{
		if (current->num == length)
		{
			flag = 0;
			break ;
		}
		counter++;
		current = current->next;
	}
	if (flag == 0)
		return (0);
	else
		return (1);
}

static void	sort_b(t_deque *b, int length)
{
	int	flag;

	flag = find_node(b, length);
	while (b->front->num != length)
	{
		if (flag == 0)
			rotate(b, 'b');
		else
			reverse_rotate(b, 'b');
	}
}

static void	b_to_a(t_deque *a, t_deque *b)
{
	int	length;

	length = b->size - 1;
	while (b->size != 0)
	{
		sort_b(b, length);
		push(b, a, 'a');
		length--;
	}
}

static void	a_to_b(t_deque *a, t_deque *b, int chunk, int count)
{
	int	length;

	length = a->size - 1;
	while (a->size != 0)
	{
		if (a->front->num <= count)
		{
			push(a, b, 'b');
			count++;
		}
		else if (a->front->num > count && a->front->num <= count + chunk)
		{
			push(a, b, 'b');
			rotate(b, 'b');
			count++;
		}
		else if (a->front->num > (count + chunk))
		{
			if (count < a->size / 2 && count >= 0)
				reverse_rotate(a, 'a');
			else
				rotate(a, 'a');
		}
		length--;
	}
}

void	sandglass_start(t_deque *a, t_deque *b)
{
	int	chunk;
	int	standard;
	int	count;

	chunk = 10;
	standard = 100;
	while (a->size > standard)
	{
		standard *= 3;
		chunk *= 2;
	}
	count = 0;
	a_to_b(a, b, chunk, count);
	b_to_a(a, b);
}
