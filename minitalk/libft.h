/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:42:52 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/05/29 21:47:06 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_atoi(char *str);

typedef struct s_content
{
	int	data;
	int	count;
}	t_content;

#endif
