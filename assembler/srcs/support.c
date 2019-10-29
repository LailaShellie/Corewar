/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blanna <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:17:20 by blanna            #+#    #+#             */
/*   Updated: 2019/10/28 12:17:21 by blanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void						error(t_ass *d_asm, char *str, t_tkn *tkn, int fl)
{
	ft_printf("----------------------------------------\n");
	ft_printf("/%s\\\n", str);
	if (fl == 1)
		ft_printf(">>>>| Location: ln - %d|<<<<\n", ST - 1);
	else if (fl == 2)
		ft_printf(">>>>| Location: ln - %d|<<<<\n", tkn->y - 1);
	ft_printf("----------------------------------------\n");
	free_all(d_asm);
	exit(EXIT_FAILURE);
}

void						skip_spaces(t_ass *d_asm, char *line)
{
	while (line[J] == ' ' || line[J] == '\t')
		J++;
}

void						skip_comm(t_ass *d_asm, char *line)
{
	if (line[J] == COMMENT_CHAR || line[J] == ALT_COMMENT_CHAR)
		while (line[J] && line[J] != '\n')
			J++;
}

long long					ft_atoi_size(const char *str, uint8_t size)
{
	int						neg;
	int						i;
	unsigned long long		num;
	int						h;

	sila(str, &i, &neg, &h);
	num = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		num *= 10;
		num += ((int)str[i] - 48);
		i++;
	}
	if ((num > INT64_MAX || nbrlen(num, neg)
		!= (ft_strlen(str) - h)) && num != 0)
		num = neg ? 0 : INT64_MAX;
	num = (neg == 1 ? -num : num);
	return (num);
}

int							check_reg(char *line, int len)
{
	int		i;

	i = 0;
	if ((len == 2 || len == 3) && line[i] == 'r')
	{
		i++;
		while (ft_isdigit(line[i]) && i < len)
			i++;
		return ((i == len && ft_atoi(&line[1]) > 0) ? 1 : 0);
	}
	return (0);
}
