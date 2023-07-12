/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:56:32 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/12 15:58:41 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	set_signal(void)
{
	set_terminal_print_off();
	signal(SIGINT, do_sigint);
	signal(SIGQUIT, SIG_IGN);
}

void	set_signal_fork(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	set_signal_origin(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	set_signal_heredoc(void)
{
	signal(SIGINT, do_sigint_heredoc);
	signal(SIGQUIT, SIG_IGN);
}

void	do_sigint_heredoc(int signum)
{
	(void)signum;
	ft_putstr_fd("\n", STD_ERROR);
	exit (1);
}

void	set_terminal_print_off(void)
{
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(1, 0, &term);
}

void	set_terminal_print_on(void)
{
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag |= (ECHOCTL);
	tcsetattr(1, 0, &term);
}

void	do_sigint(int signum)
{
	(void)signum;
	ft_putstr_fd("\n", STD_ERROR);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	change_exit_status(1);
}

void	do_sigterm(void)
{
	ft_putstr_fd("\033[1A", STD_ERROR);
	ft_putstr_fd("\033[12C", STD_ERROR);
	ft_putstr_fd("exit\n", STD_ERROR);
}

void	check_fork_signal(int statloc)
{
	if ((statloc & 255) != 0)
	{
		if ((statloc & 127) == 2)

			ft_putstr_fd("\n", STD_ERROR);
		else if ((statloc & 127) == 3)
			ft_putstr_fd("Quit: 3\n", STD_ERROR);
	}
}
