/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_csp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 01:48:03 by acrooks           #+#    #+#             */
/*   Updated: 2019/06/13 01:50:23 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_type_c(va_list ap, char *modi)
{
	char	*res;
	char	c;

	if (ft_strcmp(modi, "") == 0)
		c = (unsigned char)va_arg(ap, int);
	if (!(res = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	res[0] = c;
	res[1] = '\0';
	return (res);
}

char	*ft_type_s(va_list ap)
{
	char *s;

	s = (va_arg(ap, char*));
	s = (s == NULL ? ft_strdup("(null)") : ft_strdup(s));
	return (s);
}

char	*ft_type_p(va_list ap)
{
	void *p;
	char *str;

	p = va_arg(ap, void*);
	str = ft_itoa_base((unsigned long)p, 16);
	return (str);
}
