/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:51:26 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/03 19:24:16 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_messege(void)
{
	write(1, "Error\n", 6);
	return (-1);
}

char	*parse_input(int ac, char **av)
{
	int		i;
	char	*join;
	char	*temp;
	char	**split;

	join = ft_strdup("");
	if (join == NULL)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		temp = ft_strjoin_with_space(join, av[i]);
		if (temp == NULL)
		{
			free(join);
			return (NULL);
		}
		free(join);
		join = temp;
		i++;
	}
	split = ft_split(join, ' ');
	free(join);
	return (split);
}

int input_length(char **input)
{
	int i;

	i = 0;
	while(input[i] != 0)
		i++;
	return (i);
}

int check_duplicate(char **input)
{
	int i;
	int j;

	i = 0;
	while(input[i])
	{
		j = i + 1;
		while (input[j])
		{
			if (input[i] == input[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int char_to_int(char **input)
{
	int i;
	int len;
	int	overflow;
	int	**raw;

	len = input_length(input);
	raw = malloc(sizeof(int *) * len);
	if (!raw)
		return (-1);
	i = 0;
	overflow = 1;
	while(i < len)
	{
		raw[i] = ft_atoi(input[i], *overflow);
		if (overflow == 0)
			return (-1);
		i++;
	}
	return (raw);
}


int	main(int ac, char **av)
{
	t_data *data;
	char **input;
	
	if (ac < 2)
		return (0);
	input = parse_input(ac, av);
	if (!input)
		return (error_messege());
	char_to_int(input);
	
}
