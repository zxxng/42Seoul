/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:27:23 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/07 00:16:02 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				num;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_deque
{
	t_node	*front;
	t_node	*rear;
	int		size;
}	t_deque;

char	*join_input(int ac, char **av);
char	**parse_input(char *join);
int		check_duplicate(int *raw, int len);
int		*char_to_int(char **input, int len);
int		check_sorted(int *arr, int len);

// command
void	push_front(t_deque *deque, t_node *new);
void	push_rear(t_deque *deque, t_node *new);
t_node	*pop_front(t_deque *deque);
t_node	*pop_rear(t_deque *deque);
void	swap(t_deque *deque, char c);
void	swap_twice(t_deque *a, t_deque *b);
void	push(t_deque *from, t_deque *to, char c);
void	rotate(t_deque *deque, char c);
void	rotate_twice(t_deque *a, t_deque *b);
void	reverse_rotate(t_deque *deque, char c);
void	reverse_rotate_twice(t_deque *a, t_deque *b);

// converter
int		input_length(char **input);
void	add_node(int data, t_deque *stack_a);
void	input_to_node(int *conversion_input, t_deque *a, t_deque *b, int len);
int		*conversion(char **original_input);

// sort
int		*sort_array(int *arr, int n);
void	sandglass_start(t_deque *a, t_deque *b);
void	sort_hard(t_deque *a, t_deque *b);

#endif