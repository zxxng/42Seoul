/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:54:24 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/12 15:58:42 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

int	main(int argc, char **argv, char **env)
{
	char	*input;

	while (1)
	{
		input = readline("jsh> ");
		printf("%s\n", input);
		free(input);
	}
	return (0);
}

void	do_sigint(void)
{

}

void	do_sigterm(void)
{
	signal()
}

void	do_sigquit(void)
{
	signal(SIGQUIT, SIG_IGN);
}