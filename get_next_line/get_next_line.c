/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 08:18:41 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/05/15 23:12:05 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_n(char *buf)
{
	int	i;

	if (!buf)
		return (0);
	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*read_result(char **buf, char **srg, int read_size)
{
	if (read_size == 0)
	{
		free(*buf);
		return (*srg);
	}
	if (*srg != NULL)
		free(*srg);
	free(*buf);
	return (NULL);
}

char	*read_line(int fd, char **srg)
{
	char	*buf;
	int		read_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free(*srg);
		return (NULL);
	}
	buf[0] = '\0';
	while (!check_n(buf))
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == 0 || read_size == -1)
			return (read_result(&buf, srg, read_size));
		buf[read_size] = '\0';
		*srg = ft_strjoin(*srg, buf);
		if (!(*srg))
			break ;
	}
	free(buf);
	return (*srg);
}

char	*get_new_line(char **srg)
{
	char	*res;
	int		len;
	int		idx;
	int		srg_len;

	srg_len = ft_strlen(*srg);
	idx = 0;
	len = check_n(*srg);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (idx < len)
	{
		res[idx] = *(*srg + idx);
		idx++;
	}
	res[idx] = '\0';
	ft_memmove(*srg, *srg + len, srg_len - len);
	(*srg)[srg_len - len] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*srg;
	char		*res;

	srg = read_line(fd, &srg);
	if (!srg)
		return (NULL);
	if (!check_n(srg))
	{
		if ((*srg))
			res = ft_strdup(srg);
		else
			res = NULL;
		free(srg);
		srg = NULL;
	}
	else
	{
		res = get_new_line(&srg);
		if (!res)
		{
			free(srg);
			srg = NULL;
		}
	}
	return (res);
}
