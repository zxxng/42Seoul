/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:28:01 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/06 14:31:10 by jaeyyoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	*bubble_sort(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				sort_swap(&arr[j], &arr[j + 1]);
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	*sort_array(int *arr, int n)
{
	int	*new_array;
	int	i;

	new_array = malloc(sizeof(int) * n);
	if (!new_array)
		return (NULL);
	i = 0;
	while (i < n)
	{
		new_array[i] = arr[i];
		i++;
	}
	bubble_sort(new_array, n);
	return (new_array);
}
