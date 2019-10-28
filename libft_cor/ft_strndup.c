/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:02:25 by lshellie          #+#    #+#             */
/*   Updated: 2019/10/13 18:02:26 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int n)
{
	char	*str;
	int		j;

	j = 0;
	if (!(str = (char *)malloc(sizeof(char) * (n + 1))))
		return (0);
	str[n] = 0;
	while (j < n)
	{
		str[j] = s1[j];
		++j;
	}
	return (str);
}
