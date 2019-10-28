/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_float_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 01:45:36 by acrooks           #+#    #+#             */
/*   Updated: 2019/06/13 01:45:41 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_symcat(char c, char *str)
{
	int		len;
	char	*res;

	len = ft_strlen(str);
	res = NULL;
	res = ft_strnew(len + 2);
	res[0] = c;
	res[len] = '\0';
	len = 1;
	while (str[len - 1])
	{
		res[len] = str[len - 1];
		len++;
	}
	if (str != NULL)
		free(str);
	return (res);
}

char	*ft_strjoin_plus(char *str1, char *str2)
{
	char *res;

	res = NULL;
	if (str1 == NULL && str2 == NULL)
		return (NULL);
	if (str1 == NULL && str2 != NULL)
		return (str2);
	if (str1 != NULL && str2 == NULL)
		return (str1);
	res = ft_strjoin(str1, str2);
	free(str1);
	str1 = NULL;
	free(str2);
	str2 = NULL;
	return (res);
}

char	*ft_strnmalloc(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*s1;
	unsigned int	j;

	i = 0;
	s1 = NULL;
	j = len + start;
	if (!s)
		return (NULL);
	if (start > j)
		return (NULL);
	if (!(s1 = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (start < j)
		s1[i++] = s[start++];
	s1[i] = '\0';
	free(s);
	return (s1);
}

char	*ft_inf_nan(t_printf *data, double len)
{
	char *res;

	res = NULL;
	if (len != len)
	{
		res = ft_strdup("nan");
		data->isnan = 1;
	}
	if (len == len + len / 0. && len < 0)
	{
		res = ft_strdup("-inf");
		data->isnan = 0;
		data->isinf = 1;
	}
	if (len == len + len / 0. && len > 0)
	{
		res = ft_strdup("inf");
		data->isnan = 0;
		data->isinf = 1;
	}
	return (res);
}
