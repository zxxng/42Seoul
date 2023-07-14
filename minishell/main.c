/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:54:24 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/14 15:14:59 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include <signal.h>
#include <unistd.h>
#include <readline/readline.h> 
#include <readline/history.h>
#include "./libft/libft.h"
#include <termios.h>

static void	set_terminal_print_off(void)
{
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(1, 0, &term);
}

static void	set_terminal_print_on(void)
{
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag |= (ECHOCTL);
	tcsetattr(1, 0, &term);
}

static void	sigint_handler(int signum)
{
	(void)signum;
	ft_putendl_fd("jsh> ", STDERR_FILENO);
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

static void	sigterm_handler(int signum)
{
	printf("sigterm handler\n");
	ft_putendl_fd("", STDERR_FILENO);
	set_terminal_print_on();
	exit(1);
}

void	set_signal(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGTERM, sigterm_handler);
	signal(SIGQUIT, SIG_IGN);
}

int	main(int argc, char **argv)
{
	char	*input;

	set_signal();
	set_terminal_print_off();
	while (1)
	{
		input = readline("jsh> ");
		if (input == NULL)
		{
			ft_putendl_fd("", STDERR_FILENO);
			kill(getpid(), SIGTERM);
		}
		printf("%s\n", input);
		free(input);
	}
	return (0);
}
