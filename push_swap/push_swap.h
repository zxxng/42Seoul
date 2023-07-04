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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_deque
{
	t_node			front;
	t_node			rear;
	unsigned int	size;
}	t_deque;

char	*join_input(int ac, char **av);
char	**parse_input(char *join);
int		input_length(char **input);
int		check_duplicate(char **input, int len);
int		*char_to_int(char **input, int len);

#endif
