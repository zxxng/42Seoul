/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:11:38 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/05 21:59:46 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_deque *deque, char c)
{
	t_node	*first;
	t_node	*second;

	if (deque->size < 2)
		return ;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
	first = pop_front(deque);
	second = pop_front(deque);
	push_front(deque, first);
	push_front(deque, second);
}

void	swap_twice(t_deque *a, t_deque *b)
{
	if (a->size < 2)
		return (swap(b, 'b'));
	else if (b->size < 2)
		return (swap(a, 'a'));
	write(1, "ss\n", 3);
	swap(a, ' ');
	swap(b, ' ');
}
