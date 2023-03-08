/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:04:23 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/02/26 18:30:14 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_n(char *arr, int size)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (i < size)
	{
		if (arr[i] == '\n')
			return (i);
		i++;
	}
	return (-2);
}

int	fd_read(int fd, char **srg)
{
	char	buf[BUFFER_SIZE + 1];
	int		read_size;
	int		check_srg;
	int		check_buf;
	char	*tmp;

	ft_memset(buf, 0, BUFFER_SIZE);
	check_srg = -2;
	while (check_srg == -2)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == 0)
			return (0);
		if (read_size == -1)
			return (-1);
		check_buf = check_n(buf, read_size);
		if (check_buf == -2)
			check_buf = read_size;
		tmp = *srg;
		*srg = ft_strjoin(*srg, buf, check_buf + 1);
		free(tmp);
		check_srg = check_n(*srg, ft_strlen(*srg));
	}
	return (1);
}

char	*get_new_line(char **srg, int flag)
{
	char	*line;
	char	*tmp;

	if (flag == 0)
		return (NULL);
	line = malloc(sizeof(char) * (flag + 1));
	tmp = *srg;
	if (flag != -2)
	{
		line = ft_memcpy(line, *srg, flag);
		*srg = ft_memcpy(*srg, (&srg[flag + 1]), ft_strlen(*srg) - flag);
	}
	else
	{
		line = ft_memcpy(line, *srg, ft_strlen(*srg));
		*srg = NULL;
	}
	free(tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*srg;
	int			read_flag;
	int			newline_flag;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	read_flag = fd_read(fd, &srg);
	if (srg == NULL || read_flag == -1)
		return (NULL);
	newline_flag = check_n(srg, ft_strlen(srg));
	return (get_new_line(&srg, newline_flag));
}

#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int		fd;
	char	*text;

	fd = open("test", O_RDONLY);
	for (int i = 0; i < 3; i++)
	{
		text = get_next_line(fd);
		printf("%s\n", text);
	}
	close(fd);
}
