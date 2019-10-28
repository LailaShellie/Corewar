/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort_devided.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <blanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:45:10 by blanna            #+#    #+#             */
/*   Updated: 2019/05/28 16:46:36 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_partition_left(int *arr, int start, int end)
{
	int	pivot;
	int	temp;
	int	i;
	int	j;

	pivot = arr[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (arr[j] < pivot)
		{
			i++;
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
		j++;
	}
	temp = arr[j];
	arr[j] = arr[i + 1];
	arr[i + 1] = temp;
	return (i + 1);
}

void	ft_quicksort_left(int *arr, int start, int end)
{
	int	med;

	if (end > start)
	{
		med = ft_partition_left(arr, start, end);
		ft_quicksort_left(arr, start, med - 1);
		ft_quicksort_left(arr, med + 1, end);
	}
}

int		ft_partition_right(int *arr, int start, int end)
{
	int	pivot;
	int	temp;
	int	i;
	int	j;

	pivot = arr[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (arr[j] > pivot)
		{
			i++;
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
		j++;
	}
	temp = arr[j];
	arr[j] = arr[i + 1];
	arr[i + 1] = temp;
	return (i + 1);
}

void	ft_quicksort_right(int *arr, int start, int end)
{
	int	med;

	if (end > start)
	{
		med = ft_partition_right(arr, start, end);
		ft_quicksort_right(arr, start, med - 1);
		ft_quicksort_right(arr, med + 1, end);
	}
}

/*
** int main(void)
** {
** 	int	a[] = {4, 1, 3, 2};
** 	int	i;
** 	int len = 4;
** 	//a = malloc(4 * 20);
** 	//if (a == NULL)
** 	//	return (0);
** 	//i = -1;
** 	//while (++i < 20)
** 	//	a[i] = 20 - i;
** 	//i = -1;
** 	//while (++i < 20)
** 	//	ft_printf("%d ", a[i]);
** 	ft_printf("\n");
** 	ft_quicksort_hoar(a, 0, len - 1);
** 	i = -1;
** 	while (++i < len)
** 		ft_printf("%d ", a[i]);
** 	ft_printf("\n");
** 	return (0);
** }
*/
