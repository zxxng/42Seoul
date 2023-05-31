/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:22:55 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/05/31 15:56:20 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <stdlib.h>

void	error(void)
{
	ft_printf("Error : 프로그램을 종료합니다.\n");
	exit(1);
}

void	send_bit(unsigned int str, int pid, int repeat)
{
	if (repeat == 0)
		return ;
	send_bit(str / 2, pid, repeat - 1);
	usleep(100);
	if (str % 2 == 1)
	{
		if (kill(pid, SIGUSR1))
			error();
	}
	else if (str % 2 == 0)
	{
		if (kill(pid, SIGUSR2))
			error();
	}
	pause();
}

void	client_handler(int signum)
{
	static int	count;

	ft_printf("Success : %d, signal : %d\n", count++, signum);
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*send_str;

	if (argc != 3)
		error();
	pid = ft_atoi(argv[1]);
	send_str = argv[2];
	signal(SIGUSR1, client_handler);
	signal(SIGUSR2, client_handler);
	while (*send_str)
	{
		send_bit(*send_str, pid, 8);
		send_str++;
	}
	return (0);
}
