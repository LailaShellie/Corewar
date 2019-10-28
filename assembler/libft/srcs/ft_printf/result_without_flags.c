/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_without_flags.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrooks <acrooks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 01:47:45 by acrooks           #+#    #+#             */
/*   Updated: 2019/06/13 01:47:50 by acrooks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*result_without_flags(t_printf *data, va_list ap)
{
	if ((ft_strcmp(data->tp, "d") == 0) || (ft_strcmp(data->tp, "i") == 0))
		return (ft_type_d_i(ap, data->s_tp));
	else if ((ft_strcmp(data->tp, "o") == 0))
		return (ft_type_o(ap, data->s_tp));
	else if ((ft_strcmp(data->tp, "u") == 0))
		return (ft_type_u(ap, data->s_tp));
	else if ((ft_strcmp(data->tp, "x") == 0))
		return (ft_type_x(ap, data->s_tp));
	else if ((ft_strcmp(data->tp, "X") == 0))
		return (ft_type_upper_x(ap, data->s_tp));
	else if ((ft_strcmp(data->tp, "c") == 0))
		return (ft_type_c(ap, data->s_tp));
	else if ((ft_strcmp(data->tp, "s") == 0) &&
	!(check_typelist(data->s_tp[0], SIZE_TYPE)))
		return (ft_type_s(ap));
	else if ((ft_strcmp(data->tp, "p") == 0))
		return (ft_type_p(ap));
	else if ((ft_strcmp(data->tp, "f") == 0))
		return (ft_float_process(ft_type_f(ap, data->s_tp), data));
	else if ((ft_strcmp(data->tp, "%") == 0))
		return (ft_strdup("%"));
	return (ft_strdup(""));
}
