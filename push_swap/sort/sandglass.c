/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandglass.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:56:50 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/05 20:53:45 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_b(t_deque *b, int length)
{
	while (b->front->num != length)
	{
		if (b->front->num < b->rear->num)
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
	while (length != 0)
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
			if (count < length / 2 && count >= 0)
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
	int	count;

	chunk = 30;
	count = 0;
	a_to_b(a, b, chunk, count);
	b_to_a(a, b);
}
