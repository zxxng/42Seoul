/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:11:53 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/05 17:33:10 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_deque *deque, char c)
{
	t_node	first;

	if (deque->size < 2)
		return ;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
	first = pop_front(deque);
	push_rear(deque, first);
}

void	rotate_twice(t_deque *a, t_deque *b)
{
	if (a->size < 2)
		return (rotate(b, 'b'));
	else if (b->size < 2)
		return (rotate(a, 'a'));
	write(1, "rr\n", 3);
	rotate(a, ' ');
	rotate(b, ' ');
}
