/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:34:20 by blanna            #+#    #+#             */
/*   Updated: 2018/12/15 18:51:07 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int		ft_atoi(const char *s)
{
	long long int	value;
	long long int	sign;

	value = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\r' \
			|| *s == '\f' || *s == '\v' || *s == '\n')
		++s;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		value = value * 10;
		value = value + (*s - '0');
		if (value < 0)
			return (sign == 1 ? -1 : 0);
		s++;
	}
	return (value * sign);
}
