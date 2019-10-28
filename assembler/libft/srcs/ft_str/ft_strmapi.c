/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:44:20 by blanna            #+#    #+#             */
/*   Updated: 2018/12/15 18:56:59 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s || !f)
		return (0);
	dest = ft_strnew(ft_strlen(s));
	while (s[i] && f)
	{
		if (!dest)
			return (0);
		{
			dest[i] = (*f)(j, s[i]);
			i++;
			j++;
		}
	}
	return (dest);
}
