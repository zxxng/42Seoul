/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 17:27:23 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/03 19:48:50 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				inp_arr;
	int				sort_arr;
	int				idx_arr;
	int				size;
}	t_node;

typedef struct s_deque
{
	struct s_node	*prev;
	struct s_node	*next;
}	t_deque;
#endif

inp_arr
