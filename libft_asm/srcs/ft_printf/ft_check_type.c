/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 01:44:00 by acrooks           #+#    #+#             */
/*   Updated: 2019/06/13 01:44:46 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_type(const char *form, char **typestr)
{
	int		i;
	int		tag;
	char	*typelist;
	char	*buf;

	i = 0;
	tag = 0;
	typelist = ft_strdup(TYPELIST);
	buf = typelist;
	while (form[i])
	{
		if (check_typelist(form[i], typelist))
		{
			i++;
			*typestr = ft_strndup(form, i);
			tag = 1;
			break ;
		}
		typelist = buf;
		i++;
	}
	free(typelist);
	return (ft_if_notmod(tag, typestr, form) ? i : 0);
}

int		check_typelist(char c, char *s)
{
	while (*s)
	{
		if (c == *s)
			return (1);
		s++;
	}
	return (0);
}

int		ft_if_notmod(int tag, char **typestr, const char *form)
{
	if (tag)
		return (1);
	*typestr = ft_strdup((char *)form);
	return (0);
}
