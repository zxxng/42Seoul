/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 08:19:06 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/28 16:52:21 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

size_t	ft_strlen(char *str);
char	*ft_strdup(char *s1);
void	*ft_memmove(void *dst, void *src, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, void *src, size_t len);
char	**ft_split(char const *s, char c);
int		ft_memcmp(const void *s1, const void *s2, size_t num);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);

// ft_printf
int		ft_putnbr_len(long long n, unsigned int base);
int		ft_putnbr(int n);
int		ft_putnbr_un(unsigned int n, unsigned int len, char *base);
int		ft_putnbr_p(uintptr_t n);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_printf(const char *str, ...);

#endif
