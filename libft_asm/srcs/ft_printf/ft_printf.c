/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 01:45:16 by acrooks           #+#    #+#             */
/*   Updated: 2019/06/13 01:45:20 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format_str, ...)
{
	va_list		ap;
	char		*res;
	size_t		size;

	res = NULL;
	va_start(ap, format_str);
	size = final_process(format_str, ap, &res);
	write(1, res, size);
	free(res);
	va_end(ap);
	return (size);
}
