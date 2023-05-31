/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:23:05 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/05/31 22:53:16 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>
#include <stdlib.h>
#include <sys/signal.h>

t_content	g_content;

void	sigusr_handler(int signum, siginfo_t *info, void *context)
{
	(void) context;
	g_content.data <<= 1;
	if (signum == SIGUSR1)
		g_content.data |= 1;
	g_content.count++;
	if (g_content.count == 8)
	{
		write(1, &g_content.data, 1);
		g_content.count = 0;
		g_content.data = 0;
	}
	usleep(100);
	kill(info->si_pid, signum);
}

void	sig_init(struct sigaction *sigusr_action)
{
	sigemptyset(&(sigusr_action->sa_mask));
	sigusr_action->sa_flags = SA_SIGINFO;
	sigusr_action->sa_sigaction = sigusr_handler;
	sigaction(SIGUSR1, sigusr_action, 0);
	sigaction(SIGUSR2, sigusr_action, 0);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sigusr_action;

	(void) argv;
	if (argc != 1)
	{
		ft_printf("Error : 프로그램을 종료합니다.\n");
		exit(1);
	}
	pid = getpid();
	ft_printf("PID : %d\n", pid);
	sig_init(&sigusr_action);
	g_content.data = 0;
	g_content.count = 0;
	while (1)
		pause();
	return (0);
}
