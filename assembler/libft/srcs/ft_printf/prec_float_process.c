/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_float_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 01:46:13 by acrooks           #+#    #+#             */
/*   Updated: 2019/06/13 01:47:38 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_rounding(char *str, int len, int flag, double begin_n)
{
	while (len && str[len] && str[len - 1] && flag == 1)
	{
		flag = 0;
		if ((str[len - 1] + 1) % 2 == 0)
		{
			if (begin_n + str[len] - '5' >= 0)
			{
				str[len] = '0';
				str[len - 1] = str[len - 1] + 1;
			}
		}
		else
		{
			if (begin_n + str[len] - '5' > 0)
			{
				str[len] = '0';
				str[len - 1] = str[len - 1] + 1;
			}
		}
		if (str[len - 1] > 9 + '0')
			flag = 1;
		len--;
	}
	return (ft_strnmalloc(str, 0, ft_strlen(str)));
}

char	*round_and_output(char *rounding_num, unsigned long long int whole,
int flag)
{
	char *res;

	res = NULL;
	rounding_num[0] = '0';
	whole = whole + 1;
	res = ft_itoa_base(whole, 10);
	if (flag == 1)
		res = ft_symcat('-', res);
	rounding_num = ft_symcat('.', rounding_num);
	res = ft_strjoin_plus(res, rounding_num);
	res = ft_strnmalloc(res, 0, ft_strlen(res) - 1);
	return (res);
}

char	*ft_output_zero_prec(char *drob_part, unsigned long long int whole,
int flag, double begin_n)
{
	char *res;

	res = NULL;
	if ((whole + 1) % 2 == 0)
	{
		if (begin_n + drob_part[0] - '0' >= 5)
			whole++;
	}
	else
	{
		if (begin_n + drob_part[0] - '0' > 5)
			whole++;
	}
	res = ft_itoa_base(whole, 10);
	if (flag == 1)
		res = ft_symcat('-', res);
	return (res);
}
