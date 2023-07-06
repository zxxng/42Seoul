/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 22:35:41 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/07 00:20:20 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_size_two(t_deque *a)
{
	if (a->front->num > a->rear->num)
		swap(a, 'a');
}

static void	sort_size_three(t_deque *a)
{
	int	v1;
	int	v2;
	int	v3;

	v1 = a->front->num;
	v2 = a->front->next->num;
	v3 = a->rear->num;
	if ((v1 > v2) && (v2 > v3) && (v1 > v3))
	{
		swap(a, 'a');
		reverse_rotate(a, 'a');
	}
	else if (v1 > v2 && v2 < v3 && v1 < v3)
		swap(a, 'a');
	else if (v1 > v2 && v2 < v3 && v1 > v3)
		rotate(a, 'a');
	else if (v1 < v2 && v2 > v3 && v1 < v3)
	{
		swap(a, 'a');
		rotate(a, 'a');
	}
	else if (v1 < v2 && v2 > v3 && v1 > v3)
		reverse_rotate(a, 'a');
}

static void	sort_size_four(t_deque *a, t_deque *b)
{
	while (a->size > 3)
	{
		if (a->front->num == 0)
			break ;
		else
			rotate(a, 'a');
	}
	push(a, b, 'b');
	sort_size_three(a);
	push(b, a, 'a');
}

static void	sort_size_five(t_deque *a, t_deque *b)
{
	while (a->size > 3)
	{
		if (a->front->num < 2)
			push(a, b, 'b');
		else
			rotate(a, 'a');
	}
	sort_size_three(a);
	push(b, a, 'a');
	push(b, a, 'a');
	if (a->front->num != 0)
		swap(a, 'a');
}

void	sort_hard(t_deque *a, t_deque *b)
{
	if (a->size == 5)
		sort_size_five(a, b);
	else if (a->size == 4)
		sort_size_four(a, b);
	else if (a->size == 3)
		sort_size_three(a);
	else
		sort_size_two(a);
}
