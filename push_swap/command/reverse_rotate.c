/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:11:48 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/05 22:12:32 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_deque *deque, char c)
{
	t_node	*last;

	if (deque->size < 2)
		return ;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
	last = pop_rear(deque);
	push_front(deque, last);
}

void	reverse_rotate_twice(t_deque *a, t_deque *b)
{
	if (a->size < 2)
		return (reverse_rotate(b, 'b'));
	else if (b->size < 2)
		return (reverse_rotate(a, 'a'));
	write(1, "rrr\n", 4);
	reverse_rotate(a, ' ');
	reverse_rotate(b, ' ');
}
