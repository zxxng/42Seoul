/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_get_next_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:04:23 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/05/02 19:40:12 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "before_get_next_line.h"

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
		buf[read_size] = '\0';
		tmp = *srg;
		*srg = ft_strjoin(*srg, buf);
		free(tmp);
		check_srg = check_n(*srg, ft_strlen(*srg));
	}
	return (1);
}

char	*get_new_line(char **srg, int flag)
{
	char	*line;
	int		new_len;

	if (flag == 0)
		return (NULL);
	if (flag == -2)
		new_len = ft_strlen(*srg);
	else
		new_len = check_n(*srg, ft_strlen(*srg));
	line = malloc(sizeof(char) * (new_len + 1));
	if (flag != -2)
	{
		line = ft_memcpy(line, *srg, new_len);
		line[new_len] = '\0';
		*srg = ft_memcpy(*srg, *srg + (new_len + 1), ft_strlen(*srg) - new_len);
	}
	else
	{
		line = ft_memcpy(line, *srg, new_len);
		*srg = NULL;
	}
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

// #include <fcntl.h>
// #include <stdio.h>
// int	main(void)
// {
// 	int		fd;
// 	char	*text;

// 	fd = open("test", O_RDONLY);
// 	while (1)
// 	{
// 		text = get_next_line(fd);
// 		if (text == NULL)
// 			break;
// 		printf("%s\n", text);
// 		free(text);
// 	}
// 	close(fd);
// }
