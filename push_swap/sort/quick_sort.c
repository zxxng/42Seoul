/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:27:23 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/04 20:18:37 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node *last_node(t_node *node) {
    while (node && node->next) {
        node = node->next;
    }
    return node;
}

void update_partition_ptrs(t_node **new_head, t_node **new_high, t_node *pivot, t_node *prev) {
    if (!(*new_head)) *new_head = pivot;
    *new_high = prev;
}

t_node *partition(t_node *head, t_node *high, t_node **new_head, t_node **new_high) {
    t_node *pivot = high, *prev = NULL, *cur = head, *tail = pivot;

    while (cur != pivot) {
        if (cur->num < pivot->num) {
            if (!(*new_head)) *new_head = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev) prev->next = cur->next;
            t_node *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
    update_partition_ptrs(new_head, new_high, pivot, tail);
    return pivot;
}

t_node *_quick_sort_nodes(t_node *head, t_node *high) {
    if (!head || head == high) return head;

    t_node *new_head = NULL, *new_high = NULL;
    t_node *pivot = partition(head, high, &new_head, &new_high);

    if (new_head != pivot) {
        t_node *tmp = new_head;
        while (tmp->next != pivot) tmp = tmp->next;
        tmp->next = NULL;

        new_head = _quick_sort_nodes(new_head, tmp);
        last_node(new_head)->next = pivot;
    }
    pivot->next = _quick_sort_nodes(pivot->next, new_high);
    return new_head;
}

void deque_quick_sort(t_deque *deque) {
    t_node *high = last_node(deque->front);
    deque->front = _quick_sort_nodes(deque->front, high);
}
