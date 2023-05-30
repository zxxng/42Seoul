/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:22:55 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/05/29 21:53:43 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <stdlib.h>

void	send_bit(unsigned int str, int pid, int repeat)
{
	if (repeat == 0)
		return ;
	send_bit(str / 2, pid, repeat - 1);
	if (str % 2 == 1)
		kill(pid, SIGUSR1);
	else if (str % 2 == 0)
		kill(pid, SIGUSR2);
	usleep(100);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*send_str;

	if (argc != 3)
	{
		ft_printf("Error : 프로그램을 종료합니다.\n");
		exit(1);
		return (-1);
	}
	pid = ft_atoi(argv[1]);
	send_str = argv[2];
	while (*send_str)
	{
		send_bit(*send_str, pid, 8);
		send_str++;
	}
	return (0);
}
