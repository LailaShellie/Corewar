/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:45:24 by blanna            #+#    #+#             */
/*   Updated: 2018/12/14 17:35:36 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char			*str1;
	char			*str2;
	size_t			i;

	if (!*s2)
		return ((char *)s1);
	while (*s1 && n != 0)
	{
		if (*s1 == *s2)
		{
			i = n;
			str1 = (char *)s1 + 1;
			str2 = (char *)s2 + 1;
			while (i-- != 0 && *str1 && *str2 && *str1 == *str2)
			{
				++str1;
				++str2;
			}
			if (!*str2)
				return ((char *)s1);
		}
		n--;
		++s1;
	}
	return (NULL);
}
