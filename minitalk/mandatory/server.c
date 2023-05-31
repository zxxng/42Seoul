/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:23:05 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/05/31 15:56:19 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <stdlib.h>

t_content	g_content;

void	sigusr_handler(int signal)
{
	g_content.data <<= 1;
	if (signal == SIGUSR1)
		g_content.data |= 1;
	g_content.count++;
	if (g_content.count == 8)
	{
		write(1, &g_content.data, 1);
		g_content.count = 0;
		g_content.data = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error : 프로그램을 종료합니다.\n");
		exit(1);
	}
	pid = getpid();
	ft_printf("PID : %d\n", pid);
	signal(SIGUSR1, sigusr_handler);
	signal(SIGUSR2, sigusr_handler);
	g_content.data = 0;
	g_content.count = 0;
	while (1)
		pause();
	return (0);
}
