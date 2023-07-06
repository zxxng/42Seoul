/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:21:23 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/06 12:05:00 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_front(t_deque *deque, t_node *new)
{
	if (!deque || !new)
		return ;
	if (deque->size == 0)
	{
		deque->front = new;
		deque->rear = new;
	}
	else
	{
		deque->front->prev = new;
		new->next = deque->front;
		deque->front = new;
	}
	deque->size++;
}

void	push_rear(t_deque *deque, t_node *new)
{
	if (!deque || !new)
		return ;
	if (deque -> size == 0)
	{
		deque->front = new;
		deque->rear = new;
	}
	else
	{
		deque->rear->next = new;
		new -> next = NULL;
		new -> prev = deque->rear;
		deque->rear = new;
	}
	deque->size++;
}

t_node	*pop_front(t_deque *deque)
{
	t_node	*tmp;

	if (!deque || deque->size == 0)
		return (0);
	tmp = deque->front;
	deque->front = deque->front->next;
	tmp ->next = 0;
	tmp -> prev = 0;
	if (deque->size == 1)
		deque->rear = 0;
	else
		deque->front->prev = 0;
	deque->size--;
	return (tmp);
}

t_node	*pop_rear(t_deque *deque)
{
	t_node	*tmp;

	if (!deque || deque -> size == 0)
		return (0);
	tmp = deque->rear;
	deque->rear = deque->rear->prev;
	tmp->prev = 0;
	tmp->next = 0;
	if (deque->size == 1)
	{
		deque->front = 0;
		deque->rear = 0;
	}
	else
		deque->rear->next = 0;
	deque->size--;
	return (tmp);
}
