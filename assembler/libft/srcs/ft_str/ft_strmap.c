/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:44:08 by blanna            #+#    #+#             */
/*   Updated: 2018/12/15 18:55:50 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	int		i;

	i = 0;
	if (!s || !f)
		return (0);
	dest = ft_strnew(ft_strlen(s));
	while (s[i] && f)
	{
		if (!dest)
			return (0);
		{
			dest[i] = (*f)(s[i]);
			i++;
		}
	}
	return (dest);
}
