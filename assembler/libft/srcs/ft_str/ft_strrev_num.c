/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <blanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 15:27:26 by blanna            #+#    #+#             */
/*   Updated: 2019/05/08 15:42:02 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	*ft_strrev_num(unsigned char *s, int len)
{
	int		i;
	char	first;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = len - 1;
	while (i < len - i)
	{
		first = s[i];
		s[i] = s[len - i];
		s[len - i] = first;
		i++;
	}
	return (s);
}
