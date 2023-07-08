/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:10:47 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/07 00:27:00 by jaeyyoo          ###   ########.fr       */
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
			join[i] != '-' && join[i] != '+' && join[i] != ' ')
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

int	check_sorted(int *arr, int len)
{
	int	i;

	if (len == 1)
		return (0);
	i = 0;
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
			return (1);
		i++;
	}
	return (0);
}

static int	check_duplicate(int *raw, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (raw[i] == raw[j])
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
	int	error;
	int	*raw;

	raw = malloc(sizeof(int) * len);
	if (!raw)
		return (0);
	i = 0;
	error = 1;
	while (i < len)
	{
		raw[i] = ft_atoi(input[i], &error);
		if (error == 0)
		{
			free(raw);
			return (NULL);
		}
		i++;
	}
	if (!check_duplicate(raw, len))
	{
		free(raw);
		return (NULL);
	}
	return (raw);
}
