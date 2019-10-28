/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:43:45 by blanna            #+#    #+#             */
/*   Updated: 2018/12/12 19:42:14 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t		i;
	size_t		dlen;
	size_t		slen;

	i = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (n <= dlen)
		return (slen + n);
	while ((dst[i] != '\0') && i < (n - 1))
		i++;
	while (*src && i < (n - 1))
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = '\0';
	return (dlen + slen);
}
