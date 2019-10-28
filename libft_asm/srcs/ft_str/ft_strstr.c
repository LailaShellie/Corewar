/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:46:13 by blanna            #+#    #+#             */
/*   Updated: 2018/12/17 17:17:32 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *find)
{
	int		i;
	int		fi;
	char	*s1;
	char	*s2;

	s1 = (char*)str;
	s2 = (char*)find;
	i = 0;
	while (s1[i] != '\0')
	{
		fi = 0;
		while (s1[i + fi] == s2[fi])
		{
			fi++;
			if (s2[fi] == '\0')
				return (&s1[i]);
		}
		i++;
	}
	if (s2[0] == '\0')
		return (s1);
	return (NULL);
}
