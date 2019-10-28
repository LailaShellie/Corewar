/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_final.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 01:43:43 by acrooks           #+#    #+#             */
/*   Updated: 2019/06/13 05:00:38 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			format_final(const char **format_str, char **res, va_list ap)
{
	int			i;
	size_t		size;
	char		*modstr;
	t_printf	*data;

	i = 0;
	modstr = NULL;
	data = (t_printf*)malloc(sizeof(t_printf));
	i = ft_check_type(*format_str, &modstr);
	ft_initial_struct(data);
	modstr = (i == 0 ? check_undefined_type(modstr) : modstr);
	*format_str = (i == 0 ? *format_str + ft_strlen(modstr) : *format_str + i);
	ft_parsing(modstr, data, ap);
	if (!(ft_strchr(TYPELIST, data->tp[0])))
		return (0);
	*res = result_without_flags(data, ap);
	*res = add_flags(data, *res);
	size = ft_strlen(*res);
	free(data->tp);
	free(data->s_tp);
	free(data);
	free(modstr);
	return (size);
}

char			*check_undefined_type(char *s)
{
	int			i;
	char		*dst;

	i = 0;
	while (s[i] == '-' || s[i] == '+' || s[i] == ' ' \
	|| s[i] == '0' || s[i] == '#')
		i++;
	while (ft_isdigit(s[i]))
		i++;
	if (s[i] == '.')
		i++;
	while (ft_isdigit(s[i]))
		i++;
	while (s[i] == 'l' || s[i] == 'h')
		i++;
	if (!(dst = ft_strnew(i)))
		return (NULL);
	dst = ft_strncpy(dst, s, i);
	free(s);
	return (dst);
}
