/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 01:43:08 by acrooks           #+#    #+#             */
/*   Updated: 2019/06/13 01:43:14 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		final_process(const char *format_str, va_list ap, char **res)
{
	size_t	summ_len;
	size_t	len;
	char	*temp;

	len = 0;
	summ_len = 0;
	while (format_str[len])
	{
		if (format_str[len] == '%')
		{
			*res = ft_power_rangers(*res, format_str, summ_len, len);
			summ_len += len;
			format_str += len + 1;
			len = format_final(&format_str, &temp, ap);
			ft_cat_and_free(res, temp, summ_len, len);
			summ_len += len;
			len = 0;
		}
		else
			len++;
	}
	len = ft_strlen(format_str);
	*res = ft_power_rangers(*res, format_str, summ_len, len);
	summ_len += len;
	return (summ_len);
}

void		ft_cat_and_free(char **res, char *temp, size_t summ_len, size_t len)
{
	*res = ft_power_rangers(*res, temp, summ_len, len);
	free(temp);
}
