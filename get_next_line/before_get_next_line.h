/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_get_next_line.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:04:40 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/05/02 19:40:14 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BEFORE_GET_NEXT_LINE_H
# define BEFORE_GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

int		check_n(char *arr, int size);
int		fd_read(int fd, char **srg);
char	*get_new_line(char **srg, int flag);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *src);

#endif
