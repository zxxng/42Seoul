/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 08:18:41 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/05/12 17:41:39 by jaeyyoo          ###   ########.fr       */
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

char *read_result(char **buf, char **srg, int read_size)
{
	if (read_size == 0)
	{
		free(*buf);
		return (*srg);
	}
	if (read_size == -1)
	{
		if (*srg != NULL)
			free(*srg);
		free(*buf);
		*srg = NULL;
		return (NULL);
	}
	(*buf)[read_size] = '\0';
	*srg = ft_strjoin(*srg, *buf);
	return (*srg);
}

char	*read_line(int fd, char *srg)
{
	char	*buf;
	int		read_size;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	while (!check_n(buf))
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		return (read_result(&buf, &srg, read_size));
	}
	free(buf);
	return (srg);
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
	res = (char *)malloc(sizeof(char) * (len + 1));
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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	srg = read_line(fd, srg);
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
			free(srg);
	}
	return (res);
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd = open("./test.txt",O_RDONLY);
	char	*line;
	int		i = 1;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			printf("null\n");
			return (0);
		}
		printf("%d번째\n%s\n",i, line);
		i++;
	}
	return (0);
}