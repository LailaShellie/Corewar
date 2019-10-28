/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:38:24 by blanna            #+#    #+#             */
/*   Updated: 2018/12/15 19:10:09 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*s1;
	char	*s2;
	size_t	i;

	s1 = (char *)dst;
	s2 = (char *)src;
	if (dst == src)
		return (dst);
	if (dst < src)
	{
		i = -1;
		while (++i < n)
			s1[i] = s2[i];
	}
	else
		while (n > 0)
		{
			n--;
			s1[n] = s2[n];
		}
	return (dst);
}
