/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:37:25 by blanna            #+#    #+#             */
/*   Updated: 2018/12/12 17:02:20 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	char	*str;
	char	let;
	size_t	i;

	str = (char *)buf;
	let = (char)ch;
	i = -1;
	while (++i < n)
	{
		if (str[i] == let)
			return ((void *)&str[i]);
	}
	return (NULL);
}
