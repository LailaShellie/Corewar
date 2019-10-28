/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_dioux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 01:50:29 by acrooks           #+#    #+#             */
/*   Updated: 2019/06/13 01:52:49 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_type_d_i(va_list ap, char *modi)
{
	long long int	arg;
	char			*res;

	arg = 0;
	if (ft_strcmp(modi, "h") == 0)
		arg = (short)va_arg(ap, int);
	else if (ft_strcmp(modi, "hh") == 0)
		arg = (signed char)va_arg(ap, int);
	else if (ft_strcmp(modi, "l") == 0)
		arg = va_arg(ap, long);
	else if (ft_strcmp(modi, "ll") == 0)
		arg = va_arg(ap, long long);
	else if (ft_strcmp(modi, "") == 0)
		arg = va_arg(ap, int);
	res = ft_itoa(arg);
	return (res);
}

char	*ft_type_o(va_list ap, char *modi)
{
	unsigned long long int	arg;
	char					*res;

	arg = 0;
	if (ft_strcmp(modi, "h") == 0)
		arg = (unsigned short)va_arg(ap, unsigned int);
	else if (ft_strcmp(modi, "hh") == 0)
		arg = (unsigned char)va_arg(ap, unsigned int);
	else if (ft_strcmp(modi, "l") == 0)
		arg = va_arg(ap, unsigned long);
	else if (ft_strcmp(modi, "ll") == 0)
		arg = va_arg(ap, unsigned long long);
	else if (ft_strcmp(modi, "") == 0)
		arg = va_arg(ap, unsigned int);
	res = ft_itoa_base(arg, 8);
	return (res);
}

char	*ft_type_u(va_list ap, char *modi)
{
	unsigned long long int	arg;
	char					*res;

	arg = 0;
	if (ft_strcmp(modi, "h") == 0)
		arg = (unsigned short)va_arg(ap, unsigned int);
	else if (ft_strcmp(modi, "hh") == 0)
		arg = (unsigned char)va_arg(ap, unsigned int);
	else if (ft_strcmp(modi, "l") == 0)
		arg = va_arg(ap, unsigned long);
	else if (ft_strcmp(modi, "ll") == 0)
		arg = va_arg(ap, unsigned long long);
	else if (ft_strcmp(modi, "") == 0)
		arg = va_arg(ap, unsigned int);
	res = ft_itoa_base(arg, 10);
	return (res);
}

char	*ft_type_x(va_list ap, char *modi)
{
	unsigned long long int	arg;
	char					*res;

	arg = 0;
	if (ft_strcmp(modi, "h") == 0)
		arg = (unsigned short)va_arg(ap, unsigned int);
	else if (ft_strcmp(modi, "hh") == 0)
		arg = (unsigned char)va_arg(ap, unsigned int);
	else if (ft_strcmp(modi, "l") == 0)
		arg = va_arg(ap, unsigned long);
	else if (ft_strcmp(modi, "ll") == 0)
		arg = va_arg(ap, unsigned long long);
	else if (ft_strcmp(modi, "") == 0)
		arg = va_arg(ap, unsigned int);
	res = ft_itoa_base(arg, 16);
	return (res);
}

char	*ft_type_upper_x(va_list ap, char *modi)
{
	return (ft_upper_str(ft_type_x(ap, modi)));
}
