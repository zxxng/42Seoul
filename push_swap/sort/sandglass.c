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

void	b_to_a(t_deque *a, t_deque *b)
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

void	a_to_b(t_deque *a, t_deque *b, int chunk, int i)
{
	int	length;

	length = a->size - 1;
	while (a->size != 0)
	{
		if (a->front->num <= i)
		{
			push(a, b, 'b');
			i++;
		}
		else if (a->front->num > i && a->front->num <= i + chunk)
		{
			push(a, b, 'b');
			rotate(b, 'b');
			i++;
		}
		else if (a->front->num > (i + chunk))
		{
			if (i < a->size / 2 && i >= 0)
				reverse_rotate(a, 'a');
			else
				rotate(a, 'a');
		}
		length--;
	}
}
