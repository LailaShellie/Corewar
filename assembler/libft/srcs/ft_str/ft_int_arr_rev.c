/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_arr_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <blanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:36:44 by blanna            #+#    #+#             */
/*   Updated: 2019/05/28 18:36:45 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_int_arr_rev(int *arr, int len)
{
	int	i;
	int j;
	int temp;

	i = 0;
	j = len;
	while ((len % 2 == 1 && len > 1) || (len % 2 == 0 && len > 0))
	{
		temp = arr[i];
		arr[i] = arr[j - 1];
		arr[j - 1] = temp;
		i++;
		j--;
		len -= 2;
	}
	return (1);
}
