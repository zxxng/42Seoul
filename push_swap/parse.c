/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:10:47 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/04 16:06:56 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

char	*join_input(int ac, char **av)
{
	int		i;
	char	*join;
	char	*temp;

	join = ft_strdup("");
	if (!join)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		temp = ft_strjoin(join, av[i]);
		if (temp == NULL)
		{
			free(join);
			return (NULL);
		}
		free(join);
		join = temp;
		i++;
	}
	printf("join : %s\n", join);
	return (join);
}

char	**parse_input(char *join)
{
	int		i;
	int		flag;
	char	**split;

	i = 0;
	flag = 1;
	while (join[i])
	{
		if (!(join[i] >= '0' && join[i] <= '9') && \
			join[i] != '-' && join[i] != ' ')
		{
			flag = 0;
		}
		if (flag == 0)
		{
			free(join);
			return (NULL);
		}
		i++;
	}
	split = ft_split(join, ' ');
	free(join);
	return (split);
}

int	check_duplicate(char **input, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (input[j])
		{
			if (input[i] == input[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	*char_to_int(char **input, int len)
{
	int	i;
	int	overflow;
	int	*raw;

	if (!check_duplicate(input, len))
		return (0);
	raw = malloc(sizeof(int) * len);
	if (!raw)
		return (0);
	i = 0;
	overflow = 1;
	while (i < len)
	{
		raw[i] = ft_atoi(input[i], &overflow);
		if (overflow == 0)
		{
			free(raw);
			return (NULL);
		}
		i++;
	}
	return (raw);
}