/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 01:44:16 by acrooks           #+#    #+#             */
/*   Updated: 2019/06/13 05:04:47 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_initial_struct(t_printf *data)
{
	data->pl = 0;
	data->min = 0;
	data->z = 0;
	data->sh = 0;
	data->sp = 0;
	data->f_width = 0;
	data->z_width = 0;
	data->prec = 0;
	data->tp = ft_strnew(1);
	data->s_tp = ft_strnew(2);
	data->isnan = 0;
	data->isinf = 0;
	data->fl_zsh = 0;
}

int			ft_precision_struct(t_printf *data, char *mods)
{
	int i;

	i = 0;
	if (mods[i] != '.')
		return (0);
	i++;
	data->prec = ft_atoi(mods + i);
	if (data->prec == 0)
		data->prec = -1;
	while (ft_isdigit(mods[i]))
		i++;
	return (i);
}

void		ft_parsing_flags(t_printf *data, char mod)
{
	if (mod == '+')
		data->pl = 1;
	else if (mod == '-')
		data->min = 1;
	else if (mod == '0')
		data->z = 1;
	else if (mod == '#')
		data->sh = 1;
	else if (mod == ' ')
		data->sp = 1;
}

int			ft_width_struct(char *mods, t_printf *data, va_list ap)
{
	int i;

	i = 0;
	if (mods[i] == '*')
	{
		data->f_width = va_arg(ap, int);
		i++;
	}
	else if (ft_isdigit(mods[i]) && mods[i] != '0')
	{
		data->f_width = ft_atoi(mods);
		data->z_width = data->f_width;
		while (ft_isdigit(mods[i]))
			i++;
		return (i);
	}
	return (0);
}

t_printf	*ft_parsing(char *mods, t_printf *data, va_list ap)
{
	int i;

	i = 0;
	while (*mods)
	{
		ft_parsing_flags(data, *mods);
		mods += ft_precision_struct(data, mods);
		if (ft_width_struct(mods, data, ap))
		{
			mods += ft_width_struct(mods, data, ap);
			continue;
		}
		while (*mods && ft_strchr(SIZE_TYPE, *mods))
		{
			(data->s_tp)[i++] = *mods;
			mods++;
		}
		if (ft_strchr(TYPELIST, *mods))
		{
			(data->tp)[0] = *mods;
			return (data);
		}
		mods++;
	}
	return (NULL);
}
