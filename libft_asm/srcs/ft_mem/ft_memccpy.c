/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:37:12 by blanna            #+#    #+#             */
/*   Updated: 2018/12/15 17:48:04 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*s1;
	char	*s2;
	size_t	i;
	char	let;

	s1 = (char *)dest;
	s2 = (char *)src;
	let = (char)c;
	i = -1;
	while (++i < n)
	{
		s1[i] = s2[i];
		if (let == s2[i])
			return (dest + i + 1);
	}
	return (NULL);
}
