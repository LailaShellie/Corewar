/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:45:48 by blanna            #+#    #+#             */
/*   Updated: 2018/12/11 16:45:52 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char *src;

	src = str;
	while (*src)
		src++;
	if (c == 0)
		return ((char*)src);
	while (src > str)
	{
		src--;
		if (((char)*src) == c)
			return ((char*)src);
	}
	return (0);
}
