/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_float_core.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 01:53:55 by acrooks           #+#    #+#             */
/*   Updated: 2019/06/13 03:29:17 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_res_prec(double n, t_float f_d)
{
	if (f_d.neg_fl == 1)
		return (ft_symcat('-', ft_itoa_base((n + 0.5), 10)));
	return (ft_itoa_base((n + 0.5), 10));
}

char	*ft_float_process(double n, t_printf *form)
{
	t_float			f_d;
	unsigned long	*p;

	ft_bzero(&f_d, sizeof(f_d));
	f_d.drb = ft_inf_nan(form, n);
	if (f_d.drb != NULL)
		return (f_d.drb);
	p = (unsigned long *)&n;
	f_d.neg_fl = *p >> 63;
	n < 0 ? n = -n : 0;
	f_d.whole = (unsigned long long)n;
	if (form->prec == -1)
		return (ft_res_prec(n, f_d));
	n = n - f_d.whole;
	form->prec = (form->prec <= 0 ? 6 : form->prec);
	f_d.drb = ft_strnew(form->prec + 2);
	while (f_d.count < form->prec + 1)
	{
		n = n * 10;
		f_d.drb[f_d.count++] = (char)n + '0';
		n = n - (char)n;
	}
	return (ft_sborka(f_d.drb, f_d.whole, f_d.neg_fl, n));
}

char	*ft_sborka(char *drb, unsigned long long whole, int flag, double n)
{
	int		len;
	char	*str_float;
	char	*rounding_num;

	str_float = NULL;
	rounding_num = NULL;
	len = *drb == 0 ? ft_strlen(drb) : ft_strlen(drb) - 1;
	if (len == 0)
		return (ft_output_zero_prec(drb, whole, flag, n));
	rounding_num = ft_rounding(drb, len, 1, n);
	if (rounding_num[0] > 9 + '0')
		return (round_and_output(rounding_num, whole, flag));
	str_float = ft_itoa_base(whole, 10);
	if (flag == 1)
		str_float = ft_symcat('-', str_float);
	rounding_num = ft_symcat('.', rounding_num);
	str_float = ft_strjoin_plus(str_float, rounding_num);
	return (ft_strnmalloc(str_float, 0, ft_strlen(str_float) - 1));
}
