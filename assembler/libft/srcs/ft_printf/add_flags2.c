/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_flags2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 01:35:55 by acrooks           #+#    #+#             */
/*   Updated: 2019/06/13 03:53:38 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_sharp(t_printf *data, char *str)
{
	char	*res;
	char	tp;
	int		flag;

	flag = ((*str == '0' && str[1] == 0) || !*str) ? 0 : 1;
	tp = data->tp[0];
	res = NULL;
	if ((tp == 'o' && flag) || (tp == 'o' && ft_strcmp("", str) == 0))
		res = ft_strjoin("0", str);
	if (((tp == 'x' && flag)) || tp == 'p')
		res = ft_strjoin("0x", str);
	if (tp == 'X' && flag)
		res = ft_strjoin("0X", str);
	if (tp == 'f' && data->prec == -1 && data->isnan == 0 && data->isinf == 0)
		res = ft_strjoin(str, ".");
	if (res)
	{
		free(str);
		str = NULL;
	}
	return (res ? res : str);
}

void	ft_sub_precision(char *res, char *src, int len, int prec)
{
	if (len > 0)
	{
		if (*src == '-')
		{
			*res = '-';
			res++;
			src++;
		}
		ft_memset(res, '0', len);
		ft_strcat(res, src);
	}
	else
		ft_strncat(res, src, prec);
}

char	*ft_space(char *str)
{
	if (str[0] != '-' && str[0] != '+' && str[0] != '%')
		str = ft_strjoin_plus(ft_strdup(" "), str);
	return (str);
}

char	*ft_precision(t_printf *data, char *str)
{
	char		*buf;
	long int	i;
	int			prec;

	buf = NULL;
	if ((*(data->tp) == 's' && (!*str)))
		return (str);
	prec = (*(data->tp) == 's' && (data->prec >= (int)ft_strlen(str)) ? \
	ft_strlen(str) : data->prec);
	if (prec == 0)
		return (str);
	if ((prec == -1 && ft_strchr("xXuodi", *(data->tp))
		&& !ft_atoi(str)) && !data->pl)
		return (ft_pres_norm(data, str, prec));
	i = (data->tp[0] == 'o' && data->sh ? \
	prec - ft_strlen(str) - 1 : prec - ft_strlen(str));
	(ft_atoi(str) < 0) ? i++ : 0;
	if (i < 0 && data->tp[0] != 's')
		return (str);
	prec = (prec < 0 ? 0 : prec);
	buf = ft_strnew(prec);
	ft_sub_precision(buf, str, i, prec);
	free(str);
	return (buf);
}

char	*check_zero(t_printf *d, char *src)
{
	if (ft_strcmp("0", src) == 0 && ft_strchr("diouxX", d->tp[0]) \
	&& (d->prec || (!d->prec && d->min && d->sh && d->tp[0] == 'o')))
	{
		free(src);
		src = ft_strdup("");
		return (src);
	}
	return (src);
}
