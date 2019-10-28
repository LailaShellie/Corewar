/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 01:35:23 by acrooks           #+#    #+#             */
/*   Updated: 2019/06/13 03:53:44 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_width(t_printf *d, char *s1)
{
	char		*buf;
	long int	i;
	int			prec;

	prec = d->z_width;
	i = (ft_strcmp("", s1) == 0 && d->tp[0] == 'c' ? \
	prec - ft_strlen(s1) - 1 : prec - ft_strlen(s1));
	if (i < 0)
		return (s1);
	buf = ft_strnew(prec);
	if (d->min)
	{
		ft_strcpy(buf, s1);
		ft_memset(buf + ft_strlen(s1), ' ', i);
	}
	else
	{
		ft_memset(buf, ' ', i);
		ft_strcat(buf, s1);
	}
	free(s1);
	return (buf);
}

void	ft_sub_zero_size(t_printf *d, char *res, char *src, int len)
{
	char sp;

	sp = ' ';
	if (!d->min)
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
	{
		ft_strcpy(res, src);
		res += ft_strlen(src);
		ft_memset(res, sp, len);
	}
}

char	*ft_zero_size(t_printf *d, char *s1)
{
	char		*buf;
	long int	i;
	int			prec;

	if (s1[0] != '-')
		if ((d->pl && d->z) || (d->sp && d->z) \
		|| (d->min && d->sh && d->z))
			d->f_width -= 1;
	if (!d->z || (d->prec && d->tp[0] != 'f'))
		return (s1);
	prec = d->f_width;
	i = prec - ft_strlen(s1);
	if (i < 0)
		return (s1);
	buf = ft_strnew(prec);
	ft_sub_zero_size(d, buf, s1, i);
	free(s1);
	return (buf);
}

char	*ft_plus(int plus, char *s1)
{
	if (!plus)
		return (s1);
	if (s1[0] != '-')
		s1 = ft_strjoin_plus(ft_strdup("+"), s1);
	return (s1);
}

char	*add_flags(t_printf *d, char *src)
{
	if (src == NULL)
		return (NULL);
	src = check_zero(d, src);
	d->fl_zsh = (ft_strcmp("", src) == 0 ? 1 : 0);
	if (d->tp[0] != 'c' && d->isnan == 0 && d->isinf == 0)
		src = ft_precision(d, src);
	if (d->sh && d->z && d->tp[0] == 'o' && d->isnan == 0 \
	&& d->isinf == 0 && d->fl_zsh == 0)
		d->f_width -= 1;
	if (d->sh && d->z && ((d->tp[0] == 'x' \
	|| d->tp[0] == 'X') && d->fl_zsh == 0))
		d->f_width -= 2;
	if (!d->isnan && !d->isinf)
		src = ft_zero_size(d, src);
	if ((d->sh || (d->tp[0] == 'p')) && ((!(d->fl_zsh && d->sh)) \
	|| (d->tp[0] == 'o' && d->fl_zsh && d->sh)))
		src = ft_sharp(d, src);
	if (d->tp[0] != 'u' && d->isnan != 1)
		src = ft_plus(d->pl, src);
	if (d->sp && d->tp[0] != 'u' && d->tp[0] != 'c' && d->isnan != 1)
		if (src[0] != '-')
			src = ft_space(src);
	if (!d->z || d->prec || d->f_width)
		src = ft_width(d, src);
	return (src);
}
