/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:28:01 by jaeyyoo           #+#    #+#             */
/*   Updated: 2023/07/05 19:05:50 by jaeyyoo          ###   ########.fr       */
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

static int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			sort_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	sort_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

static void	quick_sort(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
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
	quick_sort(new_array, 0, n - 1);
	return (new_array);
}
