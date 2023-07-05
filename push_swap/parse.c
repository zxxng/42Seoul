/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:10:47 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/05 21:30:39 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (join);
}

char	**parse_input(char *join)
{
	int		i;
	int		flag;
	char	**split;

	i = 0;
	flag = 1;
	if (join == NULL)
		return (NULL);
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

int	check_duplicate(int *raw, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len - 1)
		{
			if (raw[i] == raw[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

#include <stdio.h>
int	*char_to_int(char **input, int len)
{
	int	i;
	int	overflow;
	int	*raw;

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
	if (!check_duplicate(raw, len))
		return (0);
	for (int k=0; k<len; k++){
		printf("raw[%d] : %d\n", k , raw[k]);
	}
	return (raw);
}
